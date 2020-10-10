#include <bits/stdc++.h>

using namespace std;

#define dd double
#define pi acos(-1.0)
#define eps 1e-9

int main()

{
    dd R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    dd tmp1 = R * R;
    dd dx = abs(x1 - x2), dy = abs(y1 - y2);
    dd dis = (dx * dx) + (dy * dy);

    if(dis > tmp1) {
        //cout << x1 << " " << y1 << " " << R << endl;
        printf("%0.9f %0.9f %0.9f\n", x1, y1, R);
        return 0;
    }

    if( abs(dis - 0.0) <= eps) {
        dd r = R / 2.0;
        dd x = x1 + r;
        //cout << x << " " << y1 << " " << r << endl;
        printf("%0.9f %0.9f %0.9f\n", x, y1, r);

        return 0;
    }

    dis = sqrt(dis);
    dd r = (R + dis) / 2.0;
    dd m1 = r, m2 = r - dis;
    dd x = (m1 * x1 - m2 * x2) / (m1 - m2);
    dd y = (m1 * y1 - m2 * y2) / (m1 - m2);
    //cout << x << " " << y << " " << r << endl;
    printf("%0.9f %0.9f %0.9f\n", x, y, r);

    return 0;
}