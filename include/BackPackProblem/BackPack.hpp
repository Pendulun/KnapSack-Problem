#ifndef BACKPACK_H
#define BACKPACK_H
#include <list>
#include "Item.hpp"

namespace BackPackProblem{
	class BackPack{
	private:
		float maxWeigth;
		std::list<Item> items;
	public:
		virtual float solve();
		void setItems(std::list<Item> items);
		void setMaxWeigth(float maxWeigth);
		float getMaxWeigth();
		std::list<Item> getItems();
		virtual ~BackPack();
	};
}
#endif