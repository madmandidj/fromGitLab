#ifndef __OBJECT_T_HPP__
#define __OBJECT_T_HPP__
#include <GL/glew.h>
#include<map>
#include "../Triangle_t/Triangle_t.hpp"
#include "../Vertex_t/Vertex_t.hpp"

namespace openglEA
{

class Object_t 
{
public:
    typedef enum
    {
        MENU_LINE,
        LEFT_BRICK,
        RIGHT_BRICK
    }ObjectID;
    virtual ~Object_t(){}
    Object_t(ObjectID _id);
    void AddTriangle(Triangle_t& _triangle);
    void RemoveTriangle(Triangle_t& _triangle);
    size_t NumOfTriangles() const;
    void Print() const;
protected:
    std::map<Triangle_t, Triangle_t::TriangleID> m_triContainer;
    ObjectID m_id;
private:
    Object_t(const Object_t& _objTri);//Copy CTOR NA
    Object_t& operator=(const Object_t& _objTri);//Assignment Operator NA
};
}//namespace openglEA
#endif //#ifndef __OBJECT_T_HPP__
