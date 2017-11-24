// Ãƒ€šÃ‚© 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "AssassinsVest.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AAssassinsVest::AAssassinsVest(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_AssassinsVest.ArmorIcon_AssassinsVest'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_AssassinsVest-small.ArmorIcon_AssassinsVest-small'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> ArmorMeshObject(TEXT("SkeletalMesh'/Game/EtherealParty/Morgan/Clothes/AssassinsGarb/AssassinsVest/AssassinsVest.AssassinsVest'"));

	// Set Default Objects
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_ArmorMesh = ArmorMeshObject.Object;
	ArmorMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("ArmorMesh"));
	ArmorMesh->SetSkeletalMesh(SK_ArmorMesh);
	ArmorMesh->SetupAttachment(RootComponent);
	UCommonLibrary::SetupSKComponentsWithCollision(ArmorMesh);
	
	// Set Default Values
	Name = EMasterGearList::GL_AssassinsVest;
	NameText = LOCTEXT("AssassinsVestName", "Assassins Vest");
	Type = EMasterGearTypes::GT_Body;
	TypeText = LOCTEXT("AssassinsVestType", "Body");
	Description = "Armor of Ethereal Assassins.";
	Price = 20000;
	MPCost = 0;
	ATK = 4;
	DEF = 2;
	SPD = 2;
	HP = 30;
	MP = 10;
	SpecialEffectText = LOCTEXT("AssassinsVestSpecialEffect", "Prevents all negative status effects.");
}

// Called when the game starts or when spawned
void AAssassinsVest::BeginPlay()
{
	Super::BeginPlay();

	// Bind this function to the event dispatcher for Bind Gear
	OnBindGear.AddDynamic(this, &AAssassinsVest::DoSpecialEffect);
	OnRemoveGear.AddDynamic(this, &AAssassinsVest::RemoveSpecialEffect);
}

// Custom code for Special Effect
void AAssassinsVest::DoSpecialEffect()
{
	OwnerReference->NullPoison = true;
	OwnerReference->NullBurn = true;
	OwnerReference->NullConfuse = true;
	OwnerReference->NullSilence = true;
}

// Custom code for Special Effect
void AAssassinsVest::RemoveSpecialEffect()
{
	OwnerReference->NullPoison = false;
	OwnerReference->NullBurn = false;
	OwnerReference->NullConfuse = false;
	OwnerReference->NullSilence = false;
}

#undef LOCTEXT_NAMESPACE
