// Fill out your copyright notice in the Description page of Project Settings.


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

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime; 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	HARD CODE
	float DeltaZ = 0.25f(amplitude) * FMath::Sin(RunningTime * 5.f(scaling));
	*/

	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant); 

	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	DRAW_SPHERE_SINGLE_FRAME(GetActorLocation())
	DRAW_VECTOR_SINGLE_FRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100)
}

