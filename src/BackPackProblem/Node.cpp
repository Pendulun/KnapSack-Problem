#include "Node.hpp"

namespace BackPackProblem{
	Node::Node(int index, float weigth, float value, float bound){
		this->weigth = weigth;
		this->value = value;
		this->index = index;
		this->bound = bound;
	}

	float Node::getWeigth() const{
		return this->weigth;
	}

	float Node::getBound() const{
		return this->bound;
	}

	int Node::getIndex() const{
		return this->index;
	}

	float Node::getValue() const{
		return this->value;
	}

}