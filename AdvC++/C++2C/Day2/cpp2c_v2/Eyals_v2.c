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

void ABC_10_Scaleable_D_0p(Scaleable* const _this);
void ABC_10_Scaleable_F_5_scale_1p_de(Scaleable* const _this, double _dbl);
VirtualFunc scal_virtT[2] = {(VirtualFunc)ABC_10_Scaleable_D_0p, (VirtualFunc)ABC_10_Scaleable_F_5_scale_1p_de}; 

void ABC_10_Scaleable_D_0p(Scaleable* const _this)
{
	/* Empty */
}

void ABC_10_Scaleable_F_5_scale_1p_de(Scaleable* const _this, double _dbl)
{
	 /* This call should terminate program because its pure virtual with no implementation */
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
static int AB_5_Shape_NumOfShapes = 0;

typedef struct Shape
{
	VirtualFunc* 	m_vTable;
	int				m_id;
}Shape;

void AB_5_Shape_C_0p(Shape* const _this);

void AB_5_Shape_D_0p(Shape* const _this);

void AB_5_Shape_C_1p_const_Se_const_ptr(Shape* const _this, const Shape* const _other);

void AB_5_Shape_F_4_draw_0p_const(const Shape* const _this); /*virtual*/

void AB_5_Shape_F_4_draw_1p_Cm_const(const Shape* const _this, ColorEnum _c); /*virtual*/ 

void AB_5_Shape_F_5_scale_1p_de(Shape* const _this, double _f); /*virtual*/

double AB_5_Shape_F_4_area_const(const Shape* const _this); /*virtual*/

static void AB_5_Shape_SF_printInventory();  

VirtualFunc shap_virtT[5] = {(VirtualFunc)ABC_10_Scaleable_D_0p, 
						(VirtualFunc)AB_5_Shape_F_4_draw_0p_const,
						(VirtualFunc)AB_5_Shape_F_4_draw_1p_Cm_const,
						(VirtualFunc)AB_5_Shape_F_5_scale_1p_de,
						(VirtualFunc)AB_5_Shape_F_4_area_const}; 

/*
Shape() : m_id(++NumOfShapes) 
{
		std::printf("Shape::Shape() - %d\n", m_id); 
}
*/
void AB_5_Shape_C_0p(Shape* const _this)
{
	/* Calls constructor of base */
	
	_this->m_vTable = shap_virtT;	
	
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
	AB_5_Shape_F_4_draw_0p_const(_this);
	
	--AB_5_Shape_NumOfShapes;
	
	printf("Shape::~Shape - %d\n", _this->m_id);
	
	/* Call destructor of base */
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
	/* Calls constructor of base */
	
	_this->m_vTable = shap_virtT;	
	
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
	
	((void(*)(const Shape* const))_this->m_vTable[1])(_this);
	
	setColor(DEFAULT);
	
	return;
}


/*
virtual void scale(double f = 1) 
{ 
	std::printf("Shape::scale(%f)\n", f);
}
*/



/*
virtual double area() const 
{ 
	return -1; 
}
*/



/*
static void printInventory() 
{
	std::printf("Shape::printInventory - %d\n", NumOfShapes);
}
*/








int main()
{
	
	return 0;
}

