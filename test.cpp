#include <iostream>
#include <cmath>

using namespace std;

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}

int main() {
    int a, b;
    cout << "Nhap hai so nguyen a va b: ";
    cin >> a >> b;

    cout << "UCLN cua " << a << " va " << b << " la: " << UCLN(a, b) << endl;
    cout << "BCNN cua " << a << " va " << b << " la: " << BCNN(a, b) << endl;

    return 0;
}