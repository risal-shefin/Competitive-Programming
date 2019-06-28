#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque <int> card;
    int sareja = 0, dima = 0;
    int n;
    cin >> n;
    while(n--) {
        int in;
        cin >> in;
        card.push_back(in);
    }
    bool state = 0;
    while(!card.empty()) {
        int tmp;
        if(card.front() > card.back()) {
            tmp = card.front();
            card.pop_front();
        }
        else {
            tmp = card.back();
            card.pop_back();
        }
        if(state == 0) {
            state = 1;
            sareja += tmp;
        }
        else {
            state = 0;
            dima += tmp;
        }
    }
    cout << sareja << " " << dima << endl;
    return 0;
}
