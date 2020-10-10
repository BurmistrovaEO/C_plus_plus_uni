const double PI = 3.1415;
#include <random>
#include <string>
using namespace std;
class Base
{
public:
	double area;	
	string name;
	string get_Name();
	Base();
	~Base();
};
class Circle:public Base
{
	double radius;

public:		
	//double area;
	Circle();
	~Circle();	
	void set_Name();
	//string get_Name();
	void set_Radius(double rad);
	void set_Area();
};
class Ellipse :public Base
{
	double b_half;
	double small_half;

public:	
	//string name = "ellipse";
	Ellipse();
	~Ellipse();
	void set_Values(double bigger,double smaller);	
	//string get_Name();
	void set_Area();
	void set_Name();
};
double fRand(double fMin, double fMax);