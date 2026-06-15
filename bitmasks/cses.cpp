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

#define ull unsigned long long
#define ll long long

// También por patrón de posiciones de bits.
// https://cses.fi/problemset/task/1146
void solv()
{
  ll n;
  cin>>n;
  if(n==1){
    cout<<"1\n";
    return;
  }
  int cnt=0;
  ll ans=0;
  for(int i=50; i>=0; i--){
    ll bit=(1ll<<i); // 101 >>1 =10
    if(n&bit){
      // 2*1 + 1*1
      ans+=bit*cnt+i*(bit/2);
      cnt++;
    }
  }
  cln(ans+cnt);
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
