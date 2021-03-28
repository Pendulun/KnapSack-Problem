#include "BackPackBB.hpp"

namespace BackPackProblem{

	BackPackBB::BackPackBB(){
	}

	BackPackBB::~BackPackBB(){
	}

	float BackPackBB::maiorValorPossivel(){
		return -1;
	}

	float BackPackBB::solve(){
		std::sort(BackPack::getItems().begin(),BackPack::getItems().end());
		return maiorValorPossivel();
	}
}