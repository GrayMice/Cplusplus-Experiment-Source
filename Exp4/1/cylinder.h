/*cylinder.h*/
#include "circle.h"
class Cylinder : public Circle	//声明Circle类，公有继承于Circle
{
public:
	Cylinder (float, float, float, float);
	void setHeight (float);
	float getHeight () const;
	float getArea () const;
	float getVolume () const;
	friend std::ostream &operator << (std::ostream&, Cylinder&);//重载<<运算符
protected:
	float height;
};

