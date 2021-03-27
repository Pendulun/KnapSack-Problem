#include "BackPackBT.hpp"

namespace BackPackProblem{

	BackPackBT::BackPackBT(float maxWeigth){
		BackPack::BackPack(maxWeigth);
	}

	float BackPackBT::solve(){
		return 1.0;
	}
}