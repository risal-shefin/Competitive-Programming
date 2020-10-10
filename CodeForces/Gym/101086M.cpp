#include <bits/stdc++.h>
using namespace std;

struct exam {
    int s;
    int e;
    exam(int st, int en) {
        s = st;
        e = en;
    }
};

bool cmp(exam a, exam b)

{
    if(a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}

int main()

{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map <string, vector <exam> > vol;
        map <string, vector <exam> > :: iterator it;

        while(n--) {
            string name;
            cin >> name;
            int start, stop, num;
            cin >> start >> stop >> num;

            while(num--) {
                string s;
                cin >> s;

                vol[s].push_back( exam(start, stop) );
            }

        }

        vector <string> ans;
        for(it = vol.begin(); it != vol.end(); it++) {
            sort( (it -> second).begin(), (it -> second).end(), cmp);

            //cout << (it -> second)[0].e << endl;
            for(int i = 0; i < (it -> second).size() - 1; i++) {
                if( (it -> second)[i].e >= (it -> second)[i + 1].s) {
                    ans.push_back(it -> first);
                    //cout << it -> first << endl;
                    break;
                }
            }

        }

        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;

        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;

    }

    return 0;
}