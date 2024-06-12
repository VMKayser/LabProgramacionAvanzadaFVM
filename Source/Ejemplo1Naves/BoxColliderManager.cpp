#include "BoxColliderManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

ABoxColliderManager::ABoxColliderManager()
{
    PrimaryActorTick.bCanEverTick = true;
    estadoProceso = 0;
    MoverNave = false;
    OnActorBeginOverlap.AddDynamic(this, &ABoxColliderManager::colisionar);
}

void ABoxColliderManager::colisionar(AActor* objetoA, AActor* naveChoque)
{
    estadoProceso++;
    if (objetoA && naveChoque)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("hubo una colision "));
        UE_LOG(LogActor, Warning, TEXT("Hubo una colision entre %s y %s"), *objetoA->GetName(), *naveChoque->GetName());
    }

    switch (estadoProceso) {
    case 1:
        /*FormacionNavesEnemigas(10, 2);*/
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Shapes Creados"));
        break;
    case 2:
        SaltarShapes();
        break;
    case 3:
        MoverNave = true;
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Moviendo Naves"));
        break;
    case 4:
        EliminarObjetos();
        break;
    default:
        estadoProceso = 0;
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Reiniciando"));
        MoverNave = false;
        break;
    }
}

void ABoxColliderManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (MoverNave)
    {
        MoverObjetos(DeltaTime);
    }
}

void ABoxColliderManager::FormacionNavesEnemigas(int CantidadNaves, int NumeroDeFilas)
{
    FVector UbicacionInicial = FVector(-300.0f, 40.0f, 250.0f);
    FVector UbicacionFinal = UbicacionInicial;
    int32 NumeroColumnas = CantidadNaves / NumeroDeFilas;
    for (int32 i = 0; i < CantidadNaves; i++)
    {
        int tipomalla = FMath::RandRange(0, 3);
        CrearNavesEnemigas(UbicacionFinal, tipomalla);
        UbicacionFinal.Y += 300.0f;

        if ((i + 1) % NumeroColumnas == 0)
        {
            UbicacionFinal.X += 300.0f;
            UbicacionFinal.Y = UbicacionInicial.Y;
        }
    }
}

void ABoxColliderManager::CrearNavesEnemigas(FVector UbicacionInicial, int tipomalla)
{
    const FRotator SpawnRotation = FRotator::ZeroRotator;
    UWorld* const World = GetWorld();
    if (World)
    {
        AShape* nuevoShape = World->SpawnActor<AShape>(UbicacionInicial, SpawnRotation);
        if (nuevoShape)
        {
            nuevoShape->AsignarMalla(tipomalla); // Asignar la malla basada en el índice proporcionado

            // Añadir la nave y el índice de malla a las listas
            ListaDeNaves.Add(nuevoShape);
            MallasActual.Add(tipomalla);
        }
    }
}

void ABoxColliderManager::SaltarShapes()
{
    for (int32 i = 0; i < ListaDeNaves.Num(); i++)
    {
        AShape* Shape = ListaDeNaves[i];
        int32 NumeroMalla = MallasActual[i];

        if (Shape)
        {
            Shape->saltar();
            if (NumeroMalla == 1) // Si la malla es la de índice 1
            {
                
            }
        }
    }
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Shapes lanzados"));
}

void ABoxColliderManager::MoverObjetos(float DeltaTime)
{
    for (int32 i = 0; i < ListaDeNaves.Num(); i++)
    {
        AShape* Shape = ListaDeNaves[i];
        int32 NumeroMalla = MallasActual[i];

        if (Shape != nullptr)
        {
            UStaticMeshComponent* MeshComponent = Shape->GetMeshComponent();
            if (MeshComponent && !MeshComponent->IsSimulatingPhysics()) // Si las físicas están desactivadas
            {
                Shape->mover(DeltaTime); // Método de movimiento sin físicas
            }
            else if (MeshComponent && MeshComponent->IsSimulatingPhysics()) // Si las físicas están activadas
            {
                Shape->MoverConImpulso(DeltaTime); // Método de movimiento con físicas y usando impulsos
            }
            if (NumeroMalla == 0) // Si la malla es la de índice 0
            {
                
            }
        }
    }
}

void ABoxColliderManager::EliminarObjetos()
{
    for (int32 i = 0; i < ListaDeNaves.Num(); i++)
    {
        AShape* Shape = ListaDeNaves[i];
        int32 NumeroMalla = MallasActual[i];
        Shape->Destroy();

        if (Shape)
        {
            if (NumeroMalla == 2) // Si la malla es la de índice 2
            {
                /*Shape->Destroy();*/
            }
        }
    }
    ListaDeNaves.Empty(); // Limpiar la lista después de destruir las naves
    MallasActual.Empty(); // Limpiar la lista de mallas
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Shapes destruidos"));
}
