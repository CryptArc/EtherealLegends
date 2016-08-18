// � 2014 - 2016 Soverance Studios
// www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http ://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "GameFramework/GameMode.h"
//#include "EtherealGameInstance.h"
#include "EtherealPlayerController.h"
#include "EtherealPlayerState.h"
#include "EtherealGameState.h"
#include "EtherealGameMode.generated.h"

UCLASS()
class AEtherealGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AEtherealGameMode(const FObjectInitializer& ObjectInitializer);
		
};


