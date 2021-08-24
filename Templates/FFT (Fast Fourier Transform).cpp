/***
   * Multiply (7x^2 + 8x^1 + 9x^0) with (6x^1 + 5x^0)
   * ans = 42x^3 + 83x^2 + 94x^1 + 45x^0
   * A = {9, 8, 7}
   * B = {5, 6}
   * V = multiply(A,B)
   * V = {45, 94, 83, 42}
***/

/*** Tricks
   * Use vector < bool > if you need to check only the status of the sum
   * Use bigmod if the power is over same polynomial && power is big
   * Use long double if you need more precision
   * Use long long for overflow
***/
typedef vector <int> vi;
const double PI = 2.0 * acos(0.0);
using cd = complex<double>;

void fft(vector<cd> & a, bool invert = 0)

{
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

void ifft(vector <cd> & p)

{
    fft(p, 1);
}

vi multiply(vi const& a, vi const& b)

{

    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa);
    fft(fb);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    ifft(fa);

    vi result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    return result;
}
