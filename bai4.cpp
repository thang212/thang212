#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    while (n < 0)
    {
        cout << "Nhap lai so n: ";
        cin >> n;
    }
    
    long long f0 = 0, f1 = 1, fn;
    if (n == 0) {
        fn = f0;
    } else if (n == 1) {
        fn = f1;
    } else {
        for (int i = 2; i <= n; i++) {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
    }
    cout << "So Fibonacci thu " << n << " la: " << fn << endl;
    return 0;
}
// Dương Hiển Thắng MSSV:077207005603