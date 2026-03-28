// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PGTest : ModuleRules
{
	public PGTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PGTest",
			"PGTest/Variant_Platforming",
			"PGTest/Variant_Platforming/Animation",
			"PGTest/Variant_Combat",
			"PGTest/Variant_Combat/AI",
			"PGTest/Variant_Combat/Animation",
			"PGTest/Variant_Combat/Gameplay",
			"PGTest/Variant_Combat/Interfaces",
			"PGTest/Variant_Combat/UI",
			"PGTest/Variant_SideScrolling",
			"PGTest/Variant_SideScrolling/AI",
			"PGTest/Variant_SideScrolling/Gameplay",
			"PGTest/Variant_SideScrolling/Interfaces",
			"PGTest/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
