// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Item.h"
#include "DrawDebugHelpers.h" 


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
/////////////////////////////////////////////////MESSEGES////////////////////////////////////////////////////////
	//Використовується для виводу повідомлення в лог консолі Unreal Engine. Це допомагає в налагодженні коду.
	UE_LOG(LogTemp, Warning, TEXT("Begin Play called!"));
	
	//GEngine - глобальний об'єкт, який надає доступ до движка Unreal Engine.
	if (GEngine)
	{
		//виводиться повідомлення на екран 
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item on screen Message"));
	}
/////////////////////////////////////////////////MESSEGES////////////////////////////////////////////////////////
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    /////////////////////////////////////////////////MESSEGES////////////////////////////////////////////////////////
	/*
	message about delta time to OUTPUT LOG
	%f -  convector float to string the next element  
	*/
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		/*
		одже для вписання стрінги на наш екран
		GetName() -  вшита функція, можа перечитати хедер файл нажавши Ф12 при наведенні на ФСтрінг
		Нам потрібна конвертація для стрінги = %s
		вводяди саму стрінгу вкінці нам потрібно додати зірочку = А ця зірочка надає нам рядок у стилі C.
		ми маємо вставляти його саме як С стиль стрінгу
		прописано в документації по анріалу
		*/
		FString Name = GetName();
		FString Message = FString::Printf(TEXT("Item name: %s"), *Name);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

		UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %s"), *Name);


		/*
		FString Message = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

		doing the same as previous
		попередньо створюємо сам мечедж з конвертацією
		гуд практіс FString::Printf(TEXT("DeltaTime: %f"), DeltaTime в прінтФ використовувати максрос ТЕКСТ
		*/
		/////////////////////////////////////////////////MESSEGES////////////////////////////////////////////////////////
	}
}

