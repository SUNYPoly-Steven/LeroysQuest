#include "Braids.h"

namespace LeroysQuest {

	Braids::Braids()
	{
	}


	Braids::~Braids()
	{
	}


	const char* Braids::Name() const
	{
		return "The Braids";
	}

	const char* Braids::Description() const
	{
		return "";
	} 

	const char* Braids::ConditionalDescription() const
	{
		return ""; 
	}



	void Braids::OnEnter()
	{}

	void Braids::OnExit()
	{}

	bool Braids::OnEvent(Item item)
	{
		return false;
	}

}