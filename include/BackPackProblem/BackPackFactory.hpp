#ifndef BACKPACKFACTORY_H
#define BACKPACKFACTORY_H
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackFactory{
	public:
		BackPackFactory();
		virtual ~BackPackFactory();
		virtual BackPack* createBackPack(float maxWeigth) = 0;
	};
}
#endif