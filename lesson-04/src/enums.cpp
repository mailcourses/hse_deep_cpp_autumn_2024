#include <iostream>

enum Shape
{
    SH_CIRCLE,
    SH_TRIANGLE,
    SH_SQUARE,
    SH_NONE
};

enum Color
{
    C_WHITE,
    C_BLUE,
    C_RED,
    C_NONE
};

enum class ShapeClass
{
    CIRCLE,
    TRIEANGLE,
    SQUARE,
    NONE
};

enum class ColorClass
{
    WHITE,
    BLUE,
    RED,
    NONE
};

int main()
{
    Shape shape1 = SH_SQUARE;
    if (shape1 == SH_SQUARE) {
        std::cout << "SQUARE" << std::endl;
    }

    Color color1 = C_RED;

    ColorClass color2 = ColorClass::RED;
    ShapeClass shape2 = ShapeClass::SQUARE;
}
