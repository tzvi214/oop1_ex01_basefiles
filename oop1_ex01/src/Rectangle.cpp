#include "Rectangle.h"
#include "macros.h"
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

	}
	
}

Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1])
{
	
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

	return m_bottomLeft;
}

Vertex Rectangle::getTopRight() const
{
	return m_topRight; 
}

double Rectangle::getWidth() const
{
	return m_width; 
}

double Rectangle::getHeight() const
{
	return m_height; 
}
//-------------------------------------------------
void Rectangle::draw(Board& board) const {

   
    // יצירת  ערכים זמניים ליצירת הקווים.
    Vertex bottemRight, topLeft;

    bottemRight.m_col = m_topRight.m_col;
    bottemRight.m_row = m_bottomLeft.m_row;
    topLeft.m_col = m_bottomLeft.m_col;
    topLeft.m_row = m_topRight.m_row;

    board.drawLine(m_bottomLeft,Vertex(m_topRight.m_col, m_bottomLeft.m_row));

    board.drawLine(m_bottomLeft, bottemRight); // under line.
    board.drawLine(topLeft, m_topRight);  // up line.
    board.drawLine(m_bottomLeft, topLeft);  // left line.
    board.drawLine(bottemRight, m_topRight);  // right line.
}

Rectangle Rectangle::getBoundingRectangle() const
{
    // return this rectagle.
    return Rectangle(m_bottomLeft, m_topRight);
}

double Rectangle::getPerimeter() const
{
    return (m_height * 2) + (m_width * 2);
}

double Rectangle::getArea() const
{
    return (m_height * m_width);
}

Vertex Rectangle::getCenter() const
{
   return Vertex((m_width / 2) + m_bottomLeft.m_col, (m_height / 2) + m_bottomLeft.m_row);
}

bool Rectangle::scale(double factor)
{
    if (factor <= 0)
        return false;

    Vertex center = getCenter();


    // המרחקים החדשים מכל קודקוד למרכז
    Vertex bottomLeftNew (
        center.m_col + (m_bottomLeft.m_col - center.m_col) * factor,
        center.m_row + (m_bottomLeft.m_row - center.m_row) * factor);
    

    Vertex topRightNew(
        center.m_col + (m_topRight.m_col - center.m_col) * factor,
        center.m_row + (m_topRight.m_row - center.m_row) * factor);
    

    if (!isLegal(bottomLeftNew, topRightNew))
        return false;

    // עדכון הקודקודים לאחר בדיקה שהתחום תקין
    m_bottomLeft = bottomLeftNew;
    m_topRight = topRightNew;
    m_width = topRightNew.m_col - bottomLeftNew.m_col;
    m_height = topRightNew.m_row - bottomLeftNew.m_row;

    return true;
}
bool Rectangle::isLegal(const Vertex& bottomLeft, const Vertex& topRight)
{
    return (bottomLeft.isValid() && topRight.isValid() &&
        topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft));
}

