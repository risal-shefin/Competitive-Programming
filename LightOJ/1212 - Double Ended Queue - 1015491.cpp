#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, i, n, m, siz, num;
    string s;
    cin >> T;
    for(i = 1; i <= T; i++) {
        deque <int> q;
        siz = 0;
        cout << "Case " << i << ":\n";
        scanf("%d %d", &n, &m);
        cin.ignore();
        while(m--) {
              string temp;
            getline(cin, temp);
            stringstream scut(temp);
            scut >> s;
            scut >> num;
              if(s == "pushLeft") {
                if(siz == n) {
                    cout << "The queue is full\n";
                }
                else {
                    cout << "Pushed in left: " << num << endl;
                    q.push_front(num);
                    siz++;
                }
            }
              else if(s == "pushRight") {
                if(siz == n) {
                    cout << "The queue is full\n";
                }
                  else {
                    q.push_back(num);
                    cout << "Pushed in right: " << num << endl;
                    siz++;
                }
            }
              else if(s == "popLeft") {
                if(siz == 0) {
                    cout << "The queue is empty\n";
                }
                else {
                    cout << "Popped from left: " << q.front() << endl;
                    q.pop_front();
                    siz--;
                }
            }
              else if(s == "popRight") {
                if(siz == 0) {
                    cout << "The queue is empty\n";
                }
                  else {
                    cout << "Popped from right: " << q.back() << endl;
                    q.pop_back();
                    siz--;
                }
            }
          }
    }
      return 0;
}
