#include<math.h>
#include<stdio.h>

/*
class Point2D
{
public:
	Point2D();
	Point2D(double _x, double _y);

	double GetX() const;
	double GetY() const;
	double Distance(const Point2D& _other) const;

	Point2D &operator+=(const Point2D& _other);
	Point2D &operator*=(double _factor);

private:
	double m_x;
	double m_y;		
};
*/
typedef struct Point2D
{
	double m_x;
	double m_y;
}Point2D;



/*
Point2D::Point2D()
: m_x(0), m_y(0)
{
}
*/
void Point2D_CreatePoint2D_1(Point2D* const _this)
{
	_this->m_x = 0;
	_this->m_y = 0;
	return;
}



/*
Point2D::Point2D(double _x, double _y)
: m_x(_x), m_y(_y)
{
}
*/
void Point2D_CreatePoint2D_3(Point2D* const _this, double _x, double _y)
{
	_this->m_x = _x;
	_this->m_y = _y;
	return;
}



/*
inline double Point2D::GetX() const
{
	return m_x;
}
*/
#define Point2D_GetX(this) ((this)->m_x)







/*
inline double Point2D::GetY() const
{
	return m_y;
}
*/
#define Point2D_GetY(this) ((this)->m_y)







/*
double Point2D::Distance(const Point2D& _other) const
{
	double dx = m_x - _other.m_x;
	double dy = m_y - _other.m_y;
	return sqrt(dx * dx + dy * dy);
}
*/
double Point2D_Distance(const Point2D* _this, const Point2D* _other)
{
	double dx = _this->m_x - _other->m_x;
	double dy = _this->m_y - _other->m_x;
	return sqrt(dx * dx + dy * dy);
}








/*
Point2D& Point2D::operator+=(const Point2D& _other)
{
	m_x += _other.m_x;
	m_y += _other.m_y;
	
	return *this;
}
*/
Point2D Point2D_operator_PlusEquals(Point2D* _this, const Point2D* _other)
{
	_this->m_x += _other->m_x;
	_this->m_y += _other->m_y;
	
	return *_this;
}






/*
Point2D& Point2D::operator*=(double _factor)
{
	m_x *= _factor;
	m_y *= _factor;
	
	return *this;
}
*/
Point2D Point2D_operator_MultEquals(Point2D* const _this, double _factor)
{
	_this->m_x *= _factor;
	_this->m_y *= _factor;
	
	return *_this;
}







/*
void pointless()
{
	Point2D p0;
	Point2D p1(0,10);
	printf("distance p0 --> p1 == %f\n", p0.Distance(p1));

	Point2D dxy(+4, -7);
	p1 += dxy;
	printf("%f, %f\n", p1.GetX(), p1.GetY());
	printf("now distance p0 --> p1 == %f\n", p0.Distance(p1));
}
*/

void pointless()
{
	Point2D p0;
	Point2D_CreatePoint2D_1(&p0);
	
	Point2D p1;
	Point2D_CreatePoint2D_3(&p1, 0, 10);
	printf("distance p0 --> p1 == %f\n", Point2D_Distance(&p0, &p1));

	Point2D dxy;
	Point2D_CreatePoint2D_3(&p1, +4, -7);
	Point2D_operator_PlusEquals(&p1, &dxy);
	
	printf("%f, %f\n", Point2D_GetX(&p1), Point2D_GetY(&p1));
	printf("now distance p0 --> p1 == %f\n", Point2D_Distance(&p0, &p1));
}



/*void pointless();*/







int main()
{
	pointless();
	return 0;
}













