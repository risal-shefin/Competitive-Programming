#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
struct node {
    ll rem, pls, id;
};
 
struct comp{
    bool operator()(node left, node right){
        return left.rem < right.rem;
    }
};
 
ll ara[200009], cnt[200009], used[200009];
 
int main()
 
{
    ll n, m;
    cin >> n>> m;
 
    ll ct = n / m;
 
    multiset <node, comp> info;
    multiset <node, comp> :: iterator it1, it2;
    node tmp;
    for(ll i = 0; i < n; i++) {
        scanf("%lld", &ara[i]);
 
        ll rem = ara[i] % m;
 
        cnt[rem]++;
    }
 
    for(ll i = 0; i < n; i++) {
        ll rem = ara[i] % m;
 
        if(cnt[rem] <= ct)
            continue;
 
        used[rem]++;
        if(used[rem] <= ct)
            continue;
 
        tmp.rem = rem;
        tmp.id = i;
        tmp.pls = 0;
 
        info.insert(tmp);
    }
 
    ll mv = 0;
    for(ll i = 0; i < m; i++) {
        if(cnt[i] >= ct)
            continue;
 
        ll x = i;
        ll lim = 0;
        if(x == 0) {
            x = m;
            lim = 1;
        }
 
        ll j;
        bool check = 0;
        tmp.rem = x, tmp.id = 0, tmp.pls = 0;
        it1 = info.lower_bound(tmp);
        if(it1 == info.begin()) {
            check = 1;
            goto s;
        }
        it1--;
        j = it1 -> rem;
 
        for(; j >= lim; )
        {
            ll rm = it1 -> rem;
            ll dif = x - rm;
            mv += dif;
            ll me = it1 -> id;
            ara[ me ] += dif;
 
            cnt[i]++;
 
            //cout << "  fff " << info.size() << endl;
            info.erase(it1);
            if(info.size() == 0)
                break;
            if(cnt[i] == ct)
                break;
 
            tmp.rem = j + 1, tmp.id = 0, tmp.pls = 0;
            it1 = info.lower_bound(tmp);
            if(it1 == info.begin()) {
                check = 1;
                break;
            }
            it1--;
            j = it1 -> rem;
            //cout << info.size() << endl;;
        }
 
        s:
        if(check)
        {
 
            while(1)
            {
                it1 = info.end();
                it1--;
                j = (it1 -> rem);
                ll dif = m - j + i;
                ll me = it1 -> id;
                mv += dif;
                ara[ me ] += dif;
 
                cnt[i]++;
 
                info.erase(it1);
                if(info.size() == 0)
                    break;
                if(cnt[i] == ct)
                    break;
            }
        }
        //cout << 5;
    }
 
    printf("%lld\n", mv);
    for(ll i = 0; i < n; i++) {
        if(i != 0)
            printf(" ");
        printf("%lld", ara[i]);
    }
 
    cout << endl;
 
    return 0;
}