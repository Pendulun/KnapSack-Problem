#ifndef BACKPACKBBFACTORY_H
#define BACKPACKBBFACTORY_H
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackBBFactory : public BackPackFactory{
	public:
		BackPackBBFactory();
		BackPack* createBackPack() override;
	};
}
#endif