#ifndef BACKPACKBB_H
#define BACKPACKBB_H
#include <list>
#include "Item.hpp"
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackBB : public BackPack{
	public:
		BackPackBB(float maxWeight);
		float solve() override;
	};
}
#endif