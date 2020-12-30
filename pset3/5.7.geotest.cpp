#include <iostream>
#include "geometry.cpp"

using namespace std;

void printAttributes(Polygon *p){
    const PointArray *p_array = p->getPoints();
    cout << "Area: " << p->area() << endl;
    cout << "Points: ";
    for (int i = 0; i < p_array->getSize(); ++i){
        cout << "(" << p_array->get(i)->getX() << "," << p_array->get(i)->getY() << ") ";
    cout << endl;
    }

}

int main(){
    int x1, y1, x2, y2, x3, y3;
    cout << "What are the lower left and upper right corners of your rectangle?" << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle r(Point(x1, y1), Point(x2, y2));
    printAttributes(&r);
    cout << "What are the three points of your triangle?" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Triangle t(Point(x1, y1), Point(x2, y2), Point(x3, y3));
    printAttributes(&t);
}