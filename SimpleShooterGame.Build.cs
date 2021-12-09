// Copyright Epic Games, Inc. All Rights Reserved.
//These are all defaults that are created when you create the game
//These are untampered 
using UnrealBuildTool;

public class SimpleShooterGame : ModuleRules
{
	public SimpleShooterGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GameplayTasks", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

	}
}
