// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MojProjekt46542 : ModuleRules
{
	public MojProjekt46542(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
