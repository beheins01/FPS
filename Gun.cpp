/** @file MyShooterCharacter.cpp

 *  @brief This is the main file of the code that sets up the players character in the game

 * This file is where I set up the gun with animations and also set up the gun mesh
 * In this file I set up the line tracing for the bullets so that they can register if they hit something
 * In this file I attach the muzzle flash and sound when the gun is fired
 * In this file I set up the location on the gun where the muzzle flash and sound come from
 * In this file I set up the gun spawing with the AI's and the Main Character
 * In this file I set up the location where the bullet hits
 * In this file I attached a sound when the bullet hits a character or surface in the game

 *  @Author: Ben Heins

 *  @bug: No known bugs

 */
#include "Gun.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject < USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

/** @brief This function gets the gun trace so that it can track the bullets coming out of the gun

 *

 *  This function applies the gun animations and sounds to the gun so that they can be implemented
 *  in the code later


 */
void AGun::PullTrigger()
{
	//This is where I am able to attach the animations for the muzzle flash animation 
	//This is where I am able to attach the sound for the muzzle flash
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));

	//This takes the line trace of the gun and can register if it hits an object or reaches max range
	FHitResult Hit;

	//Determines the direction the line trace is fired at
	FVector ShotDirection;
	bool bSuccess = GunTrace(Hit, ShotDirection);
	if (bSuccess)
	{

		//This sets the location every time that we fire the gun for the effects and sounds
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
		
		AActor* HitActor = Hit.GetActor();
		if (HitActor != nullptr)
		{
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
			AController* OwnerController = GetOwnerController();
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}

}

/** @brief This function controls what happens when the gamne begins for the gun

  */
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

/** @brief This function sets up the tick

 *

 *  this function allows the AGun class to change every instance that
 *  the game is being run so that it changes every instant and adapts

 *

 *  @param DeltaSeconds is an integer variable that contains the change in time

 */
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/** @brief This sets up the gun line traces

 *

 *  This function allows the game to take the line traces from the gun and see
 *  when it collides with a pawn or a surface within the game while it is also
 *  maintaining its set variables

 *

 *  @param Hit this FHitResult detects if the bullent has impacted a surface or pawn
 *  @param ShotDirection This vector determines which direction the gun shot was directed

 *  @return All the variables like location, end, collision

 */
bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr) return false;			//Sets up just in call we get a nullptr because Unreal Engine will crash if it gets a null

	FVector Location;		//Gotten from an already created file
	FRotator Rotation;		//Gotten from an already created file
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	ShotDirection = -Rotation.Vector();

	FVector End = Location + Rotation.Vector() * MaxRange;			//Calctulating how to get to  bullet endpoint

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

/** @brief Sets the gun to a pawn.

 */
AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return nullptr;				//Sets up just in call we get a nullptr because Unreal Engine will crash if it gets a null
	return OwnerPawn->GetController();

}

