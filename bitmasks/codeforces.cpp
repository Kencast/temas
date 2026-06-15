#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(ARG) cout << "[" << #ARG << "]: " << ARG << endl
#else
#define debug(ARG) 42
#endif

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

#define ll long long

const ll MOD = 998'244'353;

ll get0(ll x){
  if(x<3) return 1;
  return (2 + (x - 3) / 4)%MOD;
}

ll get1(ll x){
  if(!x) return 0;
  return ((x - 1) / 4 + 1)%MOD;
}

// https://codeforces.com/contest/2225/problem/D
void solv()
{
  ll n, x;
  cin>>n>>x;
  ll ans=get0(x-1)*(get0(n)-get0(x-1)+MOD)%MOD;
  ans+=get1(x-1)*(get1(n)-get1(x-1)+MOD)%MOD;
  cln(ans%MOD);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solv();
  return 0;
}