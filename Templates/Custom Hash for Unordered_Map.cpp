// To prevent collision in unordered_map
#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
/*Random number in [l, r] range. _real_ for double
mt19937_64 rng(FIXED_RANDOM);
ll x = uniform_int_distribution<ll>(l, r)(rng); */

/// Declaration: unordered_map <int, int, custom_hash> numbers;
/// Usage: same as normal unordered_map
/// Ex: numbers[5] = 2;

/// *** To use gp_hash_table (faster than unordered_map) ****  ///
/// Add these extra two lines:
/// #include <ext/pb_ds/assoc_container.hpp>
/// using namespace __gnu_pbds;

/// Declaration: gp_hash_table<int, int, custom_hash> numbers;
/// Usage: Same as unordered_map
