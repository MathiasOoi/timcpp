// 3 Point
class Point{
    private:
        int x, y;
    public:
        Point(int xi = 0, int yi = 0) {x = xi; y = yi;}
        int getX() const {return x;}
        int getY() const {return y;}
        void setX(const int new_x) {x = new_x;}
        void setY(const int new_y) {y = new_y;}
};
// 4 PointArray
class PointArray{
    private:
        Point *points;
        int size;
        void resize(int size);

    public:
        PointArray() {points = new Point[0]; size = 0;}
        PointArray(const Point new_points[], const int new_size);
        PointArray(const PointArray &pv);
        ~PointArray() {delete[] points;}

        void push_back(const Point &p);
        void insert(const int position, const Point &p);
        void remove(const int pos);
        int getSize() const {return size;}
        void clear();
        Point *get(const int position);
        const Point *get(const int position) const;

        
};

// 5 Polygon
class Polygon{
    protected:
        static int total_polygons;
        PointArray points;
    public:
        Polygon(const Point points_array[], const int len);
        Polygon(const PointArray &points_array);
        ~Polygon(){total_polygons--;}

        virtual double area() const = 0;
        static int getNumPolygons() {return total_polygons;}
        int getNumSides() const {return points.getSize();}
        const PointArray *getPoints() const {return &points;}
};

//5 Rectangle
class Rectangle : public Polygon{
    public:
        Rectangle(const Point &bottom_left, const Point &top_right);
        Rectangle(const int a, const int b, const int c, const int d);
        virtual double area() const;
};

// 5 Triangle
class Triangle : public Polygon{
    public:
        Triangle(const Point &p1, const Point &p2, const Point &p3);
        virtual double area() const;
};