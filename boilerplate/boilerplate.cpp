#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

// #define int long long
#define ll long long
#define F first
#define S second
#define endl '\n'
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define g(i,m,n) for(int i=m; i<=n; i++)
#define asc(a) (a).begin(),(a).end()
#define desc(a) (a).rbegin(),(a).rend()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pa1(a,n) g(i,1,n) cout<<a[i]<<" "; cout<<endl;
#define pa(a) for(auto e: a) cout<<e<<" "; cout<<endl;
#define ia1(a,n) vector<int> a(n+1); g(i,1,n) cin>>a[i];
#define ia(a,n) vector<int> a(n); f(i,n) cin>>a[i];
#define iall(a,n) vector<ll> a(n); f(i,n) cin>>a[i];

const ll mod = 1e9+7;
const ll INF = 1e9;

ll power(ll a,ll b) {return b==0?1:1LL*power(1LL*a*a%mod,b/2)*(b%2?a:1)%mod;}
ll inverse(ll x) {return power(x,mod-2);}

void solve() {
    
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    f(i,t) {
        // cout<<"Case #"<<i+1<<":\n";
        solve();
    }
    return 0;
}