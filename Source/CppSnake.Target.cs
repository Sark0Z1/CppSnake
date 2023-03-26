// CppSnake. Copyright SarkOZ1. All Right Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CppSnakeTarget : TargetRules
{
	public CppSnakeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "CppSnake" } );
	}
}
