#include "2D.h"
#include <math.h>
using namespace std;

Base::Base()
{

};

Circle::Circle()
{

};

Ellipse::Ellipse()
{

};

void Circle::set_Radius(double rad)
{
	Circle::radius = rad;
};
void Circle::set_Area()
{
	Circle::area = pow(Circle::radius,2) * PI;
};
void Circle::set_Name()
{
	Circle::name = "circle";
};
string Base::get_Name()
{
	return Base::name;
};
void Ellipse::set_Values(double bigger, double smaller) 
{
	Ellipse::b_half = bigger;
	Ellipse::small_half = smaller;
};
void Ellipse::set_Area()
{
	Ellipse::area = Ellipse::b_half * Ellipse::small_half*PI;
};
void Ellipse::set_Name()
{
	Ellipse::name = "ellipse";
};
double fRand(double fMin, double fMax)
{
	double f = (double)(rand() % (70 - 1) + 2) / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

Rectangle::Rectangle()
{

};

void Rectangle::set_Values(double len, double wid)
{
	Rectangle::length = len;
	Rectangle::width = wid;
};
void Rectangle::set_Area()
{
	Rectangle::area = Rectangle::length * Rectangle::width;
};
void Rectangle::set_Name()
{
	Rectangle::name = "rectangle";
};

void AreaCounter::visit(Circle* circle)
{
	circle->set_Area();
	areas.push_back(circle);
};
void AreaCounter::visit(Ellipse* ellipse)
{
	ellipse->set_Area();
	areas.push_back(ellipse);

};
vector<Base*>& AreaCounter::GetWholeVect()
{
	return this->areas;
};
void AreaCounter::visit(Rectangle* rectangle)
{
	rectangle->set_Area();
	areas.push_back(rectangle);
};