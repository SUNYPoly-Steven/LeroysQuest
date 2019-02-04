#pragma once
#include "Location.h"

namespace LeroysQuest {

	class MermaidCove : public Location
	{
	public:
		MermaidCove();
		~MermaidCove();

		const char* Name() const override ;
		const char* Description() const override ;
		const char* ConditionalDescription() const override ;

		void OnEnter() override ;
		void OnExit() override ;
		bool OnEvent(Item item) override ;

	};

}

