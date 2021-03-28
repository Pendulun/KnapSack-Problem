#ifndef ITEM_H
#define ITEM_H

namespace BackPackProblem{
	class Item{
	private:
		float weigth;
		float value;
	public:
		Item(float weigth, float value);
		float getWeigth() const;
		float getValue() const;
		bool operator <(Item const& second);
	};
}

#endif