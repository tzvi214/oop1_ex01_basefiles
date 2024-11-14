#include "Window.h"
#include "Rectangle.h"
#include "macros.h"
#include <iostream>

using namespace std;
Window::Window(const Rectangle& rectangle, const Vertex& point) 
	//:m_rectangle (rectangle), זה טוב אבל משתמש בבנאי העתקה 
	:m_rectangle(Rectangle(m_rectangle.getBottomLeft(), m_rectangle.getTopRight())),
	m_point(25, 15)
{
	if (point.isLegalWindo(rectangle.getBottomLeft(), rectangle.getTopRight()))
	{
		m_rectangle = rectangle; // האם מותר לעשות את זה כי זה בנאי העתקה
		m_point = point;
	}
	cout << "in main counstrocrur Windo \n";
}


Window::Window(const Vertex& topRight, double width, double height, const Vertex& point)
  :Window(Rectangle (Vertex(topRight.m_col - width, topRight.m_row - height), topRight)
     , point)
{

	cout << "in counstrocrur Windo \n";
}

Vertex Window::getBottomLeft() const
{
	return Vertex(m_rectangle.getBottomLeft());
}

Vertex Window::getTopRight() const
{
	return Vertex(m_rectangle.getTopRight());
}

Vertex Window::getPoint() const
{
	return m_point;
}
//----------------------------------------
Rectangle Window::getBoundingRectangle() const
{
	return m_rectangle.getBoundingRectangle();
}

double Window::getPerimeter() const
{
 //  Rectangle left_down(m_rectangle.getBottomLeft(), m_point), 
 //  right_down(Vertex( m_point.m_col, m_rectangle.getBottomLeft().m_row), Vertex(m_rectangle.getTopRight().m_col, m_point.m_row)),//(p,bl),(tr,p)
 //  left_up(Vertex(m_rectangle.getBottomLeft().m_col, m_point.m_row), Vertex(m_point.m_col, m_rectangle.getTopRight().m_row)),//(bl,p),(p,tr)
 //  right_up(m_point, m_rectangle.getTopRight());

	//return(left_down.getPerimeter() + right_down.getPerimeter() + left_up.getPerimeter() + right_up.getPerimeter()) ;
	return m_rectangle.getPerimeter()*2;
}

double Window::getArea() const
{
	return m_rectangle.getArea(); 
}

Vertex Window::getCenter() const
{
	return m_point;
}

bool Window::scale(double factor)
{
	return m_rectangle.scale(2); 
}

void Window::draw(Board& board) const
{

 Rectangle left_down(m_rectangle.getBottomLeft(), m_point),
 right_down(Vertex(m_point.m_col, m_rectangle.getBottomLeft().m_row), Vertex(m_rectangle.getTopRight().m_col, m_point.m_row)),//(p,bl),(tr,p)
 left_up(Vertex(m_rectangle.getBottomLeft().m_col, m_point.m_row), Vertex(m_point.m_col, m_rectangle.getTopRight().m_row)),//(bl,p),(p,tr)
 right_up(m_point, m_rectangle.getTopRight());

 //cout << "\n right_down is:" << right_down.getBottomLeft().m_col << "," << right_down.getBottomLeft().m_row << ";  " <<
	// right_down.getTopRight().m_col << ", " << right_down.getTopRight().m_row << endl;

 //cout << "\n left_up is:" << left_up.getBottomLeft().m_col << "," << left_up.getBottomLeft().m_row << ";  "
	// << left_up.getTopRight().m_col << ", " << left_up.getTopRight().m_row << endl;

 left_down.draw(board);
 right_down.draw(board);
 left_up.draw(board);
 right_up.draw(board);

}

