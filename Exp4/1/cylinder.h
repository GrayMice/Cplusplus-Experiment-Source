/*cylinder.h*/
#include "circle.h"
class Cylinder : public Circle	//����Circle�࣬���м̳���Circle
{
public:
	Cylinder (float, float, float, float);
	void setHeight (float);
	float getHeight () const;
	float getArea () const;
	float getVolume () const;
	friend std::ostream &operator << (std::ostream&, Cylinder&);//����<<�����
protected:
	float height;
};

