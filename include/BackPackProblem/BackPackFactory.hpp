#ifndef BACKPACKFACTORY_H
#define BACKPACKFACTORY_H
#include "BackPack.hpp"

namespace BackPackProblem{
	class BackPackFactory{
	public:
		BackPackFactory();
		virtual ~BackPackFactory();
		virtual BackPack* createBackPack() = 0;
	};
}
#endif