#include "BackPackBT.hpp"

namespace BackPackProblem{

	BackPackBT::BackPackBT(){
	}

	BackPackBT::~BackPackBT(){
	}

	float BackPackBT::solve(){
		return maiorValorPossivel(0, this->BackPack::getMaxWeigth(),0);
	}

	float BackPackBT::maiorValorPossivel(unsigned int itemIndex, float pesoRestante, float valorTotal){
		if(itemIndex == this->BackPack::getItems().size()){
			return valorTotal;
		}else{

			float pesoItem = this->BackPack::getItems()[itemIndex].getWeigth();
			float valorItem = this->BackPack::getItems()[itemIndex].getValue();
			float valorComItem = 0.0;
			float valorSemItem = 0.0;

			//Poda de ramo
			if(pesoRestante-pesoItem >=0){
				valorComItem = this->maiorValorPossivel(itemIndex+1,pesoRestante-pesoItem,valorTotal+valorItem);
			}

			valorSemItem = this->maiorValorPossivel(itemIndex+1,pesoRestante,valorTotal);

			if(valorComItem > valorSemItem){
				return valorComItem;
			}else{
				return valorSemItem;
			}
		}
	}
}