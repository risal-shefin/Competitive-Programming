/// Minimum radius of circle to enclose all points of a polygon
/// Converting polygon to convex hull before any calculation reduces complexity

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define iter 30000   /// The more the number of iteration, the more accurate the result is

struct point {
    ll x, y;
} p[100005];

ll n;
double X, Y, d, e;

double dist(double a, double b) {
	return a*a + b*b;
}

int main() {

	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld %lld", &p[i].x, &p[i].y);
		X += p[i].x; Y += p[i].y;
	}
	X /= n; Y /= n;   /// Average center

	double mv = 0.1;
	for (ll i = 0; i < iter; i++) {
		ll f = 0;
		d = dist(X - p[0].x, Y - p[0].y);
		for (ll j = 1; j < n; j++) {

			e = dist(X - p[j].x, Y - p[j].y);
			if (d < e) { d = e; f = j; }
		}

		/// Moving center towards the farthest point slightly
		X += (p[f].x - X) * mv;
		Y += (p[f].y - Y) * mv;
		mv *= 0.999;
	}

	printf("X = %.3f Y = %.3f , radius = %.3f\n", X, Y, sqrt(d));
}
