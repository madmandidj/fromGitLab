#include "Vertex_t.hpp"
#include<iostream>

using namespace std;
using namespace openglEA;

int main()
{
    Vertex_t vertex(0,0,0);
    Vertex_t vertex2(0,1,0);
    Vertex_t vertex3(vertex2);
    // vertex2.Translate(vertex2);

    // vertex2.Print();
    vertex3.Print();
    vertex2.Translate(vertex2);
    vertex3.Print();
    vertex2.Print();
    return 0;
}