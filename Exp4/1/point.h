/*point.h*/
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


