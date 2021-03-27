#ifndef BACKPACKBBFACTORY_H
#define BACKPACKBBFACTORY_H
#include "BackPack.hpp"
#include "BackPackBB.hpp"
#include "BackPackFactory.hpp"

namespace BackPackProblem{
	class BackPackBBFactory : public BackPackFactory::BackPackFactory{
	public:
		BackPackBBFactory();
		BackPack* createBackPack() override;
	};
}
#endif