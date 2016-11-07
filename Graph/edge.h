
# ifndef _EDGE
# define _EDGE
class edge
{
public:
	inline edge(int src, int dst, double cost) :src(src), dst(dst), cost(cost) {};
	int getSrc() const { return src; }
	int getDst() const { return dst; }
	double getCost() const { return cost; }
	void setCost(double cost) { this->cost = cost; }
private:
	int src, dst;
	double cost;
};
# endif
