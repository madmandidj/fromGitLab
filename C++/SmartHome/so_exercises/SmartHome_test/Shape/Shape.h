#ifndef __SHAPE_H__
#define __SHAPE_H__



class Shape
{
	public:
		static Shape* Maker(int _size) = 0;
		
	protected:
	
	private:
		Shape(int _size);
		~Shape();
};






















#endif //#ifndef __SHAPE_H__

