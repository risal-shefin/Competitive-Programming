#include <bits/stdc++.h>
using namespace std;
#define ll long long
/////////////////////////////////////////////////////////////////////////////////////////
// Aho-Corasick's algorithm, as explained in  http://dx.doi.org/10.1145/360825.360855  //
/////////////////////////////////////////////////////////////////////////////////////////
const ll MAXS = 500 * 500 + 10; // Max number of states in the matching machine.
                              // Should be equal to the sum of the length of all keywords.
const ll MAXC = 26; // Number of characters in the alphabet.
bitset <505> out[MAXS]; // Output for each state, as a bitwise mask.
               // Bit i in this mask is on if the keyword with index i appears when the
               // machine enters this state.
// Used internally in the algorithm.
ll f[MAXS]; // Failure function
ll g[MAXS][MAXC]; // Goto function, or -1 if fail.
// Builds the string matching machine.
//
// words - Vector of keywords. The index of each keyword is important:
//         "out[state] & (1 << i)" is > 0 if we just found word[i] in the text.
// lowestChar - The lowest char in the alphabet. Defaults to 'a'.
// highestChar - The highest char in the alphabet. Defaults to 'z'.
//               "highestChar - lowestChar" must be <= MAXC, otherwise we will
//               access the g matrix outside its bounds and things will go wrong.
//
// Returns the number of states that the new machine has.
// States are numbered 0 up to the return value - 1, inclusive.
ll buildMatchingMachine(const vector<string> &words, char lowestChar = 'a', char highestChar = 'z') {
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
      ll states = 1; // Initially, we just have the 0 state
      for (ll i = 0; i < words.size(); ++i) {
        const string &keyword = words[i];
        ll currentState = 0;
        for (ll j = 0; j < keyword.size(); ++j) {
            ll c = keyword[j] - lowestChar;
            if (g[currentState][c] == -1) { // Allocate a new node
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState][i] = 1; // There's a match of keywords[i] at node currentState.
    }
      // State 0 should have an outgoing edge for all characters.
    for (ll c = 0; c < MAXC; ++c) {
        if (g[0][c] == -1) {
            g[0][c] = 0;
        }
    }
      // Now, let's build the failure function
    queue<ll> q;
    for (ll c = 0; c <= highestChar - lowestChar; ++c) {  // Iterate over every possible input
        // All nodes s of depth 1 have f[s] = 0
        if (g[0][c] != -1 and g[0][c] != 0) {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size()) {
        ll state = q.front();
        q.pop();
        for (ll c = 0; c <= highestChar - lowestChar; ++c) {
            if (g[state][c] != -1) {
                ll failure = f[state];
                while (g[failure][c] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure]; // Merge out values
                q.push(g[state][c]);
            }
        }
    }
      return states;
}
// Finds the next state the machine will transition to.
//
// currentState - The current state of the machine. Must be between
//                0 and the number of states - 1, inclusive.
// nextInput - The next character that enters into the machine. Should be between lowestChar
//             and highestChar, inclusive.
// lowestChar - Should be the same lowestChar that was passed to "buildMatchingMachine".
// Returns the next state the machine will transition to. This is an integer between
// 0 and the number of states - 1, inclusive.
ll findNextState(ll currentState, char nextInput, char lowestChar = 'a') {
    ll answer = currentState;
    ll c = nextInput - lowestChar;
    while (g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}
    // How to use this algorithm:
//
// 1. Modify the MAXS and MAXC constants as appropriate.
// 2. Call buildMatchingMachine with the set of keywords to search for.
// 3. Start at state 0. Call findNextState to incrementally transition between states.
// 4. Check the out function to see if a keyword has been matched.
//
// Example:
//
// Assume keywords is a vector that contains {"he", "she", "hers", "his"} and text is a string
// that contains "ahishers".
//
// Consider this program:
//
// buildMatchingMachine(v, 'a', 'z');
// ll currentState = 0;
// for (ll i = 0; i < text.size(); ++i) {
//    currentState = findNextState(currentState, text[i], 'a');
//    if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
//    for (ll j = 0; j < keywords.size(); ++j) {
//        if (out[currentState] & (1 << j)) { // Matched keywords[j]
//            cout << "Keyword " << keywords[j] << " appears from "
//                 << i - keywords[j].size() + 1 << " to " << i << endl;
//        }
//    }
// }
//
// The output of this program is:
//
// Keyword his appears from 1 to 3
// Keyword he appears from 4 to 5
// Keyword she appears from 3 to 5
// Keyword hers appears from 4 to 7
/////////////////////////////////////////////////////////////////////////////////////////
//                          End of Aho-Corasick's algorithm.                           //
/////////////////////////////////////////////////////////////////////////////////////////
ll ans[505];
int main()
{
      std::ios_base::sync_with_stdio(false);
    vector<string> keywords;
    string text = "", s;
      ll t, caseno = 0;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cin >> text;
        for(ll i = 0; i < 505; i++) {
            ans[i] = 0;
        }
          keywords.clear();
        for(ll i = 1; i <= n; i++) {
            cin >> s;
            keywords.push_back(s);
        }
        buildMatchingMachine(keywords, 'a', 'z');
        ll currentState = 0;
        for (ll i = 0; i < text.size(); ++i) {
              currentState = findNextState(currentState, text[i], 'a');
            if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
            for (ll j = 0; j < keywords.size(); ++j)
            {
                if (out[currentState][j])  // Matched keywords[j]
                {
//                    cout << "Keyword " << keywords[j] << " appears from "
//                         << i - keywords[j].size() + 1 << " to " << i << endl;
                    ans[j]++;
                }
            }
          }
          cout << "Case " << ++caseno << ":" << endl;;
        for(ll i= 0; i < n; i++)
            cout << ans[i] << endl;
    }
      return 0;
}
 
