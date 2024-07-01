// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TUIO/TuioContainer.h"
#include "CoreMinimal.h"
#include "TuioContainerStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FTuioContainer
{
	GENERATED_BODY()

	FTuioContainer(const TUIO::TuioContainer& source);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float X;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float Y;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SessionID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SourceID;
};
