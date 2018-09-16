#include "Triangle_t.hpp"
#include<iostream>
using namespace std;
namespace openglEA
{
    Triangle_t::Triangle_t(Vertex_t& _v1, Vertex_t& _v2, Vertex_t& _v3, TriangleID _id)
    {
        m_v1 = _v1;
        m_v2 = _v2;
        m_v3 = _v3;
        m_id = _id;
    }

    Triangle_t::Triangle_t(const Triangle_t& _triangle)
    {
        *this = _triangle;
    }

    Triangle_t& Triangle_t::operator=(const Triangle_t& _triangle)
    {
        m_v1 = _triangle.m_v1;
        m_v2 = _triangle.m_v2;
        m_v3 = _triangle.m_v3;
        m_id = _triangle.m_id;
        return *this;
    }

    const Vertex_t& Triangle_t::GetV1() const
    {
        return m_v1;
    }

    const Vertex_t& Triangle_t::GetV2() const
    {
        return m_v2;
    }

    const Vertex_t& Triangle_t::GetV3() const
    {
        return m_v3;
    }

    Triangle_t::TriangleID Triangle_t::GetID() const
    {
        return m_id;
    }

    void Triangle_t::SetID(TriangleID _id)
    {
        m_id = _id;
    }

    void Triangle_t::TranslateTriangle(const Vertex_t& _transfromVertex)
    {
        this->TranslateV1(_transfromVertex);
        TranslateV2(_transfromVertex);
        TranslateV3(_transfromVertex);
    }

    void Triangle_t::TranslateV1(const Vertex_t& _transfromVertex)
    {
        m_v1.Translate(_transfromVertex);
    }

    void Triangle_t::TranslateV2(const Vertex_t& _transfromVertex)
    {
        m_v2.Translate(_transfromVertex);
    }

    void Triangle_t::TranslateV3(const Vertex_t& _transfromVertex)
    {
        m_v3.Translate(_transfromVertex);
    }

    void Triangle_t::Print() const
    {
        cout << "ID = " << m_id << endl;
        cout << "v1 = " << m_v1.GetX() << ", " << m_v1.GetY() << ", " << m_v1.GetZ() << endl;
        cout << "v2 = " << m_v2.GetX() << ", " << m_v2.GetY() << ", " << m_v2.GetZ() << endl;
        cout << "v3 = " << m_v3.GetX() << ", " << m_v3.GetY() << ", " << m_v3.GetZ() << endl;
    }

    bool Triangle_t::operator<(const Triangle_t& _triangle) const
    {
        return  m_id < _triangle.GetID();
    }

    bool Triangle_t::operator==(const Triangle_t& _triangle) const
    {
        return  m_id == _triangle.GetID();
    }

    // bool Triangle_t::operator==(const Triangle_t::TriangleID& _triangleID) const
    // {
    //     return  m_id == _triangleID;
    // }

}//namespace openglEA