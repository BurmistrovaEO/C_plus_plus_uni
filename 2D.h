const double PI = 3.1415;
#include <random>
#include <vector>
#include <string>
using namespace std;
class Circle;
class Ellipse;
class Rectangle;

class Visitor
{
public:
	virtual void visit(Circle*)=0;
	virtual void visit(Ellipse*)=0;
	virtual void visit(Rectangle*)=0;
};
class Base
{
public:
	double area;	
	string name;
	string get_Name();
	virtual void accept(Visitor *visitor)=0;
	Base();
	virtual ~Base() {};
};
class Circle:public Base
{
	double radius;

public:		
	//double area;
	Circle();
	virtual ~Circle() {};
	void set_Name();
	//string get_Name();
	void set_Radius(double rad);
	void set_Area();
	void accept(Visitor *visitor)
	{
		visitor->visit(this);
	}
};
class Ellipse :public Base
{
	double b_half;
	double small_half;

public:	
	//string name = "ellipse";
	Ellipse();
	virtual ~Ellipse() {};
	void set_Values(double bigger,double smaller);	
	//string get_Name();
	void set_Area();
	void set_Name();
	void accept(Visitor *visitor)
	{
		visitor->visit(this);
	}
};
class Rectangle:public Base
{
	double length; 
	double width;
public:
	Rectangle();
	virtual ~Rectangle() {};
	void set_Values(double length, double width);
	void set_Area();
	void set_Name();
	void accept(Visitor *visitor)
	{
		visitor->visit(this);
	}
};
double fRand(double fMin, double fMax);


class AreaCounter:public Visitor
{
	vector<Base*> areas;
public:
	//AreaCounter();
	vector<Base*>& GetWholeVect();
	void visit(Circle* circle);
	void visit(Ellipse* ellipse);
	void visit(Rectangle* rectangle);
	//virtual ~AreaCounter();
};

