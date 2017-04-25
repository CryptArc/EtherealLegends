// Ãƒâ€šÃ‚Â© 2014 - 2016 Soverance Studios
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
#include "AssassinsCuffs.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AAssassinsCuffs::AAssassinsCuffs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_AssassinsCuffs.ArmorIcon_AssassinsCuffs'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/ArmorIcon_AssassinsCuffs-small.ArmorIcon_AssassinsCuffs-small'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> ArmorMeshObject(TEXT("SkeletalMesh'/Game/EtherealParty/Morgan/Clothes/AssassinsGarb/AssassinsCuffs/AssassinsCuffs.AssassinsCuffs'"));

	// Set Default Objects
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_ArmorMesh = ArmorMeshObject.Object;
	ArmorMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("ArmorMesh"));
	ArmorMesh->SetSkeletalMesh(SK_ArmorMesh);
	ArmorMesh->SetupAttachment(RootComponent);
	UCommonLibrary::SetupSKComponentsWithCollision(ArmorMesh);
	
	// Set Default Values
	Name = EMasterGearList::GL_AssassinsCuffs;
	NameText = LOCTEXT("AssassinsCuffsName", "Assassins Cuffs");
	Type = EMasterGearTypes::GT_Hand;
	TypeText = LOCTEXT("AssassinsCuffsType", "Hands");
	Description = "Armor of Ethereal Assassins.";
	Price = 20000;
	MPCost = 0;
	ATK = 4;
	DEF = 2;
	SPD = 2;
	HP = 30;
	MP = 10;
	SpecialEffectText = LOCTEXT("AssassinsCuffsSpecialEffect", "Ranged Damage +25%.");
}

// Called when the game starts or when spawned
void AAssassinsCuffs::BeginPlay()
{
	Super::BeginPlay();

	// Bind this function to the event dispatcher for Bind Gear
	OnBindGear.AddDynamic(this, &AAssassinsCuffs::DoSpecialEffect);
	OnRemoveGear.AddDynamic(this, &AAssassinsCuffs::RemoveSpecialEffect);
}

// Custom code for Special Effect
void AAssassinsCuffs::DoSpecialEffect()
{
	OwnerReference->BoostRanged = true;
}

// Custom code for Special Effect
void AAssassinsCuffs::RemoveSpecialEffect()
{
	OwnerReference->BoostRanged = false;
}

#undef LOCTEXT_NAMESPACE
