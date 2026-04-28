#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-4;
void getCircle(double x1, double y1, double x2, double y2, double x3, double y3,
               double &x0, double &y0, double &R) {
    double A = x2 - x1, B = y2 - y1;
    double C = x3 - x1, D = y3 - y1;
    double E = (x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1) / 2.0;
    double F = (x3 * x3 + y3 * y3 - x1 * x1 - y1 * y1) / 2.0;
    double det = A * D - B * C;
    x0 = (E * D - B * F) / det;
    y0 = (A * F - E * C) / det;
    R = hypot(x1 - x0, y1 - y0);
}
int main(){
	double x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    double x0, y0, R;
    getCircle(x[0], y[0], x[1], y[1], x[2], y[2], x0, y0, R);
    double angle[3];
    for (int i = 0; i < 3; ++i) {
        angle[i] = atan2(y[i] - y0, x[i] - x0);
    }
    sort(angle, angle + 3);
    double delta[3];
    delta[0] = angle[1] - angle[0];
    delta[1] = angle[2] - angle[1];
    delta[2] = 2*PI - (delta[0] + delta[1]);
    int n = 3;
    for (int m = 3; m <= 100; ++m) {
        bool ok = true;
        for (int i = 0; i < 3; ++i) {
            double k = delta[i] * m / (2*PI);
            double rk = round(k);
            if (fabs(k - rk) > EPS) {
                ok = false;
                break;
            }
        }
        if (ok) {
            n = m;
            break;
        }
    }
    double area = 0.5 * n * R * R * sin(2*PI / n);
    cout << fixed << setprecision(8) << area << endl;
	return 0;
}


