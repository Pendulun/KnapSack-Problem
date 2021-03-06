#include "Node.hpp"

namespace BackPackProblem{
	Node::Node(){}

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

	void Node::setWeigth(float weigth){
		this->weigth = weigth;
	}

	void Node::setIndex(int index){
		this->index = index;
	}
	
	void Node::setValue(float value){
		this->value = value;
	}

	void Node::setBound(float bound){
		this->bound = bound;
	}

}