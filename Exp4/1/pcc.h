/*pcc.h*/
class Point	//声明Point类（基类） 
{
public:
	Point (float, float);
	void setPoint (float, float);
	float getX () const;
	float getY () const;
	friend std::ostream &operator << (std::ostream&, const Point&);//重载<<运算符
protected:
	float x;
	float y;
};

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

