#include <iostream>
#include <vector>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }
};

class Figure {
public:
    virtual void print() const = 0;
};

class Vector {
private:
    vector<Point> points;
public:
    void addPoint(const Point& p) {
        points.push_back(p);
    }

    void print() const {
        for (const auto& p : points) {
            cout << "(" << p.getX() << ", " << p.getY() << ")\n";
        }
    }
};

class Circle : public Figure {
private:
    Point center;
    double radius;
public:
    Circle(Point c, double r) : center(c), radius(r) {}

    void print() const override {
        cout << "Circle with center (" << center.getX() << ", " << center.getY() << ") and radius " << radius << endl;
    }
};

class Rectangle : public Figure {
private:
    Point topLeft, bottomRight;
public:
    Rectangle(Point tl, Point br) : topLeft(tl), bottomRight(br) {}

    void print() const override {
        cout << "Rectangle with top-left (" << topLeft.getX() << ", " << topLeft.getY() << ") and bottom-right (" << bottomRight.getX() << ", " << bottomRight.getY() << ")\n";
    }
};

class Triangle : public Figure {
private:
    Point vertex1, vertex2, vertex3;
public:
    Triangle(Point v1, Point v2, Point v3) : vertex1(v1), vertex2(v2), vertex3(v3) {}

    void print() const override {
        cout << "Triangle with vertices (" << vertex1.getX() << ", " << vertex1.getY() << "), "
            << "(" << vertex2.getX() << ", " << vertex2.getY() << "), "
            << "(" << vertex3.getX() << ", " << vertex3.getY() << ")\n";
    }
};

class Polygon : public Figure {
private:
    vector<Point> vertices;
public:
    Polygon(const vector<Point>& verts) : vertices(verts) {}
    void print() const override {
        cout << "Polygon with vertices: ";
        for (const auto& vertex : vertices) {
            cout << "(" << vertex.getX() << ", " << vertex.getY() << ") ";
        }
        cout << endl;
    }
};

int main() {
    Vector points;
    points.addPoint(Point(1, 2));
    points.addPoint(Point(3, 4));

    cout << "Points in vector:\n";
    points.print();

    vector<Figure*> figures;
    figures.push_back(new Circle(Point(0, 0), 5));
    figures.push_back(new Rectangle(Point(0, 0), Point(2, 3)));
    figures.push_back(new Triangle(Point(1, 1), Point(4, 1), Point(2, 5)));
    figures.push_back(new Polygon({ Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2) }));

    cout << "\nFigures:\n";
    for (auto figure : figures) {
        figure->print();
    }

    for (auto figure : figures) {
        delete figure;
    }

    return 0;
}
