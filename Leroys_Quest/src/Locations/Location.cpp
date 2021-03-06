#include "Location.h"
#include <algorithm>
#include <iterator>
#include <iostream>

#include "Core.h"

namespace LeroysQuest {

	Location::Location()
	{}

	Location::~Location()
	{}

	const char* Location::Name() const
	{
		return "Nowhere important...";
	}

	const char* Location::Description() const
	{
		return "As the fog sets in it becomes harder to see... \n"
			"Maybe if you keep going it will clear.\n";
	}

	const char* Location::ConditionalDescription() const
	{
		return "";
	}

	const char* Location::TransDiscription() const
	{
		return "Looks like it leads somewhere...\n";
	}


	void Location::OnEnter()
	{ /* Leave empty so if the subclass doesnt implement it will do nothing */ }

	bool Location::OnExit(MovementDirection exitDir)
	{ 
		/* Default behavior for a location is to allow passage through in any direction */
		return true;
	}

	bool Location::OnEvent(Item item)
	{
		/* Default behavior for a location is to not handle the event */
		return false;
	}



	Location* Location::Move(MovementDirection direction) const
	{
		return m_Transitions[static_cast<size_t>(direction) - 1];
	}



	Optional<Item> Location::OnItemGet(const std::string& itemName)
	{
		auto it = std::find_if(m_Inventory.begin(), m_Inventory.end(), 
			[&](const Item& item) -> bool {
				return item.GetName() == itemName;
			}
		);
		if (it == m_Inventory.end())
		{
			/* No item to get so return nothing */
			return Optional<Item>(/* No Value */);
		}
		else
		{
			auto idx = std::distance(m_Inventory.begin(), it);

			Item out = m_Inventory.at(idx);
			m_Inventory.erase(it);

			/* Return the item */
			return Optional<Item>(std::move(out));
		}
	}

	void Location::OnItemDrop(Item item)
	{
		m_Inventory.push_back(std::move(item));
	}

	void Location::OnItemLook(const std::string& itemName) const
	{
		auto it = std::find_if(m_Inventory.begin(), m_Inventory.end(),
			[&](const Item& item) -> bool {
				return item.GetName() == itemName;
			}
		);

		if (it == m_Inventory.end())
		{
			std::cout << "Either the thing you are looking for isn't here, or it's invisible... \nGood luck finding it...\n";
			return;
		}

		auto idx = std::distance(m_Inventory.begin(), it);

		std::cout << m_Inventory[idx].GetDiscription();
	}

	void Location::SetTransitions(std::array<Location*, 4> trans)
	{
		m_Transitions = trans;
	}

	void Location::PrintAreaTransitions() const
	{
		std::cout << "To the North: " << ((!m_Transitions[0]) ? "Nothing...\n" : m_Transitions[0]->TransDiscription());
		std::cout << "To the South: " << ((!m_Transitions[1]) ? "Nothing...\n" : m_Transitions[1]->TransDiscription());
		std::cout << "To the East:  " << ((!m_Transitions[2]) ? "Nothing...\n" : m_Transitions[2]->TransDiscription());
		std::cout << "To the West:  " << ((!m_Transitions[3]) ? "Nothing...\n" : m_Transitions[3]->TransDiscription());
	}

}
