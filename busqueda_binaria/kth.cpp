#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

using ll = long long;

#define sz(x) (int)(x).size()
#define vec vector

bool eval(ll x, vec<ll> &a, ll k){
  int cntLess=lower_bound(a.begin(), a.end(), x+1)-a.begin();
  return x-cntLess>=k;
}

void solve()
{
  int n, q;
  cin>>n>>q;
  vec<ll> a(n);
  for(int i=0; i<n; i++) cin>>a[i];
  while(q--){
    ll k; cin>>k;
    ll inf=0, sup=2e18, mid;
    while(inf+1<sup){
      mid=(inf+sup)/2;
      if(eval(mid, a, k)) sup=mid;
      else inf=mid;
    }
    cout<<sup<<'\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--)
    solve();
  return 0;
}