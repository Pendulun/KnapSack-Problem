#ifndef BACKPACKBT_H
#define BACKPACKBT_H
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackBT : public BackPack{
	public:
		BackPackBT(float maxWeight);
		float solve() override;
	};
}
#endif