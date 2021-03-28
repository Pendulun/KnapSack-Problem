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

	float BackPackBB::maiorValorPossivel(){
		float maiorValor = 0.0;
		float pesoAcumulado = 0.0;

		std::queue<<Item,int>> filaItems;

		BackPackProblem::Item itemRaiz(0.0,0.0);

		filaItems.push(std::make_pair(itemRaiz,-1));

		while(!filaItems.empty()){
			std::pair<Item,int> parAtual = filaItems.pop();
			BackPackProblem::Item itemAtual = parAtual.first;
			int index = parAtual.second;


			if(index == this->getItems().size()){
				continue;
			}

			BackPackProblem::Item proxItem = this->getItems()[index+1];

			float ubProxItem = calculaUB(proxItem, maiorValor, this->getMaxWeigth()-pesoAcumulado);

			if(ubProxItem > maiorValor){
				filaItems.push(std::make_pair(proxItem,index+1));
			}

			

		}
	}

	float BackPackBB::solve(){
		return maiorValorPossivel();
	}
}