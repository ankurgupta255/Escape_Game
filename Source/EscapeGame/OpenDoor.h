// Copyright Ankur Gupta Inc

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnCloseRequest;

private:
	/*UPROPERTY(EditAnywhere)
	float OpenAngle = 120.f;*/

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	/*UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;*/

	//float LastDoorOpenTime;

	UPROPERTY(EditAnywhere)
		float TriggerMass = 50.f;

	//AActor* ActorThatOpens;
	AActor* Owner = nullptr;
	float GetTotalMassOfActorsOnPlate();
};
