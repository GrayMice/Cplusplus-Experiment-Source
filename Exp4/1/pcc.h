/*pcc.h*/
class Point	//ÉùÃ÷PointÀà 
{
public:
	Point (float, float);
	void setPoint (float, float);
	float getX () const;
	float getY () const;
	friend std::ostream &operator << (std::ostream&, const Point&);
protected:
	float x;
	float y;
};

class Circle : public Point
{
public:
	Circle (float, float, float);
	void setRadius (float);
	float getRadius () const;
	float getArea () const;
	friend std::ostream &operator << (std::ostream&, const Circle&);
protected:
	float radius;
};
	
class Cylinder : public Circle
{
public:
	Cylinder (float, float, float, float);
	void setHeight (float);
	float getHeight () const;
	float getArea () const;
	float getVolume () const;
	friend std::ostream &operator << (std::ostream&, Cylinder&);
protected:
	float height;
};

