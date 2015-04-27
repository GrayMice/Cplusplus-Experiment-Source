/*circle.h*/
#include "point.h"
class Circle : public Point	//声明Circle类，公有继承于Point 
{
public:
	Circle (float, float, float);
	void setRadius (float);
	float getRadius () const;
	float getArea () const;
	friend std::ostream &operator << (std::ostream&, const Circle&);//重载<<运算符 
protected:
	float radius;
};

