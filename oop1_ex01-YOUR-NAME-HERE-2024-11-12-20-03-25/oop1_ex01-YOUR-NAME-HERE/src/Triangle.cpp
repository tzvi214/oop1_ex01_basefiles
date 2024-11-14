#include "Triangle.h"
#include <cmath>

void Triangle::initializeTriangle(const Vertex& ver1, const Vertex& ver2, const Vertex& ver3)
{
	if (ver1.isValid() && ver2.isValid() && ver3.isValid() )//&& ver2.isParallelXAxis(ver1))
	{
		m_verBaseLeft = ver1;
		m_verBaseRight = ver2;
		m_verUp = ver3;
	}
	else
	{
		m_verBaseLeft.m_col = m_verBaseLeft.m_row = 20;
		m_verBaseRight.m_col = 30;
		m_verBaseRight.m_row = 20;
		m_verUp.m_col = 25;
		m_verUp.m_row = 20 + sqrt(75);
	}
}


Triangle::Triangle(const Vertex vertices[3])
{
	initializeTriangle(vertices[0], vertices[1], vertices[2]);
}

Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2)
{
	initializeTriangle(v0, v1, v2);
}

Vertex Triangle::getVertex(int index) const
{
	//return Vertex(m_triangle[index]);

	if(index == 0)
       return Vertex(m_verBaseLeft);
    if(index == 1)
       return Vertex(m_verBaseRight);
	return Vertex(m_verUp);

}

double Triangle::getLength(int index) const
{
	//return abs((m_triangle[(index + 1) % 3].m_col - m_triangle[index].m_col));

	if (index == 0)
		return m_verBaseRight.m_col - m_verBaseLeft.m_col;
	if (index == 1)
		return m_verBaseRight.m_col - m_verUp.m_col;

	return m_verUp.m_col - m_verBaseLeft.m_col;
}
