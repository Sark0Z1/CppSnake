// CppSnake. Copyright SarkOZ1. All Right Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CppSnakeEditorTarget : TargetRules
{
	public CppSnakeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "CppSnake" } );
	}
}
