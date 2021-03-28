#ifndef NODE_H
#define NODE_H

namespace BackPackProblem{
	class Node{
	private:
		int index;
		float weigth;
		float value;
		float bound;
	public:
		Node(int index, float weigth, float value, float bound);
		float getWeigth() const;
		int getIndex() const;
		float getValue() const;
		float getBound() const;
	};
}

#endif
