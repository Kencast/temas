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

bool eval(vector<int> &a, int k, double x){
  long long tot=0;
  for(auto v: a) tot+=int(v/x);
  return tot>=k;
}

void solve()
{
  int n, k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin>>a[i];
  double err=1e-6;
  double inf=0, sup=2e7, mid;
  while(inf+err<sup){
    mid=(inf+sup)/2;
    if(eval(a, k, mid)) inf=mid;
    else sup=mid;
  }
  cout<<fixed<<setprecision(6);
  cout<<inf<<'\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  //cin >> t;
  while (t--)
    solve();
  return 0;
}
