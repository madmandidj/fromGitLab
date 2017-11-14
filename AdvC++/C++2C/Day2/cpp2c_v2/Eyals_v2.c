#include <stdio.h>
#include <stdlib.h>

typedef void (*VirtualFunc)(void);


/*
struct Color {
	enum ColorEnum { RED, GREEN, DEFAULT };
	static void setColor(ColorEnum color){		
		static const char * pallete[] = { "\x1B[31m", "\x1B[32m", "\033[0m" };
		std::puts(pallete[color]);
	}
};
*/
typedef enum ColorEnum
{
 RED,
 GREEN,
 DEFAULT
}ColorEnum;

static void setColor(ColorEnum _color)
{
	static const char* pallete[] = {"\x1B[31m", "\x1B[32m", "\033[0m"};
	puts(pallete[_color]);
}











/*
class Scaleable {
public:
	virtual ~Scaleable() { }	
	virtual void scale(double) = 0;
};
*/
typedef struct Scaleable
{
	VirtualFunc* 	m_vTable;
}Scaleable;


void ABC_10_Scaleable_C_0p(Scaleable* const _this); /* COMPILER GENERATED DEFAULT CTOR */
void ABC_10_Scaleable_D_0p(Scaleable* const _this);
void ABC_10_Scaleable_F_5_scale_1p_de(Scaleable* const _this, double _dbl);

VirtualFunc scal_virtT[2] = {(VirtualFunc)ABC_10_Scaleable_D_0p, 
								(VirtualFunc)ABC_10_Scaleable_F_5_scale_1p_de}; 


void ABC_10_Scaleable_C_0p(Scaleable* const _this) /* COMPILER GENERATED DEFAULT CTOR */
{
	_this->m_vTable = scal_virtT;
	
	return;
}

void ABC_10_Scaleable_D_0p(Scaleable* const _this)  /* TODO: INLINE? */
{
	_this->m_vTable = scal_virtT;
	
	return;
}

void ABC_10_Scaleable_F_5_scale_1p_de(Scaleable* const _this, double _dbl)
{
	 /* This call should terminate program because its pure virtual with no implementation */
	 return;
}













/*
class Shape : public Scaleable {
public:
	Shape() : m_id(++NumOfShapes) {
		std::printf("Shape::Shape() - %d\n", m_id); 
	}

	~Shape() {
		draw();
		--NumOfShapes; 
		std::printf("Shape::~Shape - %d\n", m_id);
	}

	Shape(const Shape& other) : m_id(++NumOfShapes) {
		std::printf("Shape::Shape(Shape&) - %d from - %d\n", m_id, other.m_id);
	}

	virtual void draw() const {
		std::printf("Shape::draw() - %d\n", m_id);		
	}
	
	virtual void draw(Color::ColorEnum c) const {
		std::printf("Shape::draw(c) - %d\n", m_id);
		Color::setColor(c);
		draw();
		Color::setColor(Color::DEFAULT);
	}
	
	virtual void scale(double f = 1) { 
		std::printf("Shape::scale(%f)\n", f);
	}
	virtual double area() const { return -1; }
	static void printInventory() {
		std::printf("Shape::printInventory - %d\n", NumOfShapes);
	}

private:
	static int NumOfShapes;
	Shape& operator=(const Shape &); // disabled, no implementation provided

protected:
	 int m_id;
};
*/


typedef struct Shape
{
	Scaleable 		m_scaleable;
	int				m_id;
}Shape;

static int AB_5_Shape_NumOfShapes = 0;

void AB_5_Shape_C_0p(Shape* const _this);
void AB_5_Shape_C_1p_const_Se_const_ptr(Shape* const _this, const Shape* const _other);
void AB_5_Shape_F_5_scale_1p_de(Shape* const _this, double _f); /*virtual*/
void AB_5_Shape_D_0p(Shape* const _this); /* virtual */
void AB_5_Shape_F_4_draw_0p_const(const Shape* const _this); /*virtual*/
void AB_5_Shape_F_4_draw_1p_Cm_const(const Shape* const _this, ColorEnum _c); /*virtual*/ 
double AB_5_Shape_F_4_area_const(const Shape* const _this); /*virtual*/
static void AB_5_Shape_SF_printInventory();  

VirtualFunc shap_virtT[5] = {(VirtualFunc)AB_5_Shape_D_0p, 
								(VirtualFunc)AB_5_Shape_F_5_scale_1p_de, 
								(VirtualFunc)AB_5_Shape_F_4_draw_0p_const, 
								(VirtualFunc)AB_5_Shape_F_4_draw_1p_Cm_const, 
								(VirtualFunc)AB_5_Shape_F_4_area_const}; 

/*
Shape() : m_id(++NumOfShapes) 
{
		std::printf("Shape::Shape() - %d\n", m_id); 
}
*/
void AB_5_Shape_C_0p(Shape* const _this)
{
	
	ABC_10_Scaleable_C_0p(&(_this->m_scaleable));		/* Calls constructor of base */
	
	_this->m_scaleable.m_vTable = shap_virtT;			/* set derived virtual pointer */
	
	_this->m_id = ++AB_5_Shape_NumOfShapes;
	
	printf("Shape::Shape() - %d\n", _this->m_id);
	
	return;
}


/*
~Shape() 
{
	draw();
	--NumOfShapes; 
	std::printf("Shape::~Shape - %d\n", m_id);
}
*/
void AB_5_Shape_D_0p(Shape* const _this)
{
	_this->m_scaleable.m_vTable = shap_virtT;	
	
/*	AB_5_Shape_F_4_draw_0p_const(_this);*/
	((void(*)(const Shape* const))_this->m_scaleable.m_vTable[2])(_this);
	
	--AB_5_Shape_NumOfShapes;
	
	printf("Shape::~Shape - %d\n", _this->m_id);
	
	ABC_10_Scaleable_D_0p(&(_this->m_scaleable));  /* TODO: INLINE  (comment out)*/
	
	return;
}


/*
Shape(const Shape& other) : m_id(++NumOfShapes) 
{
	std::printf("Shape::Shape(Shape&) - %d from - %d\n", m_id, other.m_id);
}
*/
void AB_5_Shape_C_1p_const_Se_const_ptr(Shape* const _this, const Shape* const _other)
{
	_this->m_scaleable = _other->m_scaleable;
	
	_this->m_id = ++AB_5_Shape_NumOfShapes;
	
	printf("Shape::Shape(Shape&) - %d from - %d\n", _this->m_id, _other->m_id);
	
	return;
}


/*
virtual void draw() const 
{
	std::printf("Shape::draw() - %d\n", m_id);		
}
*/
void AB_5_Shape_F_4_draw_0p_const(const Shape* const _this)
{
	printf("Shape::draw() - %d\n", _this->m_id);
	
	return;
}


/*
virtual void draw(Color::ColorEnum c) const 
{
	std::printf("Shape::draw(c) - %d\n", m_id);
	Color::setColor(c);
	draw();
	Color::setColor(Color::DEFAULT);
}
*/
void AB_5_Shape_F_4_draw_1p_Cm_const(const Shape* const _this, ColorEnum _c)
{
	printf("Shape::draw(c) - %d\n", _this->m_id);
	
	setColor(_c);
	
/*	((void(*)(const Shape* const))_this->m_scaleable.m_vTable[1])(_this);*/
	((void(*)(const Shape* const))_this->m_scaleable.m_vTable[2])(_this);
	
	setColor(DEFAULT);
	
	return;
}


/*
virtual void scale(double f = 1) 
{ 
	std::printf("Shape::scale(%f)\n", f);
}
*/
void AB_5_Shape_F_5_scale_1p_de(Shape* const _this, double _f)
{
	printf("Shape::scale(%f)\n", _f);
	
	return;
}


/*
virtual double area() const 
{ 
	return -1; 
}
*/
double AB_5_Shape_F_4_area_const(const Shape* const _this)
{
	return -1;
}


/*
static void printInventory() 
{
	std::printf("Shape::printInventory - %d\n", NumOfShapes);
}
*/
static void AB_5_Shape_SF_printInventory()
{
	printf("Shape::printInventory - %d\n", AB_5_Shape_NumOfShapes);
	return;
}

















/*
class Circle : public Shape {	
public:
	Circle() : m_radius(1) { 
		std::printf("Circle::Circle() - %d, r:%f\n", m_id, m_radius); 
	}

	Circle(double r) : m_radius(r) { 
		std::printf("Circle::Circle(double) - %d, r:%f\n", m_id, m_radius); 
	}

	Circle(const Circle& other)
	: Shape(other), m_radius(other.m_radius) { 
		std::printf("Circle::Circle(Circle&) - %d, r:%f\n", m_id, m_radius);
	}

	~Circle() { 
		std::printf("Circle::~Circle() - %d, r:%f\n", m_id, m_radius); 
	}

	void draw() const { 
		std::printf("Circle::draw()  - %d, r:%f\n", m_id, m_radius);
	}

	void scale(double f = 2) {
		std::printf("Circle::scale(%f)\n", f);
		m_radius *= f;
	}
    
	double area() const {
		return m_radius * m_radius * 3.1415;	
	}

	double radius() const { 
		std::printf("Circle::draw()  - %d, r:%f\n", m_id, m_radius);
		return m_radius;
	}

private:
	double m_radius;
};
*/

typedef struct Circle
{
	Shape	m_shape;
	double	m_radius;
}Circle;

void AB_6_Circle_C_0p(Circle* const _this);
void AB_6_Circle_C_1p_de(Circle* const _this, double _r);
void AB_6_Circle_C_1p_const_Ce_ref(Circle* const _this, const Circle* const _other);
void AB_6_Circle_D_0p(Circle* const _this); /* virtual */
void AB_6_Circle_F_5_scale_1p_de(Circle* const _this, double _f); /* virtual */
void AB_6_Circle_F_4_draw_0p_const(const Circle* const _this); /* virtual */
double AB_6_Circle_F_4_area_0p_const(const Circle* const _this); /* virtual */
double AB_6_Circle_F_6_radius_0p_const(const Circle* const _this); /* virtual */

VirtualFunc circ_virtT[5] = {(VirtualFunc)AB_6_Circle_D_0p, 
								(VirtualFunc)AB_6_Circle_F_5_scale_1p_de, 
								(VirtualFunc)AB_6_Circle_F_4_draw_0p_const, 
								(VirtualFunc)AB_5_Shape_F_4_draw_1p_Cm_const, 
								(VirtualFunc)AB_6_Circle_F_4_area_0p_const}; 

/*
Circle() : m_radius(1) { 
	std::printf("Circle::Circle() - %d, r:%f\n", m_id, m_radius); 
}
*/
void AB_6_Circle_C_0p(Circle* const _this)
{
	AB_5_Shape_C_0p(&(_this->m_shape));					/* Calls constructor of base */
	
	_this->m_shape.m_scaleable.m_vTable = circ_virtT;	/* set derived virtual pointer */
	
	_this->m_radius = 1;
	
	printf("Circle::Circle() - %d, r:%f\n", _this->m_shape.m_id, _this->m_radius);
	
	return;
}


/*
Circle(double r) : m_radius(r) { 
	std::printf("Circle::Circle(double) - %d, r:%f\n", m_id, m_radius); 
}
*/
void AB_6_Circle_C_1p_de(Circle* const _this, double _r)
{
	AB_5_Shape_C_0p(&(_this->m_shape));					/* Calls constructor of base */
	
	_this->m_shape.m_scaleable.m_vTable = circ_virtT;	/* set derived virtual pointer */
	
	_this->m_radius = _r;
	
	printf("Circle::Circle(double) - %d, r:%f\n", _this->m_shape.m_id, _this->m_radius);
	
	return;
}



/*
Circle(const Circle& other)
: Shape(other), m_radius(other.m_radius) { 
	std::printf("Circle::Circle(Circle&) - %d, r:%f\n", m_id, m_radius);
}
*/
void AB_6_Circle_C_1p_const_Ce_ref(Circle* const _this, const Circle* const _other)
{	
/*	_this->m_shape = _other->m_shape;*/
	
	AB_5_Shape_C_1p_const_Se_const_ptr(&(_this->m_shape), &(_other->m_shape));
	
	_this->m_shape.m_scaleable.m_vTable = circ_virtT;

	_this->m_radius = _other->m_radius;
	
	printf("Circle::Circle(Circle&) - %d, r:%f\n", _this->m_shape.m_id, _this->m_radius);
	
	return;
}


/*
~Circle() { 
	std::printf("Circle::~Circle() - %d, r:%f\n", m_id, m_radius); 
}
*/
void AB_6_Circle_D_0p(Circle* const _this)
{
	_this->m_shape.m_scaleable.m_vTable = circ_virtT;
	
	printf("Circle::~Circle() - %d, r:%f\n", _this->m_shape.m_id, _this->m_radius);
	
	AB_5_Shape_D_0p(&(_this->m_shape));
}


/*
void draw() const { 
	std::printf("Circle::draw()  - %d, r:%f\n", m_id, m_radius);
}
*/
void AB_6_Circle_F_4_draw_0p_const(const Circle* const _this)
{
	printf("Circle::draw()  - %d, r:%f\n", _this->m_shape.m_id, _this->m_radius);

	return;
}


/*
void scale(double f = 2) {
	std::printf("Circle::scale(%f)\n", f);
	m_radius *= f;
}
*/
void AB_6_Circle_F_5_scale_1p_de(Circle* const _this, double _f)
{
	printf("Circle::scale(%f)\n", _f);
	
	_this->m_radius *= _f;
	
	return;
}


/*
double area() const {
	return m_radius * m_radius * 3.1415;	
}
*/
double AB_6_Circle_F_4_area_0p_const(const Circle* const _this)
{
	return _this->m_radius * _this->m_radius * 3.1415;
}


/*
double radius() const { 
	std::printf("Circle::draw()  - %d, r:%f\n", m_id, m_radius);
	return m_radius;
}
*/
double AB_6_Circle_F_6_radius_0p_const(const Circle* const _this)
{
	printf("Circle::draw()  - %d, r:%f\n", _this->m_shape.m_id, _this->m_radius);

	return _this->m_radius;
}





















/*
class Rectangle: public Shape {
public:
	Rectangle() : m_a(1), m_b(1) { 
		std::printf("Rectangle::Rectangle() - %d, [%d, %d]\n", m_id, m_a, m_b);
	}

	Rectangle(int a) : m_a(a), m_b(a) { 
		std::printf("Rectangle::Rectangle(int) - %d, [%d, %d]\n", m_id, m_a, m_b);
	}

	Rectangle(int a, int b) : m_a(a), m_b(b) { 
		std::printf("Rectangle::Rectangle(int, int) - %d, [%d, %d]\n", m_id, m_a, m_b);
	}
	
	Rectangle(const Rectangle &other ) 
	: m_a(other.m_a), m_b(other.m_b), Shape(other) { 
		std::printf("Rectangle::Rectangle(Rectangle&) - %d, a:%d/%d\n", m_id, m_a, m_b);
	}
	
	~Rectangle() { 
		std::printf("Rectangle::~Rectangle() - %d, [%d, %d]\n", m_id, m_a, m_b);
	}

	void draw() const { 
		std::printf("Rectangle::draw()  - %d, [%d, %d]\n", m_id, m_a, m_b);
	}

    void draw(Color::ColorEnum c) const {
		std::printf("Rectangle::draw(%d)  - %d, [%d, %d]\n", c, m_id, m_a, m_b);
	}

	void scale(double f = 4){
		std::printf("Rectangle::scale(%f)\n", f);
		m_a *= f;
		m_b *= f;
	}

	double area() const {
		return m_a * m_b;
	}

private:
	int m_a, m_b;
};
*/
typedef struct Rectangle
{
	Shape	m_shape;
	int		m_a;
	int		m_b;
}Rectangle;

void AB_9_Rectangle_C_0p(Rectangle* const _this);
void AB_9_Rectangle_C_1p_it(Rectangle* const _this, int _a);
void AB_9_Rectangle_C_2p_it_it(Rectangle* const _this, int _a, int _b);
void AB_9_Rectangle_C_1p_const_Re_ref(Rectangle* const _this, const Rectangle* const _other);
void AB_9_Rectangle_D_0p(Rectangle* const _this); /* virtual */
void AB_9_Rectangle_F_4_draw_0p_const(const Rectangle* const _this); /* virtual */
void AB_9_Rectangle_F_4_draw_1p_Re_const(const Rectangle* const _this, ColorEnum _c); /* virtual */
void AB_9_Rectangle_F_5_scale_1p_de(Rectangle* const _this, double _f); /* virtual */
double AB_9_Rectangle_F_4_area_0p_const(const Rectangle* const _this); /* virtual */

VirtualFunc rect_virtT[5] = {(VirtualFunc)AB_9_Rectangle_D_0p, 
								(VirtualFunc)AB_9_Rectangle_F_5_scale_1p_de, 
								(VirtualFunc)AB_9_Rectangle_F_4_draw_0p_const, 
								(VirtualFunc)AB_9_Rectangle_F_4_draw_1p_Re_const, 
								(VirtualFunc)AB_9_Rectangle_F_4_area_0p_const};

/*
Rectangle() : m_a(1), m_b(1) { 
	std::printf("Rectangle::Rectangle() - %d, [%d, %d]\n", m_id, m_a, m_b);
}
*/
void AB_9_Rectangle_C_0p(Rectangle* const _this)
{
	AB_5_Shape_C_0p(&(_this->m_shape));					/* Calls constructor of base */
	
	_this->m_shape.m_scaleable.m_vTable = rect_virtT;	/* set derived virtual pointer */
	
	_this->m_a = 1;
	
	_this->m_b = 1;
	
	printf("Rectangle::Rectangle() - %d, [%d, %d]\n", _this->m_shape.m_id, _this->m_a, _this->m_b);
	
	return;
}


/*
Rectangle(int a) : m_a(a), m_b(a) { 
	std::printf("Rectangle::Rectangle(int) - %d, [%d, %d]\n", m_id, m_a, m_b);
}
*/
void AB_9_Rectangle_C_1p_it(Rectangle* const _this, int _a)
{
	AB_5_Shape_C_0p(&(_this->m_shape));					/* Calls constructor of base */
	
	_this->m_shape.m_scaleable.m_vTable = rect_virtT;	/* set derived virtual pointer */
	
	_this->m_a = _a;
	
	_this->m_b = _a;
	
	printf("Rectangle::Rectangle(int) - %d, [%d, %d]\n", _this->m_shape.m_id, _this->m_a, _this->m_b);
	
	return;
}

/*
Rectangle(int a, int b) : m_a(a), m_b(b) { 
	std::printf("Rectangle::Rectangle(int, int) - %d, [%d, %d]\n", m_id, m_a, m_b);
}
*/
void AB_9_Rectangle_C_2p_it_it(Rectangle* const _this, int _a, int _b)
{
	AB_5_Shape_C_0p(&(_this->m_shape));					/* Calls constructor of base */
	
	_this->m_shape.m_scaleable.m_vTable = rect_virtT;	/* set derived virtual pointer */
	
	_this->m_a = _a;
	
	_this->m_b = _b;
	
	printf("Rectangle::Rectangle(int, int) - %d, [%d, %d]\n", _this->m_shape.m_id, _this->m_a, _this->m_b);
	
	return;
}


/*
Rectangle(const Rectangle &other ) 
: m_a(other.m_a), m_b(other.m_b), Shape(other) { 
	std::printf("Rectangle::Rectangle(Rectangle&) - %d, a:%d/%d\n", m_id, m_a, m_b);
}
*/
void AB_9_Rectangle_C_1p_const_Re_ref(Rectangle* const _this, const Rectangle* const _other)
{
	
/*	_this->m_shape = _other->m_shape;*/
	AB_5_Shape_C_1p_const_Se_const_ptr(&(_this->m_shape), &(_other->m_shape));
	
	_this->m_shape.m_scaleable.m_vTable = rect_virtT;	

	_this->m_a = _other->m_a;
	
	_this->m_b = _other->m_b;
	
	return;
}

/*
~Rectangle() { 
	std::printf("Rectangle::~Rectangle() - %d, [%d, %d]\n", m_id, m_a, m_b);
}
*/
void AB_9_Rectangle_D_0p(Rectangle* const _this)
{
	_this->m_shape.m_scaleable.m_vTable = rect_virtT;
	
	printf("Rectangle::~Rectangle() - %d, [%d, %d]\n", _this->m_shape.m_id, _this->m_a, _this->m_b);
	
	AB_5_Shape_D_0p(&(_this->m_shape));

	return;
}

/*
void draw() const { 
	std::printf("Rectangle::draw()  - %d, [%d, %d]\n", m_id, m_a, m_b);
}
*/
void AB_9_Rectangle_F_4_draw_0p_const(const Rectangle* const _this)
{
	printf("Rectangle::draw()  - %d, [%d, %d]\n", _this->m_shape.m_id, _this->m_a, _this->m_b);
	
	return;
}

/*
void draw(Color::ColorEnum c) const {
	std::printf("Rectangle::draw(%d)  - %d, [%d, %d]\n", c, m_id, m_a, m_b);
}
*/
void AB_9_Rectangle_F_4_draw_1p_Re_const(const Rectangle* const _this, ColorEnum _c)
{
	printf("Rectangle::draw(%d)  - %d, [%d, %d]\n", _c, _this->m_shape.m_id, _this->m_a, _this->m_b);
	
	return;
}

/*
void scale(double f = 4){
	std::printf("Rectangle::scale(%f)\n", f);
	m_a *= f;
	m_b *= f;
}
*/
void AB_9_Rectangle_F_5_scale_1p_de(Rectangle* const _this, double _f)
{
	printf("Rectangle::scale(%f)\n", _f);
	_this->m_a *= _f;
	_this->m_b *= _f;
	
	return;
}


/*
double area() const {
	return m_a * m_b;
}
*/
double AB_9_Rectangle_F_4_area_0p_const(const Rectangle* const _this)
{
	return _this->m_a * _this->m_b;
}





















/*
void report(const Shape& s) {
	std::puts("-----report-----");
	s.draw(); 
	Shape::printInventory();
	std::puts("-----report-----");
}
*/
void A_6_report_1p_Se(const Shape* const _s)
{
	puts("-----report-----");
	
	((void(*)(const Shape* const))_s->m_scaleable.m_vTable[2])(_s); /* call draw wiht 0 parameters */
	
	AB_5_Shape_SF_printInventory();
	
	puts("-----report-----");
	
	return;
}


/*
inline void draw(Shape& obj) { 
	std::puts("-----draw(Shape&)-----");
	obj.scale();
	obj.draw();	
	std::puts("-----draw(Shape&)-----");
} 
*/
void A_4_draw_1p_Se_ref(Shape* const _obj) /*TODO: should be inline */
{
	puts("-----draw(Shape&)-----");
	
	((void(*)(Shape* const, double _f))_obj->m_scaleable.m_vTable[1])(_obj, 1); /* call scale with 1 param */
	
	((void(*)(const Shape* const))_obj->m_scaleable.m_vTable[2])(_obj); /* call draw with 0 parameters */
	
	puts("-----draw(Shape&)-----");
	
	return;
}

/*
void draw(Circle c) { 
	std::puts("-----draw(Circle)-----");

	static Circle unit(1);
	
	unit.draw();
	unit.scale(3);
	c.draw(); 
	std::puts("-----draw(Circle)-----");
}
*/
Circle A_4_draw_1p_Ce_var_Ce_4_unit;
int A_4_draw_1p_Ce_var_Ce_4_unit_isInit = 0;

void A_4_draw_1p_Ce(Circle _c) 
{ 
	puts("-----draw(Circle)-----");

	if (!A_4_draw_1p_Ce_var_Ce_4_unit_isInit)
	{
		AB_6_Circle_C_1p_de(&A_4_draw_1p_Ce_var_Ce_4_unit, 1); 
		
		A_4_draw_1p_Ce_var_Ce_4_unit_isInit = 1;
	}	
	
	AB_6_Circle_F_4_draw_0p_const(&A_4_draw_1p_Ce_var_Ce_4_unit);
	
	AB_6_Circle_F_5_scale_1p_de(&A_4_draw_1p_Ce_var_Ce_4_unit, 3);
	
	AB_6_Circle_F_4_draw_0p_const(&_c);
	
	puts("-----draw(Circle)-----");
}

/*
void doObjArray(){
	Shape objects[] = {
	    Circle(),
	    Rectangle(4),
	    Circle(9)
	};

    for(int i = 0; i < 3; ++i) 
		objects[i].draw();
}
*/
void A_10_doObjArray_0p_Ce()
{
	Shape objects[3];
	Circle temp_c1;
	Rectangle temp_r1;
	Circle temp_c2;
	
	AB_6_Circle_C_0p(&temp_c1);
	AB_5_Shape_C_1p_const_Se_const_ptr(&objects[0], (Shape*)&temp_c1);
	AB_6_Circle_D_0p(&temp_c1);
	
	AB_9_Rectangle_C_1p_it(&temp_r1, 4);
	AB_5_Shape_C_1p_const_Se_const_ptr(&objects[1], (Shape*)&temp_r1);
	AB_9_Rectangle_D_0p(&temp_r1);
	
	AB_6_Circle_C_1p_de(&temp_c2, 9);
	AB_5_Shape_C_1p_const_Se_const_ptr(&objects[2], (Shape*)&temp_c2);
	AB_6_Circle_D_0p(&temp_c2);
	
	return;
} 

/*
void disappear() {
	std::puts("-----disappear-----");

	Circle defaultCircle();

	std::puts("-----disappear-----");
}
*/

void A_9_disappear_0p_Ce()
{
	puts("-----disappear-----");
	
	puts("-----disappear-----");
}


/*
double diffWhenDoubled(Shape& shape){
	double a0 = shape.area();
	shape.scale(2);
	double a1 = shape.area();
	return a1 - a0;
}
*/
double A_15_diffWhenDoubled_Se(Shape* const _shape)
{
	double a0;
	double a1;
	
	a0 = ((double (*)(const Shape* const))_shape->m_scaleable.m_vTable[4])(_shape);
	((void (*)(Shape* const, double))_shape->m_scaleable.m_vTable[1])(_shape, 2);
	a1 = ((double (*)(const Shape* const))_shape->m_scaleable.m_vTable[4])(_shape);
	
	return a1 - a0;
}

/*
double diffWhenDoubled(Circle& shape){
	double a0 = shape.area();
	shape.scale(2);
	double a1 = shape.area();
	return a1 - a0;
}
*/
double A_15_diffWhenDoubled_Ce(Circle* const _shape)
{
	double a0;
	double a1;
	
	a0 = ((double (*)(const Circle* const))_shape->m_shape.m_scaleable.m_vTable[4])(_shape);
	((void (*)(Circle* const, double))_shape->m_shape.m_scaleable.m_vTable[1])(_shape, 2);
	a1 = ((double (*)(const Circle* const))_shape->m_shape.m_scaleable.m_vTable[4])(_shape);
	
	return a1 - a0;
}

/*
void doPointerArray(){
	std::puts("-----doPointerArray-----");
	Shape *array[] =  {
	    new Circle(),
	    new Rectangle(3),
	    new Circle(4)
	};

    for(int i = 0; i < 3; ++i){ 
		array[i]->scale();
		array[i]->draw();
	}

	std::printf("area: %f\n", diffWhenDoubled(*array[2]));

    for(int i = 0; i < 3; ++i) { 
		delete array[i]; 
		array[i] = 0; 
	}

	std::puts("-----doPointerArray-----");
}
*/
void A_14_doPointerArray_0p()
{
	Shape* 		array[3];
	Circle* 	temp_c1;
	Rectangle* 	temp_r1;
	Circle*		temp_c2;
	int i;
	
	puts("-----doPointerArray-----");
	
	temp_c1 = malloc(sizeof(Circle));
	temp_r1 = malloc(sizeof(Rectangle));
	temp_c2 = malloc(sizeof(Circle));
	
	AB_6_Circle_C_0p(temp_c1);
	array[0] = (Shape*)temp_c1;
	
	AB_9_Rectangle_C_1p_it(temp_r1, 3);
	array[1] = (Shape*)temp_r1;
	
	AB_6_Circle_C_1p_de(temp_c2, 4);
	array[2] = (Shape*)temp_c2;
	
	for(i = 0; i < 3; ++i)
	{
		((double(*)(Shape* const, double))array[i]->m_scaleable.m_vTable[1])(array[i], 1);
		((void(*)(const Shape* const))array[i]->m_scaleable.m_vTable[2])(array[i]);
	}
	
	printf("area: %f\n", A_15_diffWhenDoubled_Ce((Circle*)array[2]));
	
	for(i = 0; i < 3; ++i)
	{
		((void(*)(Shape* const))array[i]->m_scaleable.m_vTable[0])(array[i]);
		free(array[i]);
		array[i] = 0;
	}
	
	puts("-----doPointerArray-----");
	
	return;
}

/*
void dispose(Rectangle* p){
  delete[] p;
}
*/
void A_7_dispose_1p(Rectangle* _p)
{
	size_t numOfRec;
	size_t index;

	_p = _p - sizeof(size_t);
	
	numOfRec = *(size_t*)_p;
	
	_p = _p + sizeof(size_t);
	
	for(index = 0; index < numOfRec; ++index)
	{
		AB_9_Rectangle_D_0p(&_p[index]);
	}
	
	_p = _p - sizeof(size_t);
	
	free(_p);
	
	return;
}


















/*
class Empty {
public:
    Empty(int id = 0) { std::printf("Empty::Empty(%d)\n", id); }
   ~Empty() { std::puts("Empty::~Empty()");}	
};
*/
typedef struct Empty
{
	VirtualFunc*	m_vTable;
}Empty;



void A_5_Empty_C(Empty* const _this, int _id);
void A_5_Empty_D(Empty* const _this);
VirtualFunc empty_virtT[1] = {(VirtualFunc)A_5_Empty_D};

void A_5_Empty_C(Empty* const _this, int _id)
{
	printf("Empty::Empty(%d)\n", _id);
	
	_this->m_vTable = empty_virtT;
	
	return;
}

void A_5_Empty_D(Empty* const _this)
{	
	puts("Empty::~Empty()");
	
	_this->m_vTable = empty_virtT;	
		
	return;
}











/*
class EmptyEmpty  : public Empty{
	int m_i;

public:
	EmptyEmpty(int id) : m_i(id){
		 std::printf("EmptyEmpty::EmptyEmpty(%d)\n", m_i); 
	}
};
*/
typedef struct EmptyEmpty
{
	Empty	m_empty;
	int		m_i;
}EmptyEmpty;

void A_10_EmptyEmpty_C(EmptyEmpty* const _this, int _id);



void A_10_EmptyEmpty_C(EmptyEmpty* const _this, int _id)
{
	printf("EmptyEmpty::EmptyEmpty(%d)\n", _this->m_i); 

	A_5_Empty_C(&(_this->m_empty), _id);
	
	_this->m_i = _id;
	
	return;
}

 









/*
class EmptyBag {
	Empty e1;
	Empty e2;
	EmptyEmpty ee;
public: 
	EmptyBag() : e2(2), e1(1), ee(2) {
		std::puts("EmptyBag::EmptyBag()");
	}
	~EmptyBag(){
		std::puts("EmptyBag::~EmptyBag");
	}	
};
*/
typedef struct EmptyBag
{
	Empty 		m_e1;
	Empty 		m_e2;
	EmptyEmpty 	m_ee;
}EmptyBag;


void A_8_EmptyBag_C(EmptyBag* const _this) 
{
	puts("EmptyBag::EmptyBag()");
	A_5_Empty_C(&(_this->m_e1), 1);
	A_5_Empty_C(&(_this->m_e2), 2);
	A_5_Empty_C(&(_this->m_ee.m_empty), 2);
	
	
}
void A_8_EmptyBag_D(EmptyBag* const _this)
{
	puts("EmptyBag::~EmptyBag");
}	














/*
int main(int argc, char **argv, char **envp)
{	
	std::printf("---------------Start----------------\n");
    Circle c;
	Rectangle s(4);

	std::printf("0.-------------------------------\n");		
	draw(c);

	std::printf("+..............\n");		
	draw(c);

	std::printf("+..............\n");		
    draw(s);

	std::printf("+..............\n");		
	report(c);

	std::printf("1.-------------------------------\n");	
	
    doPointerArray();

	std::printf("2.-------------------------------\n");

    doObjArray();

	std::printf("3.-------------------------------\n");

    Shape::printInventory();
    Circle c2 = c;
    c2.printInventory();

	std::printf("4.-------------------------------\n");
   
    Circle olympics[5];
	std::printf("olympic diff %f\n", diffWhenDoubled(olympics[1]));

	std::printf("5.-------------------------------\n");

    Rectangle *fourRectangles = new Rectangle[4];
    dispose(fourRectangles);

	std::printf("6.-------------------------------\n");
	EmptyBag eb;
	std::printf("Empty things are: %zu %zu %zu", sizeof(Empty), sizeof(EmptyEmpty), sizeof(EmptyBag) );
	
	std::printf("7.-------------------------------\n");
	disappear();	

	std::printf("---------------END----------------\n");

    return 0;
}
*/
int main(int argc, char **argv, char **envp)
{	
	Circle c;
	Circle c_temp;
	Rectangle s;
	Circle c2;
	Circle olympics[5];
	Rectangle* fourRectangles;
	EmptyBag eb;
	
	printf("---------------Start----------------\n");
	AB_6_Circle_C_0p(&c);
	AB_9_Rectangle_C_1p_it(&s, 4);
	
	printf("0.-------------------------------\n");	
	AB_6_Circle_C_1p_const_Ce_ref(&c_temp, &c);
	A_4_draw_1p_Ce(c_temp);
	AB_6_Circle_D_0p(&c_temp);
	
	printf("+..............\n");
	AB_6_Circle_C_1p_const_Ce_ref(&c_temp, &c);
	A_4_draw_1p_Ce(c_temp);
	AB_6_Circle_D_0p(&c_temp);		

	printf("+..............\n");		
	A_4_draw_1p_Se_ref((Shape*)&s);

	printf("+..............\n");		
	A_6_report_1p_Se((Shape*)&c);

	printf("1.-------------------------------\n");	
    A_14_doPointerArray_0p();

	printf("2.-------------------------------\n");
	A_10_doObjArray_0p_Ce();

	printf("3.-------------------------------\n");
	AB_5_Shape_SF_printInventory();
	AB_6_Circle_C_1p_const_Ce_ref(&c2, &c);
	AB_5_Shape_SF_printInventory();

	printf("4.-------------------------------\n");
	AB_6_Circle_C_0p(&olympics[0]);
	AB_6_Circle_C_0p(&olympics[1]);
	AB_6_Circle_C_0p(&olympics[2]);
	AB_6_Circle_C_0p(&olympics[3]);
	AB_6_Circle_C_0p(&olympics[4]);
	printf("olympic diff %f\n", A_15_diffWhenDoubled_Ce(&olympics[1]));
	
	printf("5.-------------------------------\n");
	fourRectangles = malloc(sizeof(size_t) + (4 * sizeof(Rectangle)));
	*(size_t*)fourRectangles = 4;
	fourRectangles = fourRectangles + sizeof(size_t);
	printf("%u\n", *(size_t*)fourRectangles);
	AB_9_Rectangle_C_0p(&fourRectangles[0]);
	AB_9_Rectangle_C_0p(&fourRectangles[1]);
	AB_9_Rectangle_C_0p(&fourRectangles[2]);
	AB_9_Rectangle_C_0p(&fourRectangles[3]);
	A_7_dispose_1p(fourRectangles);
	
	printf("6.-------------------------------\n");
	A_8_EmptyBag_C(&eb);
	printf("Empty things are: %u %u %u", sizeof(Empty), sizeof(EmptyEmpty), sizeof(EmptyBag) );
	
	printf("7.-------------------------------\n");
	A_9_disappear_0p_Ce();

	printf("---------------END----------------\n");
	
	A_8_EmptyBag_D(&eb);
	AB_6_Circle_D_0p(&olympics[4]);
	AB_6_Circle_D_0p(&olympics[3]);
	AB_6_Circle_D_0p(&olympics[2]);
	AB_6_Circle_D_0p(&olympics[1]);
	AB_6_Circle_D_0p(&olympics[0]);
	AB_6_Circle_D_0p(&c2);
	AB_9_Rectangle_D_0p(&s);
	AB_6_Circle_D_0p(&c);
	
    return 0;
}
















