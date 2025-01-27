// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTerrestre.h"

// Called when the game starts or when spawned
void ANaveEnemigaTerrestre::BeginPlay()
{
	Super::BeginPlay();

}

ANaveEnemigaTerrestre::ANaveEnemigaTerrestre()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

// Called every frame
void ANaveEnemigaTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaTerrestre::Mover(float DeltaTime)
{
	// Obtiene la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;
	float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;

	// Crea un nuevo vector de posici�n con las coordenadas aleatorias y la misma Z que la posici�n actual
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	// Establece la nueva posici�n del actor
	SetActorLocation(NuevaPosicion);
}

