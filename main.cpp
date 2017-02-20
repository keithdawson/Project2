#include <iostream>
using namespace std;
#include "MyDynamicArray.cpp"

int main() {
    MyDynamicArray x;
    for (int i=0; i<100; i++){
        x.add(i);
    }
    int sum = 0;
    for (int i=0; i<x.length(); i++){
        sum+=x[i];
    }   
    cout << "The sum is : " << sum << endl;
    for (int i=0; i<95; i++)
        x.del();
    x[60] = 27;
    
    MyDynamicArray y(10);
    for (int i=0; i<y.length(); i++) y[i] = i*i;
    for (int i=0; i<200; i++){
        y.add(i);
    }
    sum = 0;
    for (int i=0; i<y.length(); i++){
        sum+=y[i];
    }   
    cout << "The sum is : " << sum << endl;
    for (int i=0; i<195; i++)
        y.del();
    y[60] = 27;
    for (int i=0; i<200; i++){
        y.add(i);
    }
    sum = 0;
    for (int i=0; i<y.length(); i++){
        sum+=y[i];
    }   
    cout << "The sum is : " << sum << endl;
    
}