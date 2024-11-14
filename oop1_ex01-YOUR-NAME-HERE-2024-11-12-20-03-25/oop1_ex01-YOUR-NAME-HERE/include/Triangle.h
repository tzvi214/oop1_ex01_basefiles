#pragma once

#include "Vertex.h"

class Triangle
{
public:
	Triangle(const Vertex vertices[3]);
	Triangle(Vertex v0, Vertex v1, Vertex v2);

	Vertex getVertex(int index) const;
	double getLength(int index) const;
private:
	void initializeTriangle(const Vertex&, const Vertex&, const Vertex&);
	
	Vertex m_verBaseLeft, m_verBaseRight, m_verUp;
	//Vertex m_triangle [3] = { m_verBaseLeft, m_verBaseRight, m_verBaseRight };

};