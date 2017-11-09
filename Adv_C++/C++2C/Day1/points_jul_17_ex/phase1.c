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
typedef struct GLBL_Point2D
{
	double m_x;
	double m_y;
}GLBL_Point2D;



/*
Point2D::Point2D()
: m_x(0), m_y(0)
{
}
*/
void GLBL_Point2D_CreateGLBL_Point2D_1(GLBL_Point2D* const _this)
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
void GLBL_Point2D_CreateGLBL_Point2D_3(GLBL_Point2D* const _this, double _x, double _y)
{
	_this->m_x = _x;
	_this->m_y = _y;
	return;
}


void GLBL_Point2D_CreateGLBL_Point2D_2_GLBL_Point2D(GLBL_Point2D* const _this, const GLBL_Point2D* const _other)
{
	_this->m_x = _other->m_x;
	_this->m_y = _other->m_y;
	return;
}



/*
inline double Point2D::GetX() const
{
	return m_x;
}
*/
#define GLBL_Point2D_GetX(this) ((this)->m_x) //THIS IS NOT NEEDED. The relevant code should be placed directly in calling code







/*
inline double Point2D::GetY() const
{
	return m_y;
}
*/
#define GLBL_Point2D_GetY(this) ((this)->m_y) //THIS IS NOT NEEDED. The relevant code should be placed directly in calling code



/*
Generally insted of-
#define MAX 100
do-
private:
	static const int MAX = 100;
*/



/*
double Point2D::Distance(const Point2D& _other) const
{
	double dx = m_x - _other.m_x;
	double dy = m_y - _other.m_y;
	return sqrt(dx * dx + dy * dy);
}
*/
double GLBL_Point2D_Distance_const(const GLBL_Point2D* const _this, const GLBL_Point2D* const _other)
{
	double dx = _this->m_x - _other->m_x;
	double dy = _this->m_y - _other->m_y;
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
GLBL_Point2D* const GLBL_Point2D_operator_PlusEquals(GLBL_Point2D* const _this, const GLBL_Point2D* const _other)
{
	_this->m_x += _other->m_x;
	_this->m_y += _other->m_y;
	
	return _this;
}






/*
Point2D& Point2D::operator*=(double _factor)
{
	m_x *= _factor;
	m_y *= _factor;
	
	return *this;
}
*/
GLBL_Point2D* const GLBL_Point2D_operator_MultEquals(GLBL_Point2D* const _this, double _factor)
{
	_this->m_x *= _factor;
	_this->m_y *= _factor;
	
	return _this;
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
	GLBL_Point2D p0;
	GLBL_Point2D p1;
	GLBL_Point2D dxy;
	
	GLBL_Point2D_CreateGLBL_Point2D_1(&p0);
	GLBL_Point2D_CreateGLBL_Point2D_3(&p1, 0, 10);
	printf("distance p0 --> p1 == %f\n", GLBL_Point2D_Distance_const(&p0, &p1));

	
	GLBL_Point2D_CreateGLBL_Point2D_3(&dxy, +4, -7);
	GLBL_Point2D_operator_PlusEquals(&p1, &dxy);
	
	printf("%f, %f\n", GLBL_Point2D_GetX(&p1), GLBL_Point2D_GetY(&p1));
/*	printf("%f, %f\n", p1.m_x, p1.m_y);*/ // This is what compiler will do
	printf("now distance p0 --> p1 == %f\n", GLBL_Point2D_Distance_const(&p0, &p1));
}


//Phase 1 main
/*
int main()
{
	pointless();
	return 0;
}
*/

/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */

/*
class NamedPoint2D : public Point2D
{
public:
	NamedPoint2D(const char *_name = "origin");
	NamedPoint2D(double _x, double _y, const char *_name = "anonymous Point");
	NamedPoint2D(const Point2D& point, const char *_name = "anonymous Point");
	const char *GetName() const;

private:
	const char *m_name;	
};
*/
typedef struct GLBL_NamedPoint2D
{
	GLBL_Point2D m_glblPoint2D;
	const char* m_name;
}GLBL_NamedPoint2D;




/*
NamedPoint2D::NamedPoint2D(const char *_name)
: m_name(_name)
{
}
*/
void GLBL_NamedPoint2D_constCharP_5(GLBL_NamedPoint2D* const _this, const char* _name)
{
	m_name =_name;
}




/*
NamedPoint2D::NamedPoint2D(double _x, double _y, const char *_name)
: m_name(_name), Point2D(_x, _y)
{
}
*/
void GLBL_NamedPoint2D_dbl2_dbl2_constCharP_5(GLBL_NamedPoint2D* const _this, double _x, double _y, const char* _name)
{
	GLBL_Point2D_CreateGLBL_Point2D_3(&(_this->m_glblPoint2D), _x, _y);
	m_name =_name;
}




/*
NamedPoint2D::NamedPoint2D(const Point2D& _point, const char *_name)
: m_name(_name), Point2D(_point)
{
}
*/
void GLBL_NamedPoint2D_dbl2_dbl2_constCharP_5(GLBL_NamedPoint2D* const _this, const GLBL_Point2D* const _point, const char* _name)
{
	GLBL_Point2D_CreateGLBL_Point2D_2_GLBL_Point2D(&(_this->m_glblPoint2D), _point);
	m_name =_name;
}



/*
const char *NamedPoint2D::GetName() const
{
	return m_name;
}
*/
const char* GLBL_NamedPoint2D_7GetName_0(const GLBL_NamedPoint2D* const _this)
{
	return _this->m_name;
}





/*
class Rectangle
{
public:
	Rectangle(const GLBL_Point2D& _a, const GLBL_Point2D& _b, const char *_name = "anonymous Rectangle");

	const char *GetName() const;
	double CalcArea() const;

private:
	NamedPoint2D m_a;
	GLBL_Point2D m_b;
	static const int s_curvature = 1;	
};
*/
typedef struct Rectangle
{
	GLBL_NamedPoint2D m_a;
	GLBL_Point2D m_b;
	static const int s_curvature = 1;
}Rectangle;






/*
Rectangle::Rectangle(const GLBL_Point2D& _a, const GLBL_Point2D& _b, const char *_name)
: m_a(_a, _name), m_b(_b)
{
}
*/
void GLBL_Rectangle_3_constGLBL_Point2D_constGLBL_Point2D_constcharP(Rectangle* const _this,
																	 const GLBL_Point2D* const _a,
																	 const GLBL_Point2D* const _b,
																	 const char* _name)
{
	GLBL_NamedPoint2D_dbl2_dbl2_constCharP_5(_this, _a, _name);
	GLBL_Point2D_CreateGLBL_Point2D_2_GLBL_Point2D(_this, _b);
}																	 






/*
const char *Rectangle::GetName() const
{
	return m_a.GetName();
}
*/
const char* GLBL_Rectangle_GetName_0_const(const Rectangle* const _this)
{
	return _this->m_a.m_name;
}






/*
double Rectangle::CalcArea() const
{
	GLBL_Point2D p1(m_a.GetX(), m_b.GetY());
	double sideA = m_a.Distance(p1);
	double sideB = m_a.Distance(GLBL_Point2D(m_b.GetX(), m_a.GetY()));
	return sideA * sideB * s_curvature;
}
*/
double GLBL_Rectangle_CalcArea_0(const Rectangle* const _this)
{
	GLBL_Point2D p1;
	double sideA;
	double sideB;
	
	GLBL_Point2D_CreateGLBL_Point2D_3(_this->m_a.GetX(), _this->m_a.GetY())
}








/*
void dog()
{
	NamedPoint2D home(5,7, "home");
	GLBL_Point2D point(home);
	NamedPoint2D dog(point);

	dog *= 2;
	printf("Distance from %s to %s is %f\n", home.GetName(), dog.GetName(), home.Distance(dog));
}
*/







/*
void area()
{
	GLBL_Point2D p0;
	GLBL_Point2D p1(12,12);
	Rectangle r(p0, p1);
	
	printf("The area of %s is %f\n", r.GetName(), r.CalcArea());
	printf("rectangle size %zu", sizeof(r));
}
*/









int main()
{
	dog();
	area();
	return 0;
}












