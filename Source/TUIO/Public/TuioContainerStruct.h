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

	/**
	 * Coordinates of the touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_tuio_point.html#a547710f33dd3786eaa8ca326b34911c0
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	FVector2D Position;

	/**
	 * Velocity of the touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_tuio_container.html#ad71a4dba72e5c46fa8b8f7fc0f961705
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	FVector2D Speed;

	/**
	 * TUIO session ID (device) for this touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_tuio_container.html#a43a9b95e3108a178e16c8d86a9816f8a
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SessionID;

	/**
	 * TUIO source ID (finger) for this touch event.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_tuio_container.html#a667ab7e367870bd5feabe91289309fbe
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	float SourceID;

	/**
	 * Timestamp of the touch event, in seconds.
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_tuio_point.html#ac86687cf27772d0fd602c2044b6c8cdd
	 * @see http://www.tuio.org/api/cpp/class_t_u_i_o_1_1_tuio_time.html#ac403aea1a8928e714f9f6388f488fa33
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TuioContainer")
	double Timestamp;
};
