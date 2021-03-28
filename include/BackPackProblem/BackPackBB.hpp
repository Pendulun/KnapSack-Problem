#ifndef BACKPACKBB_H
#define BACKPACKBB_H
#include <vector>
#include <algorithm>
#include "Item.hpp"
#include "BackPack.hpp"
#include <iostream>
#include <queue>
#include <pair>

namespace BackPackProblem{
	class BackPackBB : public BackPack{
	private:
		float maiorValorPossivel();
		float calculaUB(const Item &proxItem, float valor, float pesoRestante);

	public:
		BackPackBB();
		~BackPackBB() override;
		float solve() override;
	};
}
#endif