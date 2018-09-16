#include "../Vertex_t/Vertex_t.hpp"
#include "../Triangle_t/Triangle_t.hpp"
#include "Object_t.hpp"
#include<iostream>
using namespace std;
namespace openglEA
{
    Object_t::Object_t(ObjectID _id)
    {
        m_id = _id;
    }

    void Object_t::AddTriangle(Triangle_t& _triangle)
    {
        m_triContainer.insert(std::pair<Triangle_t, Triangle_t::TriangleID>(_triangle, _triangle.GetID()));
    }

    void Object_t::RemoveTriangle(Triangle_t& _triangle)
    {
        // m_triContainer.remove(_id);
        // int intID = _id;
        // std::set<Triangle_t> it = m_triContainer.find(intID);
        // m_triContainer.erase(it);
        m_triContainer.erase(m_triContainer.find(_triangle));
    }

    size_t Object_t::NumOfTriangles() const
    {
        return m_triContainer.size();
    }

    void Object_t::Print() const
    {
        size_t numOfTris = NumOfTriangles();
        cout << "Object ID = " << m_id << endl;
        // for (std::map<Triangle_t, Triangle_t::TriangleID>::iterator it = m_triContainer.begin(); it != m_triContainer.end(); ++it)
        // {
        //     (*it)->Print();
        // }
        for (std::map<Triangle_t, Triangle_t::TriangleID>::const_iterator it = m_triContainer.begin();
                it != m_triContainer.end(); ++it)
        {
            (*it).first.Print();
        }
    }



}//namespace openglEA