//Online FFT Trick. O(nlog^2n)
//dp[i] = Sum of dp[j]*B[i-j -1] for j in range [0,i-1]
//Problem Link: https://www.codechef.com/problems/MANCBST

void online_fft(int n)
{
    vector<int> vec1,vec2,res;
    dp[0] = 1; // Base Case

    for(int i = 0; i <= n; i++){
        // We've computed till dp[i] and want to add its contribution.
        // -1 from the B[i-j -1] of the recurrence
        dp[i + 1] = (dp[i+1] + (dp[i] * B[1 -1])) % mod;
        dp[i + 2] = (dp[i+2] + (dp[i] * B[2 -1])) % mod;

        int pw = 1, tmp = i;
        while(tmp && (tmp&1)==0) {
            tmp >>= 1; pw <<= 1;
            vec1.clear(); vec2.clear();

            int l1=i-pw, r1=i-1, l2=pw+1, r2=min(pw+pw, n);

            for(int j=l1; j<=r1; j++) vec1.push_back(dp[j]);
            // -1 from the B[i-j -1] of the recurrence
            for(int j=l2; j<=r2; j++) vec2.push_back(B[j -1]);

            if(!vec1.empty() && !vec2.empty())
                res = ntt::multiply(vec1, vec2);

            int Beg = l1+l2;
            for(int j=0; j<res.size() && Beg+j<=n; j++){
                dp[Beg+j] += res[j];
                if(dp[Beg+j]>=mod) dp[Beg+j]-=mod;
            }
        }
    }
}
