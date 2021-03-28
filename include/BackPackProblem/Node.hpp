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
		Node();
		float getWeigth() const;
		int getIndex() const;
		float getValue() const;
		float getBound() const;

		void setWeigth(float);
		void setIndex(int);
		void setValue(float);
		void setBound(float);

	};
}

#endif
