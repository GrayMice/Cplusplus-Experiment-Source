/*circle.h*/
#include "point.h"
class Circle : public Point	//����Circle�࣬���м̳���Point 
{
public:
	Circle (float, float, float);
	void setRadius (float);
	float getRadius () const;
	float getArea () const;
	friend std::ostream &operator << (std::ostream&, const Circle&);//����<<����� 
protected:
	float radius;
};

