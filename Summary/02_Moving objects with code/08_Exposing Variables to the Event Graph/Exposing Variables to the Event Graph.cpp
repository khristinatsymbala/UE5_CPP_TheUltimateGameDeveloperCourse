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
//////////////////////READ ONLY//////////////////////////////////////////
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sine Parameters")
		float Amplitude = 0.25f;
///////////////////// READ AND WRITE////////////////////////////////////
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
    float Amplitude = 0.25f;
private:
	//////For just visible into a BP_editor(not instance)
	UPROPERTY(VisibleAnywhere)
	float RunningTime;
////////////////////////////For change private variable in BP//////////
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    float RunningTime;

	

	UPROPERTY(EditInstanceOnly)
	float TimeConstant = 5.f;

};
