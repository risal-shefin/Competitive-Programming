#define ll long long
const ll N = 1e5+10;
int tree[N][26], idx;
ll len[N], link[N], cnt[N], t;
char s[N]; // 1-indexed

void add(ll p) {

    while(s[p - len[t] - 1] != s[p]) t = link[t];   // searching node for creating pTp type palindrome.
    ll x = link[t], c = s[p] - 'a';
    while(s[p - len[x] - 1] != s[p]) x = link[x];   // searching node to link pXp type palindrome, where pXp is a proper suffix.
    if(!tree[t][c]) {
        tree[t][c] = ++idx;
        len[idx] = len[t] + 2;
        link[idx] = len[idx] == 1 ? 2 : tree[x][c];
    }
    t = tree[t][c];
    cnt[t]++;
}
/* node 1 and node 2 are the two roots.
 * idx-2 is the number of total distinct palindromes in the string s.
 * Let, a node is i,
 * len[i] represents the length of the palindrome represented by node i.
 * link[i] represents the node containing the palindrome which is the largest proper suffix
 * of the palindrome of node i.
*/

int main()
{
    len[1] = -1, link[1] = 1;
    len[2] = 0, link[2] = 1;
    idx = t = 2;
    memset(tree, 0, sizeof(tree));
    memset(cnt, 0, sizeof(cnt));

    scanf("%s", s+1);
    ll len = strlen(s+1);
    for(ll i = 1; i <= len; i++) add(i);    // adding each index in pal tree one by one. O(len).

    for(ll i = idx; i > 2; i--) cnt[ link[i] ] += cnt[i];   // adding count to the suffix link.
    // cnt[i] now holds the count of the palindrome represented by node i in the string s.

    return 0;
}
