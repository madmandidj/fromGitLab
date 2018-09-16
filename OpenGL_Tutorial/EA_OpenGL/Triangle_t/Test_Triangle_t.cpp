#include "Triangle_t.hpp"
#include<iostream>

using namespace std;
using namespace openglEA;

int main()
{
    Vertex_t vertex1(0,0,0);
    Vertex_t vertex2(0,0.5,0);
    Vertex_t vertex3(1,0,0);
    Triangle_t triangle(vertex1, vertex2, vertex3, Triangle_t::BRICK_BOTTOM);
    Triangle_t triCopy(triangle);
    triCopy.SetID(Triangle_t::BRICK_TOP);
    triCopy.TranslateTriangle(vertex2);
    triangle.Print();
    triCopy.Print();
    return 0;
}