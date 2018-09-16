#ifndef __VERTEX_T_HPP__
#define __VERTEX_T_HPP__
#include <GL/glew.h>

namespace openglEA
{
class Vertex_t 
{
public:
    virtual ~Vertex_t(){}
    Vertex_t();
    Vertex_t(GLfloat _x, GLfloat _y, GLfloat _z);
    Vertex_t(const Vertex_t& _vertex);
    Vertex_t& operator=(const Vertex_t& _vertex);
    void Translate(const Vertex_t& _vertex);
    GLfloat GetX() const;
    GLfloat GetY() const;
    GLfloat GetZ() const;
    void Print() const;
protected:

private:
    // Vertex_t(); //Default CTOR not allowed
    GLfloat m_x;
    GLfloat m_y;
    GLfloat m_z;
};
}//namespace openglEA
#endif //#ifndef __VERTEX_T_HPP__
