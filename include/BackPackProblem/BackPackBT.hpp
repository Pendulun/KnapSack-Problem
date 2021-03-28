#ifndef BACKPACKBT_H
#define BACKPACKBT_H
#include <vector>
#include "BackPack.hpp"
#include "Item.hpp"

namespace BackPackProblem{
	class BackPackBT : public BackPack{
	private:
		float maiorValorPossivel(unsigned int itemIndex, float pesoRestante, float valorTotal);
	public:
		BackPackBT();
		~BackPackBT() override;
		float solve() override;
	};
}
#endif