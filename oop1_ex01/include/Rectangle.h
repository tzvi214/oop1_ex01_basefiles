#pragma once
#include <Vertex.h>


class Rectangle
{
  public:
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Vertex getBottomLeft()  const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;
	

  private:

	double m_bl_col, m_bl_row; // bottomLeft
	double m_tr_col, m_tr_row; // topRight
	double m_width, m_height;
	   
};

