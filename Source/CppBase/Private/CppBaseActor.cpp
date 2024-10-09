// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();	
	ShowActorInformation();
	InitialLocation = GetActorLocation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowInformation() {

	UE_LOG(LogTemp, Display, TEXT("PlayerName %s"), *PlayerName);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, PlayerName, true, FVector2D(2.0f, 2.0f));

	UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
	UE_LOG(LogTemp, Warning, TEXT("CppBase класс ошибся"));
	UE_LOG(LogTemp, Error, TEXT("CppBase eror"));

	UE_LOG(LogTemp, Display, TEXT("Enemy num %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);

}

void ACppBaseActor::ShowActorInformation() {
	FString ObjName  = GetName();
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *ObjName);
	UE_LOG(LogTemp, Display, TEXT("Enemy num %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

void ACppBaseActor::SinMovement() {
	float x = InitialLocation.X;
	float y = InitialLocation.Y;
	float z = Amplitude * sin(Frequency * GetWorld()->GetTimeSeconds()) + InitialLocation.Z;
	FVector CurrentLocation = FVector(x, y, z);
	SetActorLocation(CurrentLocation);
}