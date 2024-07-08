// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class TUIO11 : ModuleRules
{
	public TUIO11(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		PublicSystemIncludePaths.Add("$(ModuleDir)/TUIO11_CPP");
        PublicSystemIncludePaths.Add("$(ModuleDir)/TUIO11_CPP/oscpack");

        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "binaries/windows_x64/libTUIO.lib"));
            RuntimeDependencies.Add("$(BinaryOutputDir)/libTUIO.dll", Path.Combine(ModuleDirectory, "binaries/windows_x64/libTUIO.dll"));
        }
		else
		{
			throw new System.Exception("not implemented for linux and macos yet. Should be quite easy to implement, see TUIO11.Build.cs file.");
		}
	}
}
