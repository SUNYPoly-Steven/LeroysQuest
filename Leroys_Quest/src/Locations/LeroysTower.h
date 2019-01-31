#pragma once
#include "Location.h"

namespace LeroysQuest {

	class LeroysTower : public Location
	{
	public:
		LeroysTower();
		~LeroysTower();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;

		void OnEnter() override ;
		void OnExit() override ;
		void OnEvent() override ;

	};

}
