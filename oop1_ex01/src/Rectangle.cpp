#include <Vertex.h>
#include <Rectangle.h>
#include <macros.h>
#include <iostream>
using namespace std;


Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight) :
	m_bottomLeft(20, 10),
	m_topRight(30, 20),
	m_width(m_topRight.m_col - m_bottomLeft.m_col),
	m_height(m_topRight.m_row - m_bottomLeft.m_row)
{
	if (bottomLeft.isValid() && topRight.isValid() &&
		 topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft))
	{
	  m_bottomLeft = bottomLeft;
	  m_topRight = topRight;
		
	  m_width = m_topRight.m_col - m_bottomLeft.m_col,
	  m_height = m_topRight.m_row - m_bottomLeft.m_row;

	//	cout << "good" << endl;
	}
	/*else
	{
		cout << "not good" << endl;
	};*/

}

Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1])
{
	
	//Rectangle(vertices[0], vertices[1]);
}

Rectangle::Rectangle(double x, double y, double width, double height)
	:Rectangle(Vertex(x, y), Vertex(x + width, y + height))

{
	
}

Rectangle::Rectangle(const Vertex& topRight, double width, double height)
	:Rectangle(Vertex(topRight), Vertex(topRight.m_col - width, topRight.m_row - height))
{
	
}

Vertex Rectangle::getBottomLeft() const
{

	return Vertex(m_bottomLeft);//m_bl_col, m_bl_row
}

Vertex Rectangle::getTopRight() const
{
	return Vertex (m_topRight); //m_tr_col, m_bl_col
}

double Rectangle::getWidth() const
{
	return m_width; //m_tr_col - m_bl_col
}

double Rectangle::getHeight() const
{
	return m_height; // m_tr_row - m_bl_row
}

