#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*#define PHASE (1)*/
#define PHASE (2)


/*
Name mangling strategy:
-----------------------
Scope, NumOfChars, Name, (C)tor / (F)unction / (O)perator, NumOfParams, ParamType(first and last char),

*/

typedef struct AB7_Point2D
{
	double m_x;
	double m_y;
}AB7_Point2D;

typedef struct AB12_NamedPoint2D
{
	AB7_Point2D 	m_Point2D;
	const char* m_name;
}AB12_NamedPoint2D;



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
typedef struct AB9Rectangle
{
	AB12_NamedPoint2D 	m_NamedPoint2D;
	AB7_Point2D			m_Point2D;
}Rectangle;


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
/*typedef struct AB7Point2D*/
/*{*/
/*	double m_x;*/
/*	double m_y;*/
/*}AB7Point2D;*/

/*
Point2D::Point2D()
: m_x(0), m_y(0)
{
}
*/
void AB7_Point2D_C_0p(AB7_Point2D* const _this)
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
void AB7_Point2D_C_2p_de_de(AB7_Point2D* const _this, double _x, double _y)
{
	_this->m_x = _x;
	_this->m_y = _y;
	return;
}

void AB7_Point2D_C_1p_const_ND_ref(AB7_Point2D* const _this, const AB12_NamedPoint2D* const _ND)
{
	_this->m_x = _ND->m_Point2D.m_x;
	_this->m_y = _ND->m_Point2D.m_y;
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
double AB7_Point2D_F_Distance_1p_const_PD_ref_const(const AB7_Point2D* const _this, const AB7_Point2D* const _other)
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
AB7_Point2D* const AB7_Point2D_O_pe_1p_const_PD_ref(AB7_Point2D* const _this, const AB7_Point2D* const _other)
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
AB7_Point2D* const AB7_Point2D_O_me_1p_de(AB7_Point2D* const _this, double _factor)
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
void A9_pointless_F_0p()
{
	AB7_Point2D p0;
	AB7_Point2D p1;
	AB7_Point2D dxy;
	
	AB7_Point2D_C_0p(&p0);
	AB7_Point2D_C_2p_de_de(&p1, 0, 10);
	AB7_Point2D_C_2p_de_de(&dxy, +4, -7);
	
	printf("distance p0 --> p1 == %f\n", AB7_Point2D_F_Distance_1p_const_PD_ref_const(&p0, &p1));
	AB7_Point2D_O_pe_1p_const_PD_ref(&p1, &dxy);
	printf("%f, %f\n", p1.m_x, p1.m_y);
	printf("now distance p0 --> p1 == %f\n", AB7_Point2D_F_Distance_1p_const_PD_ref_const(&p0, &p1));
	
	return;
}

#endif
/* }} ***** Phase 1 *****/

/*----------------------------------------------------------------*/

/***** Phase 2 *****{{ */
#if PHASE == 2

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

/*typedef struct AB12NamedPoint2D*/
/*{*/
/*	AB7Point2D 	m_Point2D;*/
/*	const char* m_name;*/
/*}AB12NamedPoint2D;*/

/*Default CTOR*/
void AB12_NamedPoint2D_C_0p(AB12_NamedPoint2D* const _this)
{
	_this->m_name = "";

	return;
}






/*
NamedPoint2D::NamedPoint2D(const char *_name)
: m_name(_name)
{
}
*/
void AB12_NamedPoint2D_C_1p_const_cr_ptr(AB12_NamedPoint2D* const _this, const char* _name)
{
	_this->m_name = _name;

	return;
}





/*
NamedPoint2D::NamedPoint2D(double _x, double _y, const char *_name)
: m_name(_name), Point2D(_x, _y)
{
}
*/
void AB12_NamedPoint2D_C_3p_de_de_const_cr_ptr(AB12_NamedPoint2D* const _this, double _x, double _y, const char* _name)
{
	_this->m_name = _name;
	
	AB7_Point2D_C_2p_de_de(&(_this->m_Point2D), _x, _y);

	return;
}





/*
NamedPoint2D::NamedPoint2D(const Point2D& _point, const char *_name)
: m_name(_name), Point2D(_point)
{
}
*/
void AB12_NamedPoint2D_C_2p_const_PD_ref_const_cr_ptr(AB12_NamedPoint2D* const _this, const AB7_Point2D* const _point2D, const char* _name)
{
	_this->m_name = _name;
	
	AB7_Point2D_C_2p_de_de(&(_this->m_Point2D), _point2D->m_x, _point2D->m_y);

	return;
}

void AB12_NamedPoint2D_C_1p_const_PD_ref(AB12_NamedPoint2D* const _this, const AB7_Point2D* const _point2D)
{
	_this->m_name = "anonymous point";
	
	AB7_Point2D_C_2p_de_de(&(_this->m_Point2D), _point2D->m_x, _point2D->m_y);

	return;
}





/*
const char *NamedPoint2D::GetName() const
{
	return m_name;
}
*/

const char* AB12_NamedPoint2D_F_GetName_0p_const(const AB12_NamedPoint2D* const _this)
{
	return _this->m_name;
}


AB12_NamedPoint2D* const AB12_NamedPoint2D_O_me_1p_de(AB12_NamedPoint2D* const _this, double _factor)
{
	_this->m_Point2D.m_x *= _factor;
	_this->m_Point2D.m_y *= _factor;
	
	return _this;
}





double AB12_NamedPoint2D_F_Distance_1p_const_PD_ref_const(const AB12_NamedPoint2D* const _this, const AB12_NamedPoint2D* const _other)
{
/*	double dx;*/
/*	double dy;*/
/*	*/
/*	dx = _this->m_x - _other->m_x;*/
/*	dy = _this->m_y - _other->m_y;*/
	return AB7_Point2D_F_Distance_1p_const_PD_ref_const(&(_this->m_Point2D), &(_other->m_Point2D));
}


/*----------------------------------------------------------------*/
/*





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





/*
Rectangle::Rectangle(const Point2D& _a, const Point2D& _b, const char *_name)
: m_a(_a, _name), m_b(_b)
{
}
*/


/*
const char *Rectangle::GetName() const
{
	return m_a.GetName();
}
*/



/*
double Rectangle::CalcArea() const
{
	Point2D p1(m_a.GetX(), m_b.GetY());
	double sideA = m_a.Distance(p1);
	double sideB = m_a.Distance(Point2D(m_b.GetX(), m_a.GetY()));
	return sideA * sideB * s_curvature;
}
*/






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

void A3_dog_F_0p()
{
	AB12_NamedPoint2D home;
	AB7_Point2D point;
	AB12_NamedPoint2D dog;
	
	AB12_NamedPoint2D_C_3p_de_de_const_cr_ptr(&home, 5, 7, "home");
	AB7_Point2D_C_1p_const_ND_ref(&point, &home);
	AB12_NamedPoint2D_C_1p_const_PD_ref(&dog, &point);
	AB12_NamedPoint2D_O_me_1p_de(&dog, 2);
	printf("Distance from %s to %s is %f\n", AB12_NamedPoint2D_F_GetName_0p_const(&home), 
									AB12_NamedPoint2D_F_GetName_0p_const(&dog), 
									AB12_NamedPoint2D_F_Distance_1p_const_PD_ref_const(&home, &dog));
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
	A9_pointless_F_0p();
#endif

#if PHASE >= 2
	A3_dog_F_0p();
/*	area();*/
#endif

	return 0;
}



