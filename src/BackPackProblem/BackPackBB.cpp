#include "BackPackBB.hpp"

namespace BackPackProblem{

	BackPackBB::BackPackBB(float maxWeigth){
		BackPack::BackPack(maxWeigth);
	}

	float BackPackBB::solve(){
		return 1.0;
	}
}