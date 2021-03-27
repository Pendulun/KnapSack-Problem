#ifndef BACKPACKBTFACTORY_H
#define BACKPACKBTFACTORY_H
#include "BackPack.hpp"
#include "BackPackFactory.hpp"
#include "BackPackBT.hpp"

namespace BackPackProblem{
	class BackPackBTFactory : public BackPackFactory::BackPackFactory{
	public:
		BackPackBTFactory();
		BackPack* createBackPack() override;
	};
}
#endif