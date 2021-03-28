#ifndef BACKPACKBB_H
#define BACKPACKBB_H
#include <vector>
#include "Item.hpp"
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackBB : public BackPack{
	public:
		BackPackBB();
		~BackPackBB() override;
		float solve() override;
	};
}
#endif