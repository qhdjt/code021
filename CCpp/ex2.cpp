#include <iostream>

struct point
{
    int x;
    int y;
};

std::ostream &operator<<(std::ostream &out, const point &p)
{
    out << "struct \"Point\":{point.x:" << p.x << ",point.y:" << p.y << "}\n";
    return out;
};

// int main(int argc, char const *argv[])
int main()
{
    point p1{1, 2}; // construction
    std::cout << "p1==>" << p1;
    point p2 = p1; // copy construction
    std::cout << "p2==>" << p2;
    p2.x = 4;
    point p3(p1); // copy construction
    std::cout << "p3==>" << p3;
    point p4{p1}; // copy construction
    std::cout << "p4==>" << p4;
    auto p5 = p1; // copy construction
    std::cout << "p5==>" << p5;
    auto p6(p1); // copy construction
    std::cout << "p6==>" << p6;
    auto p7{p1}; // copy construction
    std::cout << "p7==>" << p7;
    p3 = p2; // copy assignment
             // (both p2 & p3 existed before)
    std::cout << "p3==>" << p3;
    return 0;
}
