#ifndef BACKPACK_H
#define BACKPACK_H
#include <vector>
#include "Item.hpp"

namespace BackPackProblem{
	class BackPack{
	private:
		float maxWeigth;
		std::vector<Item> items;
	public:
		virtual float solve();
		void setItems(std::vector<Item> items);
		void setMaxWeigth(float maxWeigth);
		float getMaxWeigth();
		std::vector<Item> getItems();
		virtual ~BackPack();
	};
}
#endif