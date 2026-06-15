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


// https://atcoder.jp/contests/abc365/tasks/abc365_e
void solv()
{
  int n;
  cin>>n;
  vec<int> a(n);
  for(int i=0; i<n; i++) cin>>a[i];
  long long ans=0;
  for(int b=0; b<27; b++){
    int bit=(1<<b);
    int c0=1, c1=0, cnt=0;
    long long sum=0;
    for(int r=0; r<n; r++){
      if(a[r]&bit) cnt++;
      if(cnt%2) c1++, sum+=c0;
      else c0++, sum+=c1;
    }
    ans+=sum*bit;
  }
  cln(ans-accumulate(a.begin(), a.end(), 0ll));
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
