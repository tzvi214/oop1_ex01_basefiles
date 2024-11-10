#include <Vertex.h>
#include <Rectangle.h>
#include <macros.h>
#include <iostream>
using namespace std;


Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	//cout << "@@@@@@@@@@@@@@@@@@@@@" << endl;

	/*bottomLeft.m_col < 0 || bottomLeft.m_col > MAX_COL ||
	bottomLeft.m_row < 0 || bottomLeft.m_row > MAX_ROW ||
		topRight.m_col < 0 || topRight.m_col > MAX_COL ||
		topRight.m_row < 0 || topRight.m_row > MAX_ROW ||*/
	// bottomLeft.m_col > topRight.m_col || bottomLeft.m_row > topRight.m_row
	if (!bottomLeft.isValid() || !topRight.isValid() ||
		 !topRight.isHigherThan(bottomLeft)  ||  !topRight.isToTheRightOf(bottomLeft))
	{
		m_bottomLeft.m_col = 20, m_bottomLeft.m_row = 10;
		m_topRight.m_col = 30, m_topRight.m_row = 20;
		m_width = m_topRight.m_col - m_bottomLeft.m_col, 
		m_height = m_topRight.m_row - m_bottomLeft.m_row;
		
	 cout << "not good" << endl;

		
	}
	else
	{
		m_bottomLeft.m_col = bottomLeft.m_col , m_bottomLeft.m_row = bottomLeft.m_row;
		m_topRight.m_col = topRight.m_col, m_topRight.m_row = topRight.m_row;
		m_width = m_topRight.m_col - m_bottomLeft.m_col,
		m_height = m_topRight.m_row - m_bottomLeft.m_row;

		cout << "good" << endl;


	};

}

Rectangle::Rectangle(const Vertex vertices[2])
{
	
	Rectangle(vertices[0], vertices[1]);
}

Rectangle::Rectangle(double x, double y, double width, double height)
{
	Vertex bottomLeft, topRight;
	bottomLeft.m_col = x, bottomLeft.m_row = y;
	topRight.m_col = x + width, topRight.m_row = y + height;
	Rectangle(bottomLeft, topRight);

	// זה אוטמומטי בודק שזה לא שלילי האורך והגובה 
	// בגלל הבדיקות של היחס
}

Rectangle::Rectangle(const Vertex& topRight, double width, double height)
{
	Vertex bottomLeft;
	bottomLeft.m_col = topRight.m_col - width;
	bottomLeft.m_row = topRight.m_row - height;
	Rectangle(bottomLeft, topRight);
}

Vertex Rectangle::getBottomLeft() const
{

	return m_bottomLeft;//m_bl_col, m_bl_row
}

Vertex Rectangle::getTopRight() const
{
	return m_topRight; //m_tr_col, m_bl_col
}

double Rectangle::getWidth() const
{
	return m_width; //m_tr_col - m_bl_col
}

double Rectangle::getHeight() const
{
	return m_height; // m_tr_row - m_bl_row
}

