//How to export func(C++) to BP
/*
How to choice where to put a func (public<protected,private)
- Are we going to plan on calling this function from outside the class?
- do you ever see yourself potentially calling this function in a child class derived from a item?
        For example, we may specialize item by deriving a new class called say, weapon.
        And if you think weapon might need to be calling this function, well, you can make it protected.

And if you know for sure that this class will be the only class that needs to call this function, you can make it private.
I tend to put most functions in the protected section if I'm not sure, but I typically move them out of one section and into another if the need arises.
*/ 
///////////////////////////////header file/////////////////////////////////////////////////////////

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

	//UPROPERTY(EditDefaultsOnly) //for root bp editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;
		
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.f;
////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE
    UFUNCTION(BlueprintCallable) - general function
	float TransformedSin(float Value);

    UFUNCTION(BlueprintPure) - pure function
    float TransformedSin();

    UFUNCTION(BlueprintPure)
    float TransformCosin();

////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE
private:
	//////For just visible into a BP_editor(not instance)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;
};

////////////////////////////////cpp file////////////////////////////////////////////
#include "Item/Item.h"
#include "DebugMacros.h"



// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	//Викликає початковий метод BeginPlay з базового класу AActor. Це гарантує, що будь-яка логіка, визначена в базовому класі, буде виконана.
	Super::BeginPlay();

}
////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE
float AItem::TransformedSin(float Value) - general function
{
	//Value = RunningTime;
	return Amplitude * FMath::Sin(Value * TimeConstant);
}

float AItem::TransformedSin() - general function
{
	//Value = RunningTime;
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformCosin()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE////////HERE///////HERE
// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime; 

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant); 

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	
	DRAW_SPHERE_SINGLE_FRAME(GetActorLocation())
	DRAW_VECTOR_SINGLE_FRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100)
}
