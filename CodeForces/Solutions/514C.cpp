#include <bits/stdc++.h>
using namespace std;

    namespace MostSignificantBit {

        const int SIZE = 1 << 16;

        uint8_t table[SIZE];

        bool WasInitialized() { return table[2]; }

        bool Init() {
            for (int i = 1; i < SIZE; ++i) {
                for (uint8_t pow = 0; pow < 16; ++pow) {
                    if ((i >> pow) & 1) {
                        table[i] = pow;
                    }
                }
            }
            return true;
        }

        int Get(int value) { return WasInitialized() || Init(), table[value & (SIZE-1)]; }
    }

    struct uint128_t {

        uint64_t high, low;

        uint128_t(uint64_t high_, uint64_t low_) : high(high_), low(low_) { }

        uint128_t(uint64_t low_ = 0) : high(0), low(low_) { }
    };

    bool operator==(uint128_t lhs, uint128_t rhs) { return lhs.low == rhs.low && lhs.high == rhs.high; }
    bool operator<=(uint128_t lhs, uint128_t rhs) { return lhs.high < rhs.high || (lhs.high == rhs.high && lhs.low <= rhs.low); }
    bool operator>=(uint128_t lhs, uint128_t rhs) { return rhs <= lhs; }
    bool operator!=(uint128_t lhs, uint128_t rhs) { return !(lhs == rhs); }
    bool operator< (uint128_t lhs, uint128_t rhs) { return !(lhs >= rhs); }
    bool operator> (uint128_t lhs, uint128_t rhs) { return !(lhs <= rhs); }

    int mostSignificantBit32(uint32_t value) {
        return (value >> 16) ? MostSignificantBit::Get(value >> 16) + 16 : MostSignificantBit::Get(value);
    }

    int mostSignificantBit64(uint64_t value) {
        return (value >> 32) ? mostSignificantBit32(uint32_t(value >> 32)) + 32 : mostSignificantBit32(value & ~uint32_t(0));
    }

    int mostSignificantBit(uint128_t value) {
        return value.high ? mostSignificantBit64(value.high) + 64 : mostSignificantBit64(value.low);
    }

    uint128_t operator+(uint128_t lhs, uint128_t rhs) {
        uint128_t ret(lhs.high + rhs.high, lhs.low + rhs.low);
        ret.high += (ret.low < lhs.low);
        return ret;
    }

    uint128_t operator-(uint128_t lhs, uint128_t rhs) {
        uint128_t ret(lhs.high - rhs.high, lhs.low - rhs.low);
        ret.high -= (lhs.low < ret.low);
        return ret;
    }

    uint128_t& operator+=(uint128_t& lhs, uint128_t rhs) { return lhs = lhs + rhs; }
    uint128_t& operator-=(uint128_t& lhs, uint128_t rhs) { return lhs = lhs - rhs; }

    uint128_t operator<<(uint128_t lhs, int cnt) {
        if (cnt == 0) { return lhs; }
        if (cnt >= 64) { return uint128_t(lhs.low << (cnt - 64), 0); }
        return uint128_t((lhs.high << cnt) | (lhs.low >> (64-cnt)), lhs.low << cnt);
    }

    uint128_t operator>>(uint128_t lhs, int cnt) {
        if (cnt == 0) { return lhs; }
        if (cnt >= 64) { return uint128_t(lhs.high >> (cnt-64)); }
        return uint128_t(lhs.high >> cnt, (lhs.low >> cnt) | (lhs.high << (64 - cnt)));
    }

    uint128_t& operator>>=(uint128_t& lhs, int cnt) { return lhs = lhs >> cnt; }
    uint128_t& operator<<=(uint128_t& lhs, int cnt) { return lhs = lhs << cnt; }

    uint128_t operator*(uint128_t lhs, uint128_t rhs) {
        uint64_t a32 = lhs.low >> 32, a00 = lhs.low & 0xffffffff;
        uint64_t b32 = rhs.low >> 32, b00 = rhs.low & 0xffffffff;
        uint128_t ret(lhs.high * rhs.low + lhs.low * rhs.high + a32 * b32, a00 * b00);
        return ret + (uint128_t(a32 * b00) << 32) + (uint128_t(a00 * b32) << 32);
    }

    void DivMod(uint128_t a, uint128_t b, uint128_t &q, uint128_t &r) {
        assert(b.low | b.high);
        if (a < b) { q = 0, r = a; return; }
        if (a == b) { q = 1, r = 0; return; }
        const int shift = mostSignificantBit(a) - mostSignificantBit(b);
        q = 0, r = a, b <<= shift;
        for (int i = 0; i <= shift; ++i) {
            q <<= 1;
            if (r >= b) { r -= b; q.low |= 1; }
            b >>= 1;
        }
    }

    uint128_t operator/(uint128_t lhs, uint128_t rhs) {
        uint128_t div, rem;
        return DivMod(lhs, rhs, div, rem), div;
    }

    uint128_t operator%(uint128_t lhs, uint128_t rhs) {
        uint128_t div, rem;
        return DivMod(lhs, rhs, div, rem), rem;
    }

    uint128_t& operator/=(uint128_t &lhs, uint128_t rhs) { return lhs = lhs / rhs; }
    uint128_t& operator%=(uint128_t &lhs, uint128_t rhs) { return lhs = lhs % rhs; }

#define ll long long
#define LL uint128_t
const LL base = 37;

LL pw[600009];
char s[600009];
map <LL, bool> check;


int main()

{
    pw[0] = 1;
    for(ll i = 1; i <= 600001; i++)
        pw[i] = pw[i-1] * base;

    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        scanf("%s", s+1);

        LL h = 0;
        for(ll j = 1; s[j] != '\0'; j++)
            h = h * base + (s[j] - 'a' + 1);

        check[h] = 1;
    }

    while(q--) {
        scanf("%s", s + 1);
        LL h = 0, h2 = 0;
        for(ll j = 1; s[j] != '\0'; j++)
            h = h * base + (s[j] - 'a' + 1);

        ll len = strlen(s+1);
        bool chk = 0;
        for(ll j = 1; s[j] != '\0'; j++) {
            h2 = h;
            h2 = h2 - (s[j] - 'a' + 1) * pw[len - j];

            for(char c = 'a'; c <= 'c'; c++) {
                if(c == s[j])
                    continue;

                if(check.find(h2 + (c - 'a' + 1) * pw[len - j]) != check.end()) {
                    chk = 1;
                    break;
                }
            }
            if(chk)
                break;
        }

        if(chk)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}