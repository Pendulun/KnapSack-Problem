#include "BackPackBTFactory.hpp"

namespace BackPackProblem{

	BackPackBTFactory::BackPackBTFactory(){
		
	}

	BackPack* BackPackBTFactory::createBackPack(){
		return new BackPackBT();
	}
}