/*point.h*/
class Point	//����Point�ࣨ���ࣩ 
{
public:
	Point (float, float);
	void setPoint (float, float);
	float getX () const;
	float getY () const;
	friend std::ostream &operator << (std::ostream&, const Point&);//����<<�����
protected:
	float x;
	float y;
};


