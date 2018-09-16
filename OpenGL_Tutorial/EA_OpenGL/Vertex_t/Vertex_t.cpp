#include "Vertex_t.hpp"
#include<iostream>
using namespace std;
namespace openglEA
{
    Vertex_t::Vertex_t()
    {
        m_x = 0.0;
        m_y = 0.0;
        m_z = 0.0;
    }

    Vertex_t::Vertex_t(GLfloat _x, GLfloat _y, GLfloat _z)
    {
        m_x = _x;
        m_y = _y;
        m_z = _z;
    }

    Vertex_t::Vertex_t(const Vertex_t& _vertex)
    {
        *this = _vertex;
    }

    Vertex_t& Vertex_t::operator=(const Vertex_t& _vertex)
    {
        m_x = _vertex.m_x;
        m_y = _vertex.m_y;
        m_z = _vertex.m_z;
        return *this;
    }

    void Vertex_t::Translate(const Vertex_t& _vertex)
    {
        m_x += _vertex.m_x;
        m_y += _vertex.m_y;
        m_z += _vertex.m_z;
    }

    GLfloat Vertex_t::GetX() const
    {
        return m_x;
    }

    GLfloat Vertex_t::GetY() const
    {
        return m_y;
    }

    GLfloat Vertex_t::GetZ() const
    {
        return m_z;
    }

    void Vertex_t::Print() const
    {
        cout << m_x << ", " << m_y << ", " << m_z << endl;
    }

}//namespace openglEA