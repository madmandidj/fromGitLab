#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*************
Mangled name strategy:
----------------------

Scope_NumOfChars_Name_type_#p_optionalKeyword_XX_optionalKeyWord...

Note: type = 'C' - constructor, 'F' - function, 'O' - operator
Note: #p = number of parameters (not including this) followed by char 'p'
Note: XX = First and Last characters of parameter type
*************/

/*#define PHASE (1)*/
#define PHASE (2)

/***** Phase 1 *****{{ */
#if PHASE >= 1


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
typedef struct AB_7_Point2D
{
	double m_x;
	double m_y;
}AB_7_Point2D;


/*********************************/
/*********************************/
/* COMPILER GENERATED COPY CTOR */
void AB_7_Point2D_C_1p_const_PD_ref(AB_7_Point2D* const _this, const AB_7_Point2D* const _other)
{
	_this->m_x = _other->m_x;
	_this->m_y = _other->m_y;
	return;
}
/*********************************/
/*********************************/


/*
Point2D::Point2D()
: m_x(0), m_y(0)
{
}
*/
void AB_7_Point2D_C_0p(AB_7_Point2D* const _this)
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
void AB_7_Point2D_C_2p_de_de(AB_7_Point2D* const _this, double _x, double _y)
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
/*TODO: directly replace in code where relevant


/*
inline double Point2D::GetY() const
{
	return m_y;
}
*/
/*TODO: directly replace in code where relevant


/*
double Point2D::Distance(const Point2D& _other) const
{
	double dx = m_x - _other.m_x;
	double dy = m_y - _other.m_y;
	return sqrt(dx * dx + dy * dy);
}
*/
double AB_7_Point2D_F_Distance_1p_const_PD_ref_const(const AB_7_Point2D* const _this, const AB_7_Point2D* const _other)
{
	double dx;
	double dy;
	dx = _this->m_x - _other->m_x;
	dy = _this->m_y - _other->m_y;
	
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
AB_7_Point2D* const AB_7_Point2D_O_pe_1p_const_PD_ref(AB_7_Point2D* const _this, const AB_7_Point2D* const _other)
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
AB_7_Point2D* const AB_7_Point2D_O_me_1p_de(AB_7_Point2D* const _this, double _factor)
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
void A_9_pointless_F_0p()
{
	AB_7_Point2D p0;
	AB_7_Point2D p1;
	AB_7_Point2D dxy;
	
	AB_7_Point2D_C_0p(&p0);
	AB_7_Point2D_C_2p_de_de(&p1, 0, 10);
	AB_7_Point2D_C_2p_de_de(&dxy, +4, -7);
	
	printf("distance p0 --> p1 == %f\n", AB_7_Point2D_F_Distance_1p_const_PD_ref_const(&p0, &p1));
	AB_7_Point2D_O_pe_1p_const_PD_ref(&p1, &dxy);
	printf("%f, %f\n", p1.m_x, p1.m_y);
	printf("now distance p0 --> p1 == %f\n", AB_7_Point2D_F_Distance_1p_const_PD_ref_const(&p0, &p1));
	
	return;
}

#endif
/* }} ***** Phase 1 *****/


/*----------------------------------------------------------------*/


/***** Phase 2 *****{{ */
#if PHASE >= 2

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
typedef struct AB_12_NamedPoint2D
{
	AB_7_Point2D 	m_Point2D;
	const char* 	m_name;
}AB_12_NamedPoint2D;


/*
NamedPoint2D::NamedPoint2D(const char *_name)
: m_name(_name)
{
}
*/
void AB_12_NamedPoint2D_C_1p_const_cr_ptr(AB_12_NamedPoint2D* const _this, const char* _name)
{
	if (NULL == _name)
	{
		_this->m_name = "origin";
	}
	else
	{
		_this->m_name = _name;
	}
	
	return;
}


/*
NamedPoint2D::NamedPoint2D(double _x, double _y, const char *_name)
: m_name(_name), Point2D(_x, _y)
{
}
*/
void AB_12_NamedPoint2D_C_3p_de_de_const_cr_ptr(AB_12_NamedPoint2D* const _this, double _x, double _y, const char* _name)
{
	if (NULL == _name)
	{
		_this->m_name = "anonymous Point";
	}
	else
	{
		_this->m_name = _name;
	}
	
	AB_7_Point2D_C_2p_de_de(&(_this->m_Point2D), _x, _y);

	return;
}


/*
NamedPoint2D::NamedPoint2D(const Point2D& _point, const char *_name)
: m_name(_name), Point2D(_point)
{
}
*/
void AB_12_NamedPoint2D_C_2p_const_PD_ref_const_cr_ptr(AB_12_NamedPoint2D* const _this, const AB_7_Point2D* const _point2D, const char* _name)
{
	if (NULL == _name)
	{
		_this->m_name = "anonymous Point";
	}
	else
	{
		_this->m_name = _name;
	}
	
	AB_7_Point2D_C_2p_de_de(&(_this->m_Point2D), _point2D->m_x, _point2D->m_y);

	return;
}


/*
const char *NamedPoint2D::GetName() const
{
	return m_name;
}
*/
const char* AB_12_NamedPoint2D_F_GetName_0p_const(const AB_12_NamedPoint2D* const _this)
{
	return _this->m_name;
}


/*----------------------------------------------------------------*/
/*
class Rectangle
{
public:
	Rectangle(const Point2D& _a, const Point2D& _b, const char *_name = "anonymous Rectangle");

	const char *GetName() const;
	double CalcArea() const;

private:
	NamedPoint2D m_a;
	Point2D m_b;
	static const int s_curvature = 1;	
};
*/
typedef struct AB_9_Rectangle
{
	AB_12_NamedPoint2D 	m_NamedPoint2D;
	AB_7_Point2D			m_Point2D;
}AB_9_Rectangle;

static const int AB_9_Rectangle_const_it_11_s_curvature = 1;


/*
Rectangle::Rectangle(const Point2D& _a, const Point2D& _b, const char *_name)
: m_a(_a, _name), m_b(_b)
{
}
*/
void AB_9_Rectangle_C_3p_const_PD_ref_const_PD_ref_const_cr_ptr(AB_9_Rectangle* const _this, const AB_7_Point2D* const _PD1, const AB_7_Point2D* const _PD2, const char* _name)
{
	if (NULL == _name)
	{
		_this->m_NamedPoint2D.m_name = "anonymous Rectangle";
	}
	else
	{
		_this->m_NamedPoint2D.m_name = _name;
	}
	AB_12_NamedPoint2D_C_2p_const_PD_ref_const_cr_ptr(&(_this->m_NamedPoint2D), _PD1, _this->m_NamedPoint2D.m_name);
	AB_7_Point2D_C_1p_const_PD_ref(&(_this->m_Point2D), _PD2);
	
	return;
}


/*
const char *Rectangle::GetName() const
{
	return m_a.GetName();
}
*/
const char* AB_9_Rectangle_F_GetName_0p_const(AB_9_Rectangle* const _this)
{
	return _this->m_NamedPoint2D.m_name;
}


/*
double Rectangle::CalcArea() const
{
	Point2D p1(m_a.GetX(), m_b.GetY());
	double sideA = m_a.Distance(p1);
	double sideB = m_a.Distance(Point2D(m_b.GetX(), m_a.GetY()));
	return sideA * sideB * s_curvature;
}
*/
double AB_9_Rectangle_F_CalcArea_0p_const(AB_9_Rectangle* const _this)
{
	AB_7_Point2D p1;
	double sideA;
	double sideB;
	AB_7_Point2D temp_AB_7_Point2D_1;
	
	AB_7_Point2D_C_2p_de_de(&p1, _this->m_NamedPoint2D.m_Point2D.m_x, _this->m_Point2D.m_y);
	sideA = AB_7_Point2D_F_Distance_1p_const_PD_ref_const((AB_7_Point2D*)(&_this->m_NamedPoint2D), &p1);
	AB_7_Point2D_C_2p_de_de(&temp_AB_7_Point2D_1, _this->m_Point2D.m_x, _this->m_NamedPoint2D.m_Point2D.m_y);
	sideB = AB_7_Point2D_F_Distance_1p_const_PD_ref_const((AB_7_Point2D*)(&_this->m_NamedPoint2D), &temp_AB_7_Point2D_1);

	return sideA * sideB * AB_9_Rectangle_const_it_11_s_curvature;
}


/*----------------------------------------------------------------*/
/*
void dog()
{
	NamedPoint2D home(5,7, "home");
	Point2D point(home);
	NamedPoint2D dog(point);

	dog *= 2;
	printf("Distance from %s to %s is %f\n", home.GetName(), dog.GetName(), home.Distance(dog));
}
*/
void A_3_dog_F_0p()
{
	AB_12_NamedPoint2D home;
	AB_7_Point2D point;
	AB_12_NamedPoint2D dog;
	
	AB_12_NamedPoint2D_C_3p_de_de_const_cr_ptr(&home, 5, 7, "home");
	AB_7_Point2D_C_1p_const_PD_ref(&point, (AB_7_Point2D*)(&home));
	AB_12_NamedPoint2D_C_2p_const_PD_ref_const_cr_ptr(&dog, &point, NULL);
	AB_7_Point2D_O_me_1p_de((AB_7_Point2D*)(&dog),2);
	printf("Distance from %s to %s is %f\n", AB_12_NamedPoint2D_F_GetName_0p_const(&home), 
									AB_12_NamedPoint2D_F_GetName_0p_const(&dog), 
									AB_7_Point2D_F_Distance_1p_const_PD_ref_const((AB_7_Point2D*)(&home), (AB_7_Point2D*)(&dog)));
									
	return;
}


/*
void area()
{
	Point2D p0;
	Point2D p1(12,12);
	Rectangle r(p0, p1);
	
	printf("The area of %s is %f\n", r.GetName(), r.CalcArea());
	printf("rectangle size %zu", sizeof(r));
}
*/
void A_4_area_F_0p()
{
	AB_7_Point2D p0;
	AB_7_Point2D p1;
	AB_9_Rectangle r;
	
	AB_7_Point2D_C_0p(&p0);
	AB_7_Point2D_C_2p_de_de(&p1, 12, 12);
	AB_9_Rectangle_C_3p_const_PD_ref_const_PD_ref_const_cr_ptr(&r, &p0, &p1, NULL);
	
	printf("The area of %s is %f\n", r.m_NamedPoint2D.m_name, AB_9_Rectangle_F_CalcArea_0p_const(&r));
	printf("rectangle size %zu", sizeof(r));
	
	return;
}


#endif
/* }} ***** Phase 2 *****/
/*----------------------------------------------------------------*/
/*
int main()
{
#if PHASE >= 1
	pointless();
#endif

#if PHASE >= 2
	dog();
	area();
#endif

	return 0;
}
*/


int main()
{
#if PHASE >= 1
	A_9_pointless_F_0p();
#endif

#if PHASE >= 2
	A_3_dog_F_0p();
	A_4_area_F_0p();
#endif

	return 0;
}






























