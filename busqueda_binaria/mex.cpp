#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

using ll = long long;
#define vec vector
#define sz(x) int(x.size())

// {0, 2, 1}, {}

bool eval(vec<ll> &a, int k, int x){
  vec<int> apari(x, -1);
  int tot=0, cnt=0;
  for(auto e: a){
    if(e<x && apari[e]!=tot){
      apari[e]=tot;
      cnt++;
    }
    if(cnt==x){
      tot++;
      cnt=0;
    }
  }
  return tot>=k;
}

void solve()
{
  int n, k;
  cin>>n>>k;
  vec<ll> a(n);
  for(int i=0; i<n; i++) cin>>a[i];
  int inf=0, sup=n+1, mid;
  while(inf+1<sup){
    mid=(inf+sup)/2;
    if(eval(a, k, mid)) inf=mid;
    else sup=mid;
  }
  cout<<inf<<'\n';
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
