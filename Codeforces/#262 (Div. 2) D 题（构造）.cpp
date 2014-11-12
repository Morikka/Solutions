/* 
@link http://codeforces.com/contest/460/problem/D
@author Σndless

构造。
关键在于两个相邻元素的异或可能会很小。
当集合中有两个元素时，答案可能是l^(l+1)，但l=1011时就不太合适，这种情况下(l+1)^(l+2)就更好，此时异或为1。
当集合中有四个元素时，可能出现异或为0的情况，也要考虑，方法与有两个元素时类似。
当集合中有三个元素时，唯一可以使异或为0的构造是找到一个大于l的2^k数，令其为x。
此时异或的结果已经达到最小，更大的集合大小就不用考虑了。
比如x=10000，那么
x-1=1111，
x+x/2=11000，
x+x/2-1=10111。
此时三者异或恰好为0，并且这组数恰好是所有三元组中最大数(这里为x+x/2)最小的。

@see http://endless.logdown.com/posts/2014/08/21/codeforces-round-262-div-2
*/

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
	return 0;
}
