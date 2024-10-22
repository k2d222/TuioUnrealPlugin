// Copyright Epic Games, Inc. All Rights Reserved.

#include "TUIO.h"
#include "Misc/MessageDialog.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"

#include "TUIO/TuioListener.h"
#include "TUIO/TuioClient.h"
#include "TUIO/UdpReceiver.h"
#include "TUIO/TcpReceiver.h"
#include <string>

#define LOCTEXT_NAMESPACE "FTUIOModule"

static std::string _address("localhost");
static bool _udp = true;
static int _port = 3333;


void FTUIOModule::StartupModule()
{

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FTUIOModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTUIOModule, TUIO)
