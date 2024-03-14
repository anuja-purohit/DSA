// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin>>n;
    double x= log2(n);
    if (floor(x) == x)
    cout << "Can be written in the power "<< x <<" of 2";
    else
    cout << "Cannot be written in the power of 2";
    return 0;
}