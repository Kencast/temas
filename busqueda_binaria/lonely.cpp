#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

using ll = long long;

#define vec vector
#define sz(x) (int)(x).size()


bool eval(int x, vec<int> &a){
  int n=sz(a);
  vec<int> cnt(20);
  for(int i=0; i<x; i++) for(int bit=0; bit<20; bit++)
    if(a[i]&(1<<bit)) cnt[bit]++;
  for(int i=x; i<n; i++){
    for(int bit=0; bit<20; bit++){
      int zero=(cnt[bit]==0);
      if(a[i-x]&(1<<bit)) cnt[bit]--;
      if(a[i]&(1<<bit)) cnt[bit]++;
      if(zero!=(cnt[bit]==0)) return false;
    }
  }
  return true;
};

void solve()
{
  int n;
  cin>>n;
  vec<int> a(n);
  for(int i = 0; i < n; i++) cin>>a[i];
  int inf=0, sup=n+1, mid;
  while(inf+1<sup){
    mid=(inf+sup)/2;
    if(eval(mid, a)) sup=mid;
    else inf=mid;
  }
  cout<<sup<<'\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}