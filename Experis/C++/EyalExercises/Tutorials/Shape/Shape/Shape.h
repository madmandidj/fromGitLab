#ifndef __SHAPE_H__
#define __SHAPE_H__


class Shape
{
   protected:
      int width, height;
      
   public:
      Shape(int a = 0, int b = 0);
      virtual int Area() = 0; // pure vitrual since = 0;
};


class Triangle: public Shape
{
	public:
	Triangle(int a = 0, int b = 0):Shape(a, b){}
	int Area();

};




#endif /* #ifndef __SHAPE_H__ */
