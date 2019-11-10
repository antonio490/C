
// Programming using templates
#include <iostream>
using namespace std;

template <class T>
inline void swap(T& d, T& s){
    T temp = d;
    d = s;
    s = temp;
}

template <class summable>
summable sum(const summable data[], int size, summable s = 0){
    for(int i = 0; i < size; i++)
        s += data[i];
    return s;
}

int main(){

    int m = 5, n = 10;
    double x = 5.3, y = 10.6;
    complex<double> r(2.4, 3.5), s(3.4, 6.7);

    cout << "inputs:" << m << ", " << n << endl;
    swap(m,n);
    cout << "outputs:" << m << ", " << n << endl;

    cout << "double inputs:" << x << ", " << y << endl;
    swap(x, y);
    cout << "double outputs:" << x << ", " << y << endl;

    cout << "complex inputs:" << r << ", " << s << endl;
    swap(r, s);
    cout << "complex outputs:" << r << ", " << s << endl;


}