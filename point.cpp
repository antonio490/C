#include <iostream>
using namespace std;

// Now within a language like Java, C++ or Python, where you allow natural type 
// extensibility, and you allow it efficiently, you get to. In C++ a Class is 
// equivalent to struct in C - but with different data hiding defaults.

class point{

    // Constructor with arguments
    point(){ x = y = 0.0;}

    point(){ 
        this->x = 0.0;
        this->y = 0.0;
    }

    public:
        double getx() {return x;}
        void setx(double v){ x = v;}

    private:
        double x, y;
};

point operator+ (point& p1, point& p2){
    point sum = {p1.x + p2.x, p1.y + p2.y};
    return sum;
}

ostream& operator<< (ostream& out, const point& p){
    out << "(" << p.x << "," << p.y <<" )";
    return out;
}

// usual signature for overloading ostream& oeprator<<
// (ostream& out, const my_type& v)
// both arguments are passed by reference
// my_type is passed with a const modifier
// so as not to be modified

int main(){

    point a = {3.5, 2.5}, b = {5.5, 7.2};
    cout << "a = " << a << " b = " << b << endl;;
    cout << "sum = " << a + b << endl;
}