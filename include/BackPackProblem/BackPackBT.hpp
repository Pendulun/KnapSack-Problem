#ifndef BACKPACKBT_H
#define BACKPACKBT_H
#include <list>
#include "BackPack.hpp"
#include "Item.hpp"

namespace BackPackProblem{
	class BackPackBT : public BackPack{
	public:
		BackPackBT(float maxWeight);
		float solve() override;
	};
}
#endif