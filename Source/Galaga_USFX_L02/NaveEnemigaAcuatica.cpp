// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaAcuatica.h"
ANaveEnemigaAcuatica::ANaveEnemigaAcuatica()
{
}
void ANaveEnemigaAcuatica::BeginPlay()
{
	Super::BeginPlay();
}
void ANaveEnemigaAcuatica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void ANaveEnemigaAcuatica::Mover(float Deltatime)
{
	// Obtiene la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * Deltatime;
	float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * Deltatime;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);
}

