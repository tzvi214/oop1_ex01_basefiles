#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <format>

#include "macros.h"
#include "Vertex.h"
#include "Board.h"
using namespace std;
#define RECTANGLE           0
#define TRIANGLE            0
#define ISOSCELES_TRIANGLE  0
#define WINDOW              1


#if RECTANGLE
#include "Rectangle.h"
void printInfo(const Rectangle&);
#endif

#if TRIANGLE
#include "Triangle.h"
void printInfo(const Triangle&);
#endif

#if ISOSCELES_TRIANGLE
#include "IsoscelesTriangle.h"
void printInfo(const IsoscelesTriangle&);
#endif

#if WINDOW
#include "Window.h"
void printInfo(const Window&);
#endif

void waitForEnter();
Vertex readVertex(std::string_view vertexName, std::string_view shapeName);

template <typename Shape>
void useShape(Shape& shape, std::string_view shapeName);

template <typename Shape>
void draw(const Shape& shape, Board&);

template <typename Shape>
void printGenericInfo(const Shape& shape, std::string_view shapeName);

// �������� to_string ���� Vertex
std::string to_string(const Vertex& v) {
    return "(" + std::to_string(v.m_col) + ", " + std::to_string(v.m_row) + ")";
}

int main()
{
    

#if RECTANGLE
    {
        static constexpr auto shapeName = std::string_view("rectangle");

        const auto vertices = std::array<Vertex, 2>
        {
            readVertex("bottom-left", shapeName),
                readVertex("top-right", shapeName)
        };

        std::cin.ignore(); // ignore the enter

        auto rectangle = Rectangle(vertices.data());
        useShape(rectangle, shapeName);
    }
#endif // RECTANGLE
//
//#if TRIANGLE
//    {
//        static constexpr auto shapeName = std::string_view("triangle");
//
//        const auto vertices = std::array<Vertex, 3>
//        {
//            readVertex("first", shapeName),
//                readVertex("second", shapeName),
//                readVertex("third", shapeName)
//        };
//
//        std::cin.ignore(); // ignore the enter
//
//        auto triangle = Triangle(vertices.data());
//        useShape(triangle, shapeName);
//    }
//#endif // TRIANGLE

#if ISOSCELES_TRIANGLE
    {
        static constexpr auto shapeName = std::string_view("isosceles triangle");

        const auto vertices = std::array<Vertex, 3>
        {
            readVertex("first", shapeName),
                readVertex("second", shapeName),
                readVertex("third", shapeName)
        };

        std::cin.ignore(); // ignore the enter

        auto isoscelesTriangle = IsoscelesTriangle(vertices.data());
        useShape(isoscelesTriangle, shapeName);
    }
#endif // ISOSCELES_TRIANGLE

#if WINDOW
    {

        static constexpr auto shapeName = std::string_view("window");

        const auto vertices = std::array<Vertex, 2>
        {
            readVertex("bottom-left", shapeName),
                readVertex("top-right", shapeName)
        };

        const auto rect = Rectangle(vertices.data());
        const auto point = readVertex("split point", shapeName);

        auto window = Window(rect, point);
        useShape(window, shapeName);
    }
#endif // WINDOW
}

#if RECTANGLE
void printInfo(const Rectangle& rectangle)
{
    static constexpr auto shapeName = std::string_view("rectangle");

    const auto printVertex = [](const Vertex& v, std::string_view vertexName)
        {
            std::cout << "The " << vertexName << " vertex of the " << shapeName << " is: " << to_string(v) << "\n";
        };

    printVertex(rectangle.getBottomLeft(), "bottom-left");
    printVertex(rectangle.getTopRight(), "top-right");
}
#endif // RECTANGLE

#if ISOSCELES_TRIANGLE
void printInfo(const IsoscelesTriangle& isoscelesTriangle)
{
    static constexpr auto shapeName = std::string_view("isosceles triangle");

    std::cout << "The height of the " << shapeName << " is: " << isoscelesTriangle.getHeight() << "\n";
}
#endif // ISOSCELES_TRIANGLE

#if WINDOW
void printInfo(const Window& window)
{
    static constexpr auto shapeName = std::string_view("window");

    const auto printVertex = [](const Vertex& v, std::string_view vertexName)
        {
            std::cout << "The " << vertexName << " vertex of the " << shapeName << " is: " << to_string(v) << "\n";
        };

    printVertex(window.getBottomLeft(), "bottom-left");
    printVertex(window.getTopRight(), "top-right");

    std::cout << "The split point of the " << shapeName << " is: " << to_string(window.getPoint()) << "\n";
}
#endif // WINDOW

void waitForEnter()
{
    std::cout << "Press Enter to continue...\n";
    auto line = std::string();
    std::getline(std::cin, line);
}

Vertex readVertex(std::string_view vertexName, std::string_view shapeName)
{
    std::cout << "Please enter x and y coordinates for the " << vertexName << " vertex of the " << shapeName << ":\n";
    auto v = Vertex();
    std::cin >> v;
    return v;
}

template<typename Shape>
void useShape(Shape& shape, std::string_view shapeName)
{
    auto board = Board();
    auto print = [&]
        {
            draw(shape, board);
            printInfo(shape);
            printGenericInfo(shape, shapeName);
            waitForEnter();
        };

    print();

    board.clear();
    std::cout << "Now scaled by factor of 2:\n\n";
    if (shape.scale(2))
    {
        print();
    }
    else
    {
        std::cout << "Scaling failed!\n";
        waitForEnter();
    }
}

template<typename Shape>
void draw(const Shape& shape, Board& board)
{
    shape.draw(board);
    board.print();
    waitForEnter();

    std::cout << "Now with the bounding rectangle:\n";
    auto boundingRect = shape.getBoundingRectangle();
    boundingRect.draw(board);
    board.print();
    waitForEnter();
}

template<typename Shape>
void printGenericInfo(const Shape& shape, std::string_view shapeName)
{
    std::cout << "The perimeter of the " << shapeName << " is: " << shape.getPerimeter() << "\n";
    std::cout << "The area of the " << shapeName << " is: " << shape.getArea() << "\n";
    std::cout << "The center of the " << shapeName << " is: " << to_string(shape.getCenter()) << "\n";
}