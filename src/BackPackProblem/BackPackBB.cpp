#include "BackPackBB.hpp"

namespace BackPackProblem{

	BackPackBB::BackPackBB(){
	}

	BackPackBB::~BackPackBB(){
	}

	float BackPackBB::calculaUB(const Item &proxItem, float valor, float pesoRestante){
		float valorEstimado = proxItem.getValue();
		valorEstimado /= proxItem.getWeigth();
		return valor + pesoRestante*valorEstimado;
	}

	//Não implementado
	float BackPackBB::maiorValorPossivel(){
		return -1;
	}

	float BackPackBB::solve(){
		return maiorValorPossivel();
	}
}