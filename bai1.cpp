#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout << "nhap he so a, b, c:";
    double a, b, c;
    cin >> a >> b >> c;

    if (a != 0) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        cout << "phuong trinh vo nghiem";
    } else if (delta == 0) {
        cout << "phuong trinh co nghiem kep:";

        double x = -b / (2 * a);
        cout << "x= " << x << "\n";
        }
         if (delta > 0){
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "phuong trinh co 2 nghiem phan biet:\n";
            cout << "x1= " << x1 << "\n";
            cout << "x2= " << x2 << "\n";
        }
        if (b != 0){
        double x = -c / b;
        cout << "phuong trinh bac nhat:\n";
        cout << "x= " << x << "\n";
        }
        else {
            if (c != 0) {
            cout << "phuong trinh vo nghiem";
        }

        }
    return 0;
    }
}
   