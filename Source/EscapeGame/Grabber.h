// Copyright Ankur Gupta Inc

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetupInputComponent();

	void FindPhysicsHandleComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FHitResult GetFirstPhysicsBodyInReach();

private:
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	void Grab();
	void UnGrab();
};
