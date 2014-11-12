#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define acc(a) accumulate(a.begin(), a.end(), 0LL, [&](ll x, ll y) {return x ^ y;})
void Qmin(vl &a, const vl b) {if (acc(b) < acc(a)) a = b;}

int main()
{
	ll l, r, k, x;
	cin >> l >> r >> k;
	vl ans = {l};
	if (k >= 2)
	{
		Qmin(ans, {l, l + 1});
		if (l + 2 <= r) Qmin(ans, {l + 1, l + 2});
	}
	if (k >= 3)
	{
		x = 1LL << (64 - __builtin_clzll(l));
		if (x + x / 2 <= r) ans = {x - 1, x + x / 2, x + x / 2 - 1};
	}
	if (k >= 4)
	{
		Qmin(ans, {l, l + 1, l + 2, l + 3});
		if (l + 4 <= r) Qmin(ans, {l + 1, l + 2, l + 3, l + 4});
	}
	cout << acc(ans) << '\n' << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}
