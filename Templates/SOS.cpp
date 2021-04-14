/// Given a fixed array A of 2^N integers, we need to calculate
/// the function F(x) = Sum of all A[i] such that x&i = i, i.e., i is a subset of x.
/// It means i is the subset bitmask of the bitmask of x.

/// Suboptimal Bruteforce Method O(3^n):
// iterate over all the masks
for (int mask = 0; mask < (1<<n); mask++) {
    F[mask] = A[0];
    // iterate over all the subsets of the mask
    for(int i = mask; i > 0; i = (i-1) & mask){
        F[mask] += A[i];
    }
}

/// Two DP methods O(n*2^n):
/// iterative version
for(int mask = 0; mask < (1<<N); mask++){
    dp[mask][0] = A[mask];	//handle base case separately (leaf states)
    for(int i = 0;i < N; i++){
        if(mask & (1<<i))
            dp[mask][i + 1] = dp[mask][i] + dp[mask^(1<<i)][i];
        else
            dp[mask][i + 1] = dp[mask][i];
    }
    F[mask] = dp[mask][N];
}

/// memory optimized, super easy to code.
for(int i = 0; i<(1<<N); i++)
    F[i] = A[i];
for(int i = 0;i < N; ++i) {
    for(int mask = 0; mask < (1<<N); ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];
    }
}
