#include <iostream>
using namespace std;

// Sum an array in C

double sum(double data[], int size){

    double s = 0.0; int i;
    for(i = 0; i < size; i++)
        s += data[i];
    return s;
}

// Generic sum an array by default sum starts by zero

template <class T>
T sum(const T data[], int size, T s=0){

    for(int i=0; i<size; i++)
        s += data[i];
    return s;
}

int main(){

    cout << "template for sum()" << endl;
    int a[] = {1,2,3};
    double b[] = {2.1, 2.2, 2.3};
    cout << sum(a,3) << endl;
    cout << sum(b,3) << endl;

}
