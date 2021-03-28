#include "BackPack.hpp"

namespace BackPackProblem{

	BackPack::~BackPack(){
	}

	float BackPack::solve(){
		return -1;
	}

	void BackPack::setMaxWeigth(float maxWeigth){
		this->maxWeigth = maxWeigth;
	}

	float BackPack::getMaxWeigth(){
		return this->maxWeigth;
	}

	void BackPack::setItems(std::vector<Item> items){
		this->items = items;
	}

	std::vector<Item> BackPack::getItems(){
		return this->items;
	}


}