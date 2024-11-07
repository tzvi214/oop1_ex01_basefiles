#include <Vertex.h>
#include <Vertex.h>
#include <Rectangle.h>
#include <macros.h>
#include <iostream>
using namespace std;


Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	//cout << "@@@@@@@@@@@@@@@@@@@@@" << endl;
	if (bottomLeft.m_col < 0 || bottomLeft.m_col > MAX_COL ||
		bottomLeft.m_row < 0 || bottomLeft.m_row > MAX_ROW ||
		topRight.m_col < 0 || topRight.m_col > MAX_COL ||
		topRight.m_row < 0 || topRight.m_row > MAX_ROW ||
		bottomLeft.m_col > topRight.m_col || bottomLeft.m_row > topRight.m_row)
	{
		m_bl_col = 20, m_bl_row = 10;
		m_tr_col = 30, m_tr_row = 20;
		m_width = m_tr_col - m_bl_col, // 
		m_height = m_tr_row - m_bl_row;
		
		//cout << "not good" << endl;


	}
	else
	{
		m_bl_col = bottomLeft.m_col , m_bl_row = bottomLeft.m_row;
		m_tr_col = topRight.m_col, m_tr_row = topRight.m_row;
		m_width = m_tr_col - m_bl_col,
		m_height = m_tr_row - m_bl_row;

		//cout << "good" << endl;


	};

}

Vertex Rectangle::getBottomLeft() const
{

	return Vertex(m_bl_col, m_bl_row);
}

Vertex Rectangle::getTopRight() const
{
	return Vertex(m_tr_col, m_bl_col);
}

double Rectangle::getWidth() const
{
	return (m_tr_col - m_bl_col);
}

double Rectangle::getHeight() const
{
	return (m_tr_row - m_bl_row);
}

