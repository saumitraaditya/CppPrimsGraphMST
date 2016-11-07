
/*http://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects*/
# ifndef _VERTEX
# define _VERTEX
class vertex
{
private:
	int id;
	double val;
public:
	vertex() { id = 0; val = 0; }
	vertex(int id, double val) :id(id), val(val) {}
	int getID() const { return id; }
	double getVal() const { return val; }
	void setVal(double val) { this->val = val; }
	//overloaded '<' operator to allow  STL sorting of vertex objects in STL containers.
	bool operator < (const vertex& vert) const
	{
		return (this->val < vert.getVal());
	}

	bool operator == (const vertex& vert) const
	{
		return (this->id == vert.getID());
	}
};
# endif
