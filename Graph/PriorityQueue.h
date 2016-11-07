#ifndef _PQ
#define _PQ
#include<vector>
#include<algorithm>
template <typename item>
class PQ
{
public:
	PQ() { }
	bool contains(item i) { return (std::find(bank.begin(), bank.end(), i) != bank.end()); }
	void insert(item i) { bank.push_back(i); }
	item top() {
		std::sort(bank.begin(), bank.end());
		return bank.at(0);
	} 
	int size() { return bank.size(); }
	item minPriority() {
		std::sort(bank.begin(), bank.end());
		item minVal = bank.at(0);
		bank.erase(bank.begin());
		return minVal;
	}// removes the item at the top of the queue
	void chgPriority(item i, double new_priority) {
		std::vector<item>::iterator it = std::find(bank.begin(), bank.end(), i);
		(*it).setVal(new_priority);
	}


private:
	std::vector<item> bank;
};
#endif
