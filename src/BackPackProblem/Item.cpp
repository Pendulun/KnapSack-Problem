#include "Item.hpp"

namespace BackPackProblem{
	Item::Item(float weigth, float value){
		this->weigth = weigth;
		this->value = value;
	}

	float Item::getWeigth(){
		return this->weigth;
	}

	float Item::getValue(){
		return this->value;
	}
}