#include "2D.h"
#include <math.h>
using namespace std;

Base::Base()
{

};
Base::~Base()
{

};
Circle::Circle()
{

};
Circle::~Circle()
{

};
Ellipse::Ellipse()
{

};
Ellipse::~Ellipse()
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