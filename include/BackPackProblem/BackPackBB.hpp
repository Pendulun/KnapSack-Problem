#ifndef BACKPACKBB_H
#define BACKPACKBB_H
#include <vector>
#include <algorithm>
#include "Item.hpp"
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackBB : public BackPack{
	private:
		float maiorValorPossivel();
	public:
		BackPackBB();
		~BackPackBB() override;
		float solve() override;
	};
}
#endif