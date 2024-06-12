// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ejemplo1Naves : ModuleRules
{
	public Ejemplo1Naves(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
