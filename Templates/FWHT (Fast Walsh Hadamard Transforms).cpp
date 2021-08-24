/*
 * Fast Walsh Hadamard Transforms for XOR, AND, OR Convolution
 * Let, A = {1,2,2}, B = (3,4,5)
 * All possible XOR between A, B will be:
    C = {1,1,2,4,5,6,6,7,7}
 * Let, p1 is the frequency array of A,
        p2 is the frequency array of B,
        res will be the frequency array of C.
 * FWHT calculates the res array in O(mlogm),
   where m is the size of the res array.
*/

// Define which is needed
#define bitwiseXOR
//#define bitwiseAND
//#define bitwiseOR

void FWHT(vector <ll> &p, bool inverse)
{
    int n = p.size();
    while(n&(n-1)) {
        p.pb(0);
        n++;
    }

    for(int len = 1; 2*len <= n; len <<= 1) {
        for(int i = 0; i < n; i += len+len) {
            for(int j = 0; j < len; j++) {
                ll u = p[i+j];
                ll v = p[i+len+j];

                #ifdef bitwiseXOR
                p[i+j] = u+v;
                p[i+len+j] = u-v;
                #endif // bitwiseXOR

                #ifdef bitwiseAND
                if(!inverse) {
                    p[i+j] = v;
                    p[i+len+j] = u+v;
                }
                else {
                    p[i+j] = v-u;
                    p[i+len+j] = u;
                }
                #endif // bitwiseAND

                #ifdef bitwiseOR
                if(!inverse) {
                    p[i+j] = u+v;
                    p[i+len+j] = u;
                }
                else {
                    p[i+j] = v;
                    p[i+len+j] = u-v;
                }
                #endif // bitwiseOR
            }
        }
    }

    #ifdef bitwiseXOR
    if(inverse) {
        for(int i = 0; i < n; i++)
            p[i] /= n;
    }
    #endif // bitwiseXOR
}

vector <ll> calc(vector <ll> &p1, vector <ll> &p2)
{
    FWHT(p1, 0), FWHT(p2, 0);
    vector <ll> res(p1.size());

    for(int i = 0; i < res.size(); ++i)
        res[i] = p1[i] * p2[i];

    FWHT(res, 1);
    return res;
}
// Just call calc(p1, p2);
// Note: p1, p2, res all are frequency arrays.
