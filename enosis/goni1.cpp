#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INT __int128
#define ff first
#define ss second
#define INF 1e18
#define pi acos(-1)
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define pii pair<int,int>
#define pll pair<ll,ll>
ll mod = 1000000007;
int fx[] = {0,0,-1,1};
int fy[] = {1,-1,0,0};
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<ll>::iterator lower,lw, upper,ip;
  ll t=1,ii;
  cin>>t;
  for(ii=1; ii<=t ;ii++)
  {
    ll n,i,j,x,l,r;
    vector<ll>v;

    cin>>n>>l>>r;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for(i=0;i<n;i++)
    {
        if(v[i]>=r) continue;
        ll z = 0;
        ll a = l-v[i];
        ll b = r-v[i];

        lower = lower_bound(v.begin(), v.end(),a);
        upper = upper_bound(v.begin(), v.end(),b);
        upper--;

        ll tt =(upper - v.begin())-(lower-v.begin())+1;
        ans+=tt;

        if(l<=2*v[i] && 2*v[i]<=r) ans--;
    }
    cout<<ans/2<<endl;
  }
}