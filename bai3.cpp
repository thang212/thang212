#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "nhap do dai 3 canh tam giac a, b, c:";
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) {
        cout << "3 canh tren tao thanh 1 tam giac";
    } else {
        cout << "3 canh tren khong tao thanh 1 tam giac";
        }
    if (a == b && b == c) {
        cout << "\nTam giac deu";
    } else if (a == b || b == c || a == c) {
        cout << "\nTam giac can";
    } else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
        cout << "\nTam giac vuong";
    } else {
        cout << "\nTam giac thuong";
    }
    double chuvi = a + b + c;
    cout << "\nChu vi tam giac: " << chuvi;
    double p = chuvi / 2;
    
    double dientich = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "\nDien tich tam giac: " << dientich;
    return 0;
}
// Dương Hiển Thắng MSSV:077207005603