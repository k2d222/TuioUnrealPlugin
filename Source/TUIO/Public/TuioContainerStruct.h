// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TUIO/TuioContainer.h"

#include "Math/Vector2D.h"
#include "CoreMinimal.h"

#include "TuioContainerStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FTuioContainerStruct
{
	GENERATED_BODY()

	FTuioContainerStruct() = default;
	FTuioContainerStruct(const TUIO::TuioContainer& source);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	FVector2D Position;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	FVector2D Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SessionID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SourceID;
};
