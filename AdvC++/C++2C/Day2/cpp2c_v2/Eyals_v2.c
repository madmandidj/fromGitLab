#include <stdio.h>

typedef void (*VirtualFunc)(void);

typedef VirtualFunc* virt_t;





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
	
	AB_5_Shape_F_4_draw_0p_const(_this);
	
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
	
	((void(*)(const Shape* const))_this->m_scaleable.m_vTable[1])(_this);
	
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
void AB_6_Circle_F_5_scale_1p_de(const Circle* const _this, double _f); /* virtual */
void AB_6_Circle_D_0p(Circle* const _this); /* virtual */
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
	
	_this->m_shape.m_scaleable.m_vTable = shap_virtT;	/* set derived virtual pointer */
	
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
	
	_this->m_shape.m_scaleable.m_vTable = shap_virtT;	/* set derived virtual pointer */
	
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
	_this->m_shape.m_scaleable.m_vTable = circ_virtT;	/* set derived virtual pointer */
	
	AB_5_Shape_C_1p_const_Se_const_ptr(&(_this->m_shape), &(_other->m_shape));

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

	return;
}


/*
void scale(double f = 2) {
	std::printf("Circle::scale(%f)\n", f);
	m_radius *= f;
}
*/
void AB_6_Circle_F_5_scale_1p_de(const Circle* const _this, double _f)
{

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








int main(int argc, char **argv, char **envp)
{	
	Circle c;
/*	Rectangle s;*/
/*	Circle c2;*/
/*	Circle olympics[5];	*/
/*	Rectangle* fourRectangles;*/
/*	EmptyBag eb;*/
	
	printf("---------------Start----------------\n");
/*    Circle c;*/
/*	Rectangle s(4);*/
	AB_6_Circle_C_0p(&c);

	printf("0.-------------------------------\n");		
	draw(c);

/*	printf("+..............\n");		*/
/*	draw(c);*/

/*	printf("+..............\n");		*/
/*    draw(s);*/

/*	printf("+..............\n");		*/
/*	report(c);*/

/*	printf("1.-------------------------------\n");	*/
/*	*/
/*    doPointerArray();*/

/*	printf("2.-------------------------------\n");*/

/*    doObjArray();*/

/*	printf("3.-------------------------------\n");*/

    AB_5_Shape_SF_printInventory();
/*    Circle c2 = c;*/
/*    c2.printInventory();*/

/*	printf("4.-------------------------------\n");*/
   
/*    Circle olympics[5];*/
/*	printf("olympic diff %f\n", diffWhenDoubled(olympics[1]));*/

/*	printf("5.-------------------------------\n");*/

/*    Rectangle *fourRectangles = new Rectangle[4];*/
/*    dispose(fourRectangles);*/

/*	printf("6.-------------------------------\n");*/
/*	EmptyBag eb;*/
/*	printf("Empty things are: %zu %zu %zu", sizeof(Empty), sizeof(EmptyEmpty), sizeof(EmptyBag) );*/
	
/*	printf("7.-------------------------------\n");*/
/*	disappear();	*/

	printf("---------------END----------------\n");

    return 0;
}
















