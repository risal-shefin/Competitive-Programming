#include<bits/stdc++.h>

using namespace std;

#define ll       long long

#define  sci(x)   scanf("%d", &x)
#define  scl(x)   scanf("%lld", &x)
#define  scd(x)   scanf("%lf", &x)

#define  pfi(x)   printf("%d", x)
#define  pfl(x)   printf("%lld", x)
#define  pfd(x)   printf("%lf", x)
#define  pfc(x)   printf("Case %d: ", x++)
#define  ps       printf(" ")
#define  pn       printf("\n")

#define  pb       push_back
#define  ppb      pop_back
#define  pf       push_front
#define  ppf      pop_front
#define  In       insert
#define  All(a)   a.begin(), a.end()
#define pll pair <ll, ll>
#define start first
#define len second

const int MAXN = 100005;
ll data[MAXN], a[MAXN];

struct Tree
{
	ll sum;
	ll lazy;
	pll info;
};

Tree tree[MAXN * 4];

void build(int node, int low, int high)
{
	//cout << node << ' ' << low << ' ' << high << endl;
	if(low == high)
	{
		tree[node].sum = data[low];
		tree[node].lazy = 0;
		tree[node].info = make_pair(0, 0);
		return;
	}

	int left = node * 2;
	int right = left + 1;
	int mid = (low + high) >> 1;

	build(left, low, mid);
	build(right, mid + 1, high);

	//tree[node].sum = tree[left].sum + tree[right].sum;
	tree[node].lazy = 0;
}

void update(int node, int low, int high, int lr, int hr, ll st, ll ln)
{
	//cout << low << ' ' << high << ' ' << lr << ' ' << hr << endl;
	if(tree[node].lazy)
	{

		if(low != high)
		{
			tree[node * 2].info = tree[node].info;
			tree[node * 2 + 1].info = tree[node].info;

			tree[node * 2].lazy = 1;
			tree[2 * node + 1].lazy = 1;
		}

		tree[node].lazy = 0;
	}

	if(low > hr || high < lr)
		return;

	//cout << low << ' ' << high << endl;

	if(low >= lr && high <= hr)
	{
		tree[node].info = make_pair(st, ln);
		tree[node].lazy = 1;
		//cout << low << "  " << high << " " << node << endl;

		return;
	}

	int left = node * 2;
	int right = left + 1;
	int mid = (low + high) >> 1;

	update(left, low, mid, lr, hr, st, ln);
	update(right, mid + 1, high, lr, hr, st, ln);

	//tree[node].sum = tree[left].sum + tree[right].sum;
}

ll query(int node, int low, int high, int lr, int hr)
{
	if(low > hr || high < lr)
		return 1e18;

	if(tree[node].lazy)
	{
		//cout << low << " " << high << endl;
		if(low != high)
		{
			tree[node * 2].info = tree[node].info;
			tree[node * 2 + 1].info = tree[node].info;

			tree[node * 2].lazy = 1;
			tree[2 * node + 1].lazy = 1;
		}

		tree[node].lazy = 0;
	}

	if(low >= lr && high <= hr)
	{
		if(tree[node].info.start == 0) {
			return data[low];
		}

		ll pos = tree[node].info.start + (low - tree[node].info.len);
				//cout << pos << endl;
		return a[pos];
	}

	int left = node * 2;
	int right = left + 1;
	int mid = (low + high) >> 1;

	ll p = query(left, low, mid, lr, hr);
	p = min(p, query(right, mid + 1, high, lr, hr) );

	return p;
}



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
	ll n, q;
	cin >> n >> q;
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(ll i = 1; i <= n; i++) 
		scanf("%lld", &data[i]);

	build(1, 1, n);

	while(q--) {
		ll t, x, y, k;
		scl(t);
		if(t == 1) {
			scl(x), scl(y), scl(k);
			update(1, 1, n, y, y + k - 1, x, y);
		}
		else {
			scl(x);
			printf("%lld\n", query(1, 1, n, x, x));
		}
	}
    return 0;
}