// Fill out your copyright notice in the Description page of Project Settings.


#include "ComputeTestActor.h"

#include "ExampleComputeShader/ExampleComputeShader.h"
#include "RedShiftComputeShader/RedShiftComputeShader.h"


// Sets default values
AComputeTestActor::AComputeTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AComputeTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComputeTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FExampleComputeShaderDispatchParams Params(1, 1, 1);

	Params.Input[0] = 5;
	Params.Input[1] = 10;

	//FExampleComputeShaderInterface::Dispatch(Params);
	// UE_LOG(LogTemp, Log, TEXT("Compute Shader Output: %d\n"), Params.Output);


	FExampleComputeShaderInterface::Dispatch(Params, [](int output_val) {
		UE_LOG(LogTemp, Log, TEXT("Example Compute Shader Output: %d\n"), output_val);
	});


	FRedShiftComputeShaderDispatchParams redshift_params(1, 1, 1);
	redshift_params.Input[0] = 5;
	redshift_params.Input[1] = 10;

	FRedShiftComputeShaderInterface::Dispatch(redshift_params, [](int output_val) {
		UE_LOG(LogTemp, Log, TEXT("RedShift Compute Shader Output: %d\n"), output_val);
	});
}

