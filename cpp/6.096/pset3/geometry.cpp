#include <algorithm>
#include <cmath>
#include "geometry.h"

// 4 PointArray
PointArray::PointArray(const Point new_points[], const int new_size){
    size = new_size;
    points = new Point[new_size];
    for (int i = 0; i < new_size; ++i){
        points[i] = new_points[i];
    }
}

PointArray::PointArray(const PointArray &pv){
    size = pv.size;
    points = new Point[size];
    for (int i = 0; i < size; ++i){
        points[i] = pv.points[i];
    }
}

void PointArray::resize(int new_size){
    Point *new_p = new Point[new_size];
    for (int i = 0; std::min(size, new_size); ++i){
        new_p[i] = points[i];
    }
    delete[] points;
    size = new_size;
    points = new_p;
}

void PointArray::push_back(const Point &p){
    resize(size + 1);
    points[size - 1] = p;
}

void PointArray::insert(const int position, const Point &p){
    resize(size + 1);
    for (int i = size - 1; i > position; --i){
        points[i] = points[i -1];
    }
    points[position] = p;
}

void PointArray::remove(const int pos){
    for (int i; i < size - 2; ++i){
        points[i] = points[i + 1];
    }
    resize(size - 1);
}

void PointArray::clear(){
    resize(0);
}

Point *PointArray::get(const int position){
    return position < size && position >= 0 ? points + position : NULL;
}

const Point *PointArray::get(const int position) const{
    return position < size && position >= 0 ? points + position : NULL;
}

// 5 Polygon
int Polygon::total_polygons = 0;

Polygon::Polygon(const Point points_array[], const int len) : points(points_array, len){
    total_polygons++;
}
Polygon::Polygon(const PointArray &points_array) : points(points_array){
    total_polygons++;
}

// 5 Rectangle
Point constructorPoints [4];

Point *updateConstructorPoints ( const Point &p1 , const Point &p2 , const Point &p3 , const Point &p4 = Point (0 ,0)){
    constructorPoints [0] = p1;
    constructorPoints [1] = p2;
    constructorPoints [2] = p3;
    constructorPoints [3] = p4;
    return constructorPoints;
}

Rectangle::Rectangle(const Point &bottom_left, const Point &top_right)
    : Polygon(updateConstructorPoints(bottom_left, top_right, Point(bottom_left.getX(), top_right.getY()), Point(top_right.getX(), bottom_left.getY())), 4)
{}

Rectangle::Rectangle(const int a, const int b, const int c, const int d)
    : Polygon(updateConstructorPoints(Point(a, b), Point(c, d), Point(a, d), Point(c, b)), 4)
{}

double Rectangle::area() const{
    int w, h;
    w = points.get(1)->getX() - points.get(0)->getX();
    h = points.get(1)->getY() - points.get(0)->getY();
    return w * 1.0 * h;
}

// 5 Triangle
Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
    : Polygon(updateConstructorPoints(p1, p2, p3), 3)
{}

double Triangle::area() const{
    double a, b, c, s;
    int a1, a2, b1, b2, c1, c2;

    a1 = points.get(0)->getX() - points.get(1)->getX();
    a2 = points.get(0)->getY() - points.get(1)->getY();
    b1 = points.get(1)->getX() - points.get(2)->getX();
    b2 = points.get(1)->getY() - points.get(2)->getY();
    c1 = points.get(2)->getX() - points.get(0)->getX();
    c2 = points.get(2)->getY() - points.get(0)->getY();

    a = std::sqrt(a1*a1 + a2*a2);
    b = std::sqrt(b1*b1 + b2*b2);
    c = std::sqrt(c1*c1 + c2*c2);
    s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}