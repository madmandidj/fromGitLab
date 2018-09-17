#include "../Vertex_t/Vertex_t.hpp"
#include "../Triangle_t/Triangle_t.hpp"
#include "Object_t.hpp"
#include<iostream>

using namespace std;
using namespace openglEA;

int main()
{
    Vertex_t brickLTop_a(-0.775f, 0.3f, 0.0f);
    Vertex_t brickLTop_b(-0.8f, 0.3f, 0.0f);
    Vertex_t brickLTop_c(-0.8f, -0.3f, 0.0f);
    Triangle_t brickLTop(brickLTop_a, brickLTop_b, brickLTop_c, Triangle_t::BRICK_TOP);
    Vertex_t brickLBottom_a(-0.8f, -0.3f, 0.0f);
    Vertex_t brickLBottom_b(-0.775f, -0.3f, 0.0f);
    Vertex_t brickLBottom_c(-0.775f, 0.3f, 0.0f);
    Triangle_t brickLBottom(brickLBottom_a, brickLBottom_b, brickLBottom_c, Triangle_t::BRICK_BOTTOM);
    Object_t object1(Object_t::LEFT_BRICK);
    object1.AddTriangle(brickLTop);
    object1.AddTriangle(brickLBottom);
    cout << object1.NumOfTriangles() << endl;
    object1.Print();
    return 0;
}




/*

    -0.775f, 0.3f, 0.0f, //PadL_Top-tri_1
    -0.8f, 0.3f, 0.0f,//PadL_Top-tri_2
    -0.8f, -0.3f, 0.0f,//PadL_Top-tri_3
    
    -0.8f, -0.3f, 0.0f, //PadL_Bottom-tri_1
    -0.775f, -0.3f, 0.0f,//PadL_Bottom-tri_2
    -0.775f, 0.3f, 0.0f,//PadL_Bottom-tri_3
*/