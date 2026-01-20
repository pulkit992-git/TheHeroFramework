// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheHeroFramework : ModuleRules
{
	public TheHeroFramework(ReadOnlyTargetRules Target) : base(Target)
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
			"TheHeroFramework",
			"TheHeroFramework/Variant_Platforming",
			"TheHeroFramework/Variant_Platforming/Animation",
			"TheHeroFramework/Variant_Combat",
			"TheHeroFramework/Variant_Combat/AI",
			"TheHeroFramework/Variant_Combat/Animation",
			"TheHeroFramework/Variant_Combat/Gameplay",
			"TheHeroFramework/Variant_Combat/Interfaces",
			"TheHeroFramework/Variant_Combat/UI",
			"TheHeroFramework/Variant_SideScrolling",
			"TheHeroFramework/Variant_SideScrolling/AI",
			"TheHeroFramework/Variant_SideScrolling/Gameplay",
			"TheHeroFramework/Variant_SideScrolling/Interfaces",
			"TheHeroFramework/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
