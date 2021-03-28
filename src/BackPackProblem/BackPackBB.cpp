#include "BackPackBB.hpp"

namespace BackPackProblem{

	BackPackBB::BackPackBB(){
	}

	BackPackBB::~BackPackBB(){
	}

	float BackPackBB::calculaUB(BackPackProblem::Node& noAtual){
		if(noAtual.getWeigth() > this->getMaxWeigth()){
			return 0;
		}

		float limiteSuperior = noAtual.getValue();

		int proxIndex = noAtual.getIndex() + 1;

		float pesoTotalUsado = noAtual.getWeigth();

		while((proxIndex < this->getItems().size()) && (pesoTotalUsado + this->getItems()[proxIndex].getWeigth() <= this->getMaxWeigth())){
			pesoTotalUsado += this->getItems()[proxIndex].getWeigth();
			limiteSuperior += this->getItems()[proxIndex].getValue();
			proxIndex++;
		}

		if(proxIndex < this->getItems().size()){
			float pesoRestante = this->getMaxWeigth() - pesoTotalUsado;
			float valorRelativo = this->getItems()[proxIndex].getValue()/this->getItems()[proxIndex].getWeigth();
			limiteSuperior += (pesoRestante) * (valorRelativo);
		}

		return limiteSuperior;
	}

	//Não implementado
	float BackPackBB::maiorValorPossivel(){
		
		std::queue<BackPackProblem::Node> filaRamos;

		
	}

	float BackPackBB::solve(){
		return maiorValorPossivel();
	}
}