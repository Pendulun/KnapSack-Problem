#ifndef BACKPACKBB_H
#define BACKPACKBB_H
#include <vector>
#include <algorithm>
#include "Item.hpp"
#include "Node.hpp"
#include "BackPack.hpp"
#include <iostream>
#include <queue>
#include <utility>

namespace BackPackProblem{
	class BackPackBB : public BackPack{
	private:
		float maiorValorPossivel();
		float calculaUB(BackPackProblem::Node& noAtual);

	public:
		BackPackBB();
		~BackPackBB() override;
		float solve() override;
	};
}
#endif