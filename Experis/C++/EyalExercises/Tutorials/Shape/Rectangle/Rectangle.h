#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__


class Rectangle: public Shape
{      
   public:
      Rectangle(int a = 0, int b = 0):Shape(a,b);
      int Area();
};




#endif /* #ifndef __RECTANGLE_H__ */
