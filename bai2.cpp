#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "nhap so nguyen: ";
    cin >> n;

    if (n < 2) {
        cout << n << " khong phai so nguyen to";
        return 0;
    }
    bool songuyento = true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            songuyento = false;
            break;
        }
    }
    if (songuyento) {
        cout << n << " la so nguyen to";
    } else {
        cout << n << " khong phai la so nguyen to";
    }
    return 0;
}