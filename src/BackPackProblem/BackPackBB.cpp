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

	float BackPackBB::maiorValorPossivel(){
		
		std::queue<BackPackProblem::Node> filaRamos;

		BackPackProblem::Node noAtual;
		BackPackProblem::Node proxNo;

		float resultado = 0.0;

		noAtual.setIndex(-1);
		noAtual.setValue(0.0);
		noAtual.setWeigth(0.0);

		filaRamos.push(noAtual);

		while(!filaRamos.empty()){
			noAtual = filaRamos.front();
			filaRamos.pop();

			if(noAtual.getIndex() == -1){
				proxNo.setIndex(0);
			}

			if(noAtual.getIndex() == this->getItems().size() -1){
				continue;
			}

			proxNo.setIndex(noAtual.getIndex()+1);
			proxNo.setWeigth(noAtual.getWeigth() + this->getItems()[proxNo.getIndex()].getWeigth());
			proxNo.setValue(noAtual.getValue() + this->getItems()[proxNo.getIndex()].getValue());

			if(proxNo.getWeigth() <= this->getMaxWeigth() && proxNo.getValue() > resultado){
				resultado = proxNo.getValue();
			}

			proxNo.setBound(this->calculaUB(proxNo));

			if(proxNo.getBound() > resultado){
				filaRamos.push(proxNo);
			}

			proxNo.setWeigth(noAtual.getWeigth());
			proxNo.setValue(noAtual.getValue());
			proxNo.setBound(this->calculaUB(proxNo));

			if(proxNo.getBound() > resultado){
				filaRamos.push(proxNo);
			}

		}

		return resultado;
	}

	float BackPackBB::solve(){
		return maiorValorPossivel();
	}
}