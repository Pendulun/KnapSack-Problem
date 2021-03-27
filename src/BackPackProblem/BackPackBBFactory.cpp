#include "BackPackBBFactory.hpp"

namespace BackPackProblem{

	BackPackBBFactory::BackPackBBFactory(){
		
	}

	BackPack* BackPackBBFactory::createBackPack(){
		return new BackPackBB();
	}
}