#include "BackPack.hpp"

namespace BackPackProblem{

	BackPack::~BackPack(){
	}

	float BackPack::solve(){
	}

	void BackPack::setMaxWeigth(float maxWeigth){
		this->maxWeigth = maxWeigth;
	}

	float BackPack::getMaxWeigth(){
		return this->maxWeigth;
	}

	void BackPack::setItems(std::list<Item> items){
		this->items = items;
	}

	std::list<Item> BackPack::getItems(){
		return this->items;
	}


}