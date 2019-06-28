#include <bits/stdc++.h>
using namespace std;
int main()
{
	string seq, s1, s2;
	cin >> seq >> s1 >> s2;
	int len = seq.length();
	int len1 = s1.length();
	int len2 = s2.length();
	string seq2 = seq;
	reverse(seq2.begin(), seq2.end());
	bool forward = 0, backward = 0, checker1 = 0, checker2 = 0;
	for(int i = 0; i < len; i++) {
        if(checker1 == 1) {
			if(seq.substr(i, len2) == s2) {
				checker2 = 1;
				break;
			}
		}
        if(checker1 == 0) {
            if(seq.substr(i, len1) == s1) {
                checker1 = 1;
                i += len1 - 1;
            }
        }
	}
	if(checker1 == 1 && checker2 == 1) {
		forward = 1;
	}
	checker1 = 0, checker2 = 0;
	for(int i = 0; i < len; i++) {
        if(checker1 == 1) {
			if(seq2.substr(i, len2) == s2) {
				checker2 = 1;
				break;
			}
		}
        if(checker1 == 0) {
            if(seq2.substr(i, len1) == s1) {
                checker1 = 1;
                i += len1 - 1;
            }
        }
	}
	if(checker1 == 1 && checker2 == 1) {
		checker1 = 0;
		checker2 = 0;
		backward = 1;
	}
	if(forward == 0) {
		if(backward == 1)
			cout << "backward" << endl;
		else
			cout << "fantasy" << endl;
	}
	else if(forward == 1) {
		if(backward == 1)
			cout << "both" << endl;
		else
			cout << "forward" << endl;
	}
	return 0;
}
