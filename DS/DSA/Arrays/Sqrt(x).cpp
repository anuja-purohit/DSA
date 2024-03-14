#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int x) {
    int s = 0;
    int e = x;
    long long int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e) {
        if (mid * mid == x) {
            return mid;
        }

        if (mid * mid > x) {
            e = mid - 1;
        }

        if (mid * mid < x) {
            ans = mid;
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

float precisionSqrt(int n, int ans, int precision) {
    float multiplicand;
    int exponent = -1;
    multiplicand = power(10, exponent);

    while (precision <= abs(exponent)) {
        for (int i = 0; ans * ans < n; i++) {
            ans = ans + (multiplicand);
        }
        exponent--;
    }
    return ans;
}

int main() {
    int x, precision;
    cout << "Find square root of: ";
    cin >> x;
    cout << "with precision upto: ";
    cin >> precision;

    float ans_integer = binarySearch(x);
    float ans_decimal = precisionSqrt(x, ans_integer, precision);
    cout << "The answer is: " << ans_integer + ans_decimal << endl;

    return 0;
}
