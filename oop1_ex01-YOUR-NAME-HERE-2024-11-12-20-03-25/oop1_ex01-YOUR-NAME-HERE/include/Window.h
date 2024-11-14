pragma once
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Window
{
 public:
	Window(const Rectangle& rectangle, const Vertex& point);
	Window(const Vertex& topRight, double width, double height, const Vertex& point);
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	Vertex getPoint() const;
 private:

	Rectangle rectangle;
	Vertex point;

};