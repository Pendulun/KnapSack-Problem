#ifndef BACKPACKBTFACTORY_H
#define BACKPACKBTFACTORY_H
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackBTFactory : public BackPackFactory{
	public:
		BackPackBTFactory();
		BackPack* createBackPack() override;
	};
}
#endif