// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L02GameMode.h"
#include "Galaga_USFX_L02Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaTerrestre.h"
#include "NaveEnemigaAerea.h"
#include "NaveEnemigaAcuatica.h"

AGalaga_USFX_L02GameMode::AGalaga_USFX_L02GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_L02Pawn::StaticClass();
	//NaveEnemiga01 = nullptr;
}
TArray<TSubclassOf<ANaveEnemiga>> claseNave = { ANaveEnemigaTerrestre::StaticClass(), ANaveEnemigaAerea::StaticClass(), ANaveEnemigaAcuatica::StaticClass() };

FVector ubicacionInicialNavesEnemigas = FVector(0.0f, 0.0f, 200.0f);
FVector ubicacionActualNaveEnemiga = ubicacionInicialNavesEnemigas;
FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

FTimerHandle TimerHandle_AgregarNaves;

void AGalaga_USFX_L02GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing



	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
	
		//for (int i = 0; i < 5; i++) {
		//	ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionActualNaveEnemiga, rotacionNave);
		//	//TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
		//	NaveEnemigaCazaActual->SetNombre("nave enemiga caza " + FString::FromInt(i));
		//	TANavesEnemigas.Add(NaveEnemigaCazaActual);
		//	TMPosicionesNavesEnemigas.Add(NaveEnemigaCazaActual, ubicacionActualNaveEnemiga);

		//	ubicacionActualNaveEnemiga.Y = ubicacionActualNaveEnemiga.Y + 150.0f;
		//}

		//ubicacionActualNaveEnemiga.X = ubicacionActualNaveEnemiga.X - 150.0f;
		//ubicacionActualNaveEnemiga.Y = ubicacionInicialNavesEnemigas.Y;
		//for (int j = 0; j < 5; j++) {
		//	
		//	ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionActualNaveEnemiga, rotacionNave);
		//	//TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
		//	NaveEnemigaTransporteActual->SetNombre("nave enemiga transporte" + FString::FromInt(j));
		//	TANavesEnemigas.Add(NaveEnemigaTransporteActual);
		//	TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionActualNaveEnemiga);

		//	ubicacionActualNaveEnemiga.Y = ubicacionActualNaveEnemiga.Y + 150.0f;
		//}

		/*FTimerHandle FTHVisualizacionPosicionesNavesEnemigas;*/

		//GetWorldTimerManager().SetTimer(FTHVisualizacionPosicionesNavesEnemigas, this, &AGalaga_USFX_L02GameMode::MostrarPosicionesNavesEnemigas, 1.0f, true);
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_AgregarNaves, this, &AGalaga_USFX_L02GameMode::CrearNaves, 10.0f, true, 5.0f);
	}

}

//void AGalaga_USFX_L02GameMode::MostrarPosicionesNavesEnemigas()
//{
//	for (auto ElementoActual : TMPosicionesNavesEnemigas) {
//		ANaveEnemiga* naveEnemigaActual = ElementoActual.Key;
//		FVector posicionActualNaveEnemiga = ElementoActual.Value;
//		FString mensaje = "La nave " + naveEnemigaActual->GetNombre() + " esta en la posicion> " + posicionActualNaveEnemiga.ToString();
//
//		if (GEngine)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, mensaje);
//
//			/*FString mensaje = "Nombre NaveEnemiga: " + Clave->GetNombre() + " Posicion NaveEnemiga: " + Valor.ToString();
//			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, mensaje);*/
//
//		}
//
//		TMPosicionesNavesEnemigas[naveEnemigaActual] = naveEnemigaActual->GetActorLocation();
//	}
//}
void AGalaga_USFX_L02GameMode::CrearNaves()
{
	 for (int i = 0; i < 3; ++i)
	 {
		 TSubclassOf<ANaveEnemiga> ClaseRandom = claseNave[FMath::RandRange(0, claseNave.Num() - 1)];
		 FVector SpawnLocation = ubicacionActualNaveEnemiga + FVector(0.f, (TMPosicionesNavesEnemigas.Num() + i) * 50.f, 0.f);
		 FRotator SpawnRotation = FRotator::ZeroRotator;
		 ANaveEnemiga* NuevaNaveSpawn = GetWorld()->SpawnActor<ANaveEnemiga>(ClaseRandom, SpawnLocation, SpawnRotation);
		
	 }
}