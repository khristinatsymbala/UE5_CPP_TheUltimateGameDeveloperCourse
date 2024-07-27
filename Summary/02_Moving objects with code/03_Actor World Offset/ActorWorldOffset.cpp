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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Movement Rate in units of cm/s - сантиметрів на секунду
	float MovementRate = 50.f;

	//Movement Rate * Delta Time (cv/s) * (s/frame) = (cm/frame)
	// Отримання плавного руху на певну кількість поінтів не залежно від FPS
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	DRAW_SPHERE_SINGLE_FRAME(GetActorLocation())
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

