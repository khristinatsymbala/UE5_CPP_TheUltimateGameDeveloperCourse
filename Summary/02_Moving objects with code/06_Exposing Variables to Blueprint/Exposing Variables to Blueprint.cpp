#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class BP_CPP_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	// Called every frame
		virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float RunningTime;

////////////////////////////////////////////////////////////////////////
	//UPROPERTY(EditDefaultsOnly) //for root bp editor
	UPROPERTY(EditAnywhere)
	float Amplitude = 0.25f;

	UPROPERTY(EditInstanceOnly)
	float TimeConstant = 5.f;
////////////////////////////////////////////////////////////////////////
};