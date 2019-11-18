// Now within a language like Java, C++ or Python, where you allow natural type 
// extensibility, and you allow it efficiently, you get to. In C++ a Class is 
// equivalent to struct in C - but with different data hiding defaults.

class point{

    public:
        double getx() {return x;}
        void setx(double v){ x = v;}

    private:
        double x, y;
};