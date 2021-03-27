#ifndef BACKPACKBTFACTORY_H
#define BACKPACKBTFACTORY_H
#include "BackPack.hpp"
#include "BackPackBT.hpp"

namespace BackPackProblem{
	class BackPackBTFactory : public BackPackFactory{
	public:
		BackPackBTFactory();
		BackPack* createBackPack(float maxWeigth) override;
	};
}
#endif