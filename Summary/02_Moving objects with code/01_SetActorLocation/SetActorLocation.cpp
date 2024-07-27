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

	//Отримує вказівник на поточний об'єкт світу, в якому існує актор.
	UWorld* World = GetWorld();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	SetActorLocation(FVector(0.f, 0.f, 50.f));
    //Для коректної роботи вони мають знаходитись нижче
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DRAW_SPHERE(Location);
	DRAW_VECTOR(Location, Location + Forward * 100.f);

	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

