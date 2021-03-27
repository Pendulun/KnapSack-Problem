#ifndef BACKPACK_H
#define BACKPACK_H
#include <list>
#include "Item.hpp"

namespace BackPackProblem{
	class BackPack{
	private:
		float maxWeight;
		std::list<Item> items;
	public:
		BackPack(float maxWeight);
		float solve();
		void setItems(std::list<Item> items);
		float getMaxWeight();
		std::list<Item> getItems();
	};
}
#endif