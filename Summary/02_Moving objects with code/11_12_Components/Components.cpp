//Adding functionatity to Actors
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

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformCosin();

	template<typename T>
	T Average(T first, T second);

private:
	//////For just visible into a BP_editor(not instance)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	UPROPERTY(VisibleAnywhere) // mark to unreal engine - will know - still use and not garbage data
	UStaticMeshComponent* ItemMesh; 

};

template<typename T>
inline T AItem::Average(T first, T second)
{
	return (first + second)/2;
}

////////////////////////////////cpp file////////////////////////////////////////////



#include "Item/Item.h"
#include "DebugMacros.h"



// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent")); return a pointer so we need to store a value
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh; // reassign new root component as before
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	//Викликає початковий метод BeginPlay з базового класу AActor. Це гарантує, що будь-яка логіка, визначена в базовому класі, буде виконана.
	Super::BeginPlay();


	int32 AverageInt = Average<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Average of 1 and 3 :%d"), AverageInt);
}

float AItem::TransformedSin()
{
	//Value = RunningTime;
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformCosin()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}



// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime; 

}
