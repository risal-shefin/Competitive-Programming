#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
      for(int i = 1; i <= T; i++) {
          stack <string> f, b;
        string com, url, cur, in;
        cur = "http://www.lightoj.com/";
        cout << "Case " << i << ":\n";
          while(getline(cin, in) && in.compare("QUIT") != 0) {
              stringstream s(in);
            s >> com;
            s >> url;
              if(!f.empty() && com.compare("FORWARD") == 0) {
                b.push(cur);
                cur = f.top();
                cout << cur << endl;
                f.pop();
            }
            else if(f.empty() && com.compare("FORWARD") == 0) {
                cout << "Ignored\n";
            }
              if(!b.empty() && com.compare("BACK") == 0) {
                f.push(cur);
                cur = b.top();
                cout << cur << endl;
                b.pop();
            }
            else if(b.empty() && com.compare("BACK") == 0) {
                cout << "Ignored\n";
            }
              if(com.compare("VISIT") == 0) {
                b.push(cur);
                cur = url;
                cout << cur << endl;
                while(!f.empty())
                    f.pop();
            }
          }
      }
      return 0;
}
