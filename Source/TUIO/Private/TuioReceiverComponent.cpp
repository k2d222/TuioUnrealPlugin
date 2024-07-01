// Fill out your copyright notice in the Description page of Project Settings.


#include "TUIOReceiverComponent.h"
#include "TuioContainer.h"

#include <sstream>

using namespace TUIO;

// Sets default values for this component's properties
UTUIOReceiverComponent::UTUIOReceiverComponent()
	: client(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you 't need them.
	PrimaryComponentTick.bCanEverTick = true;

	listener.setDispatcher(std::bind(&UTUIOReceiverComponent::DispatchMainThread, this));
}

// Called when the game starts
void UTUIOReceiverComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("begin play"));

	if (client) {
		delete client;
	}

	client = new TuioClient();
	client->addTuioListener(&listener);
	client->connect();
}

void UTUIOReceiverComponent::EndPlay(EEndPlayReason::Type reason)
{
	UE_LOG(LogTemp, Warning, TEXT("end play"));

	client->disconnect();
	delete client;
	client = nullptr;

	Super::EndPlay(reason);
}

void UTUIOReceiverComponent::DispatchMainThread(EEventType type, TUIO::TuioContainer* evt)
{
	FTuioContainer cont(*evt);
	AsyncTask(ENamedThreads::GameThread, [type, cont, this]()
	{
			switch (type)
			{
			case UTUIOReceiverComponent::EEventType::AddObject:
				OnAddObject.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::UpdateObject:
				OnUpdateObject.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::RemoveObject:
				OnRemoveObject.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::AddCursor:
				OnAddCursor.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::UpdateCursor:
				OnUpdateCursor.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::RemoveCursor:
				OnRemoveCursor.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::AddBlob:
				OnAddBlob.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::UpdateBlob:
				OnUpdateBlob.Broadcast(cont);
				break;
			case UTUIOReceiverComponent::EEventType::RemoveBlob:
				OnRemoveBlob.Broadcast(cont);
				break;
			default:
				break;
			}
	});

}


void UTUIOReceiverComponent::TuioDump::setDispatcher(Dispatcher dispatcher)
{
	dispatch = dispatcher;
}


void UTUIOReceiverComponent::TuioDump::addTuioObject(TuioObject* tobj) {
	dispatch(EEventType::AddObject, tobj);
}

void UTUIOReceiverComponent::TuioDump::updateTuioObject(TuioObject* tobj) {
	dispatch(EEventType::UpdateObject, tobj);
}

void UTUIOReceiverComponent::TuioDump::removeTuioObject(TuioObject* tobj) {
	dispatch(EEventType::RemoveObject, tobj);
}

void UTUIOReceiverComponent::TuioDump::addTuioCursor(TuioCursor* tcur) {
	dispatch(EEventType::AddCursor, tcur);
}

void UTUIOReceiverComponent::TuioDump::updateTuioCursor(TuioCursor* tcur) {
	dispatch(EEventType::UpdateCursor, tcur);
}

void UTUIOReceiverComponent::TuioDump::removeTuioCursor(TuioCursor* tcur) {
	dispatch(EEventType::RemoveCursor, tcur);
}

void UTUIOReceiverComponent::TuioDump::addTuioBlob(TuioBlob* tblb) {
	dispatch(EEventType::AddBlob, tblb);
}

void UTUIOReceiverComponent::TuioDump::updateTuioBlob(TuioBlob* tblb) {
	dispatch(EEventType::UpdateBlob, tblb);
}

void UTUIOReceiverComponent::TuioDump::removeTuioBlob(TuioBlob* tblb) {
	dispatch(EEventType::RemoveBlob, tblb);
}

void UTUIOReceiverComponent::TuioDump::refresh(TuioTime frameTime) { }