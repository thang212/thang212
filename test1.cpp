#include <iostream>
using namespace std;

int main() {
    cout << "nhập 3 số:";
    int a, b, c;
    cin >> a >> b >> c;

    int max;
    if (a >= b && a >= c){
        max = a;
    } else if (b >= a && b >= c){
        max = b;
    } else {
        max = c;
    }
    cout << "số lớn nhất là: " << max;

    int min;
    if (a <= b && a <= c){
        min = a;
    } else if (b <= a && b <= c){
        min = b;
    } else {
        min = c;
    }
    cout << "\nsố nhỏ nhất là: " << min;
    if (a ==b && a ==c){
        cout << "\ncả 3 số bằng nhau";
    }
    return 0;
}