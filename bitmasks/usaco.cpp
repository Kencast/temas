#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

using ll = long long;
using lf = double;

#define forn(i, n) for(int i=0; i<n; i++)
#define dforn(i, n) for (int i=(n)-1; i >= 0; i--)
#define vec vector
#define all(n) begin(n),end(n)
#define cln(a) cout << a << '\n'
#define ce(a) cout << a << ' '
#define ln cout << '\n'
#define sz(x) (int)(x).size()

typedef pair<long long, long long> ii;
typedef vec<long long> vi;

struct cow{
  long long h, w, st;
};


/*
Recursivo

vec<ll> dp(1<<20);
int n;
vec<cow> a;

ll cal(int msk){
  if(dp[msk]!=0) return dp[msk];
  ll ans=-1;
  for(int i=0; i<n; i++) if(msk&(1<<i)==0) 
    ans=max(ans, min(cal(msk|(1<<i))-a[i].w, a[i].st));
  return dp[msk]=ans;
}
*/

// https://usaco.org/index.php?page=viewproblem2&cpid=494&lang=en
void solv()
{
  // Descomentar para enviar en usaco
  //freopen("guard.in", "r", stdin);
  //freopen("guard.out", "w", stdout);
  int n, h;
  cin>>n>>h;
  vec<cow> c(n);
  for(int i=0; i<n; i++){
    cin>>c[i].h>>c[i].w>>c[i].st;
  }
  int estados=1<<n;
  vec<long long> dp(estados, -1);
  dp[0]=1e10;
  ll ans=-1;
  for(int msk=1; msk<estados; msk++) for(int i=0; i<n; i++){
    int bit=1<<i;
    if(msk&bit){
      dp[msk]=max(dp[msk], min(c[i].st, dp[msk^bit]-c[i].w));
    }
  }
  for(int msk=1; msk<estados; msk++){
    long long sum=0;
    for(int i=0; i<n; i++) if(msk&(1<<i)) sum+=c[i].h;
    if(sum>=h) ans=max(ans, dp[msk]);
  }
  if(ans<0) cout<<"Mark is too tall\n";
  else cout<<ans<<'\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--)
    solv();
  return 0;
}
