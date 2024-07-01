// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TUIO/TuioListener.h"
#include "TUIO/TuioClient.h"
#include "TUIO/UdpReceiver.h"
#include "TUIO/TcpReceiver.h"

#include <memory>
#include <functional>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TUIOReceiverComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTuioEvent, FTuioContainer, Data);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TUIO_API UTUIOReceiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	enum class EEventType {
		AddObject,
		UpdateObject,
		RemoveObject,
		AddCursor,
		UpdateCursor,
		RemoveCursor,
		AddBlob,
		UpdateBlob,
		RemoveBlob,
	};

	// Sets default values for this component's properties
	UTUIOReceiverComponent();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnAddObject;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnUpdateObject;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnRemoveObject;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnAddCursor;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnUpdateCursor;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnRemoveCursor;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnAddBlob;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnUpdateBlob;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FTuioEvent OnRemoveBlob;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type reason) override;

private:
	void DispatchMainThread(EEventType type, TUIO::TuioContainer* evt);

	class TuioDump : public TUIO::TuioListener {

	public:
		using Dispatcher = std::function<void(EEventType, TUIO::TuioContainer*)>;
		void setDispatcher(Dispatcher dispatcher);
		void addTuioObject(TUIO::TuioObject* tobj);
		void updateTuioObject(TUIO::TuioObject* tobj);
		void removeTuioObject(TUIO::TuioObject* tobj);

		void addTuioCursor(TUIO::TuioCursor* tcur);
		void updateTuioCursor(TUIO::TuioCursor* tcur);
		void removeTuioCursor(TUIO::TuioCursor* tcur);

		void addTuioBlob(TUIO::TuioBlob* tblb);
		void updateTuioBlob(TUIO::TuioBlob* tblb);
		void removeTuioBlob(TUIO::TuioBlob* tblb);

		void refresh(TUIO::TuioTime frameTime);

		Dispatcher dispatch;
	};

	TUIO::TuioClient* client;
	TuioDump listener;
};
