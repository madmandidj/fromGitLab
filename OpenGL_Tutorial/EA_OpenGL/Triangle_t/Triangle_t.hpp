#ifndef __TRIANGLE_T_HPP__
#define __TRIANGLE_T_HPP__
#include <GL/glew.h>
#include "../Vertex_t/Vertex_t.hpp"

namespace openglEA
{
class Triangle_t 
{
public:
    typedef enum
    {
        BRICK_BOTTOM = 0,
        BRICK_TOP = 1,
        NO_ID
    }TriangleID;
    virtual ~Triangle_t(){}
    Triangle_t(Vertex_t& _v1, Vertex_t& _v2, Vertex_t& _v3, TriangleID _id);
    Triangle_t(const Triangle_t& _triangle);
    Triangle_t& operator=(const Triangle_t& _triangle);
    const Vertex_t& GetV1() const;
    const Vertex_t& GetV2() const;
    const Vertex_t& GetV3() const;
    TriangleID GetID() const;
    void SetID(TriangleID _id);
    void TranslateTriangle(const Vertex_t& _transfromVertex);
    void TranslateV1(const Vertex_t& _transfromVertex);
    void TranslateV2(const Vertex_t& _transfromVertex);
    void TranslateV3(const Vertex_t& _transfromVertex);
    void Print() const;
    bool operator<(const Triangle_t& _triangle) const;
    bool operator==(const Triangle_t& _triangle) const;
    // bool operator==(const Triangle_t::TriangleID& _triangleID) const;
protected:

private:
    Triangle_t(); // Default CTOR not allowed
    Vertex_t m_v1;
    Vertex_t m_v2;
    Vertex_t m_v3;
    TriangleID m_id;
};
}//namespace openglEA
#endif //#ifndef __TRIANGLE_T_HPP__
