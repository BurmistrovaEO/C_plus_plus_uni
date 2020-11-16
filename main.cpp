#include "2D.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
bool comp(Base* b1, Base* b2)
{
	return b1->area < b2->area;
}
vector<Base*> CalculateAreas(vector<Base*>& objs,AreaCounter* areaCounter)
{
	for (Base* obj : objs) {
		obj->accept(areaCounter);
	}
	return areaCounter->GetWholeVect();
}
using namespace std; 
int main()
{
	Circle circle;
	Ellipse ellipse;
	Rectangle rectangle;
	unsigned rand_val = 70;
	int num_of_obj, tmp;
	vector<Base*> objects;
	vector<Base*> objects_w_areas;
	cout << "Please, input the number of the objects: ";
	cin >> num_of_obj;
	srand(rand_val);
	for (int i = 0; i < num_of_obj; i++)
	{
		tmp = rand() % 3;

		if (tmp == 1)
		{
			Circle* obj = new Circle;
			obj->set_Radius(fRand(1.0, 1000.3));
			obj->set_Name();
			objects.push_back(obj);		
		}
		else if(tmp==2)
		{
			Ellipse* obj = new Ellipse;
			obj->set_Values(fRand(1.0, 1000.3), fRand(1.0, 1000.3));
			obj->set_Name();
			objects.push_back(obj);
		}
		else
		{
			Rectangle* obj = new Rectangle;
			obj->set_Values(fRand(1.0, 1000.3), fRand(1.0, 1000.3));
			obj->set_Name();
			objects.push_back(obj);
		}
	}
	cout << '\n';
	AreaCounter *areaCount = new AreaCounter;
	objects_w_areas = CalculateAreas(objects,areaCount);
	sort(objects_w_areas.begin(), objects_w_areas.end(),comp);
	cout << "Objects have been sorted in such a way that their areas are in ascending order."<<'\n';
	for (int i = 0; i < num_of_obj; i++)
	{
		//cout << objects[i]->get_Name() << ' ';
		if (objects[i]->get_Name() == "circle")
			cout << i <<" circle's area is  "<< objects[i]->area<<'\n';
	}
	system("pause");
}