#include "Item.hpp"

namespace BackPackProblem{
	Item::Item(float weigth, float value){
		this->weigth = weigth;
		this->value = value;
	}

	float Item::getWeigth() const{
		return this->weigth;
	}

	float Item::getValue() const{
		return this->value;
	}

	bool Item::operator <(Item const& second) {
		return (getValue()/getWeigth())/(second.getValue()/second.getWeigth());
	}
}