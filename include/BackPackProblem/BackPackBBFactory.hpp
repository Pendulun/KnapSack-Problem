#ifndef BACKPACKBBFACTORY_H
#define BACKPACKBBFACTORY_H
#include "BackPack.hpp"
#include "BackPackBB.hpp"

namespace BackPackProblem{
	class BackPackBBFactory : public BackPackFactory{
	public:
		BackPackBBFactory();
		BackPack* createBackPack(float maxWeigth) override;
	};
}
#endif