#pragma once
#include "Vertex.h"
#include "Board.h"

class Rectangle
{
  public:
	

  Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
  Rectangle(const Vertex vertices[2]);
  Rectangle(double x, double y, double width, double height);
  Rectangle(const Vertex& topRight, double width, double height);

	
  Rectangle getBoundingRectangle() const;
  double getPerimeter() const;
  double getArea()const;
  Vertex getCenter() const;


  bool scale(double factor);
  void draw(Board& board)const;
  
  Vertex getBottomLeft()  const;
  Vertex getTopRight() const;
  double getWidth() const;
  double getHeight() const;
	
	

  private:

   bool isLegal(const Vertex& bottomLeft, const Vertex& topRight);
   Vertex m_bottomLeft;
   Vertex m_topRight;
   double m_width, m_height;
	   
};

