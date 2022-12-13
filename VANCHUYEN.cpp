
/// (^_^) Author : Cau_be_thieu_nang

#include <bits/stdc++.h>
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define FIRST_BIT(mask) __builtin_ctz((mask)&(-mask))
#define ERASE_BIT(mask) (mask)^((mask)&(-mask))
#define left _left
#define right _right
#define task "t"
using namespace std;
const ll INF=1e18;
const int iat=1e6+9;
const int mod=1e9+7;
void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
int n,m,k;
ll ta,tb,a[iat],b[iat],ans=-1;
signed main()
{
    fast_IO();
    cin>>n>>m>>ta>>tb>>k;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=m; i++)cin>>b[i];
    if(k>=n)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0; i<=k; i++)
    {
        int x=k-i;
        ll TimeToB=ta+a[1+i];
        int pos=lower_bound(b+1,b+m+1,TimeToB)-b;
        if(pos!=m+1 && m-pos+1>x)ans=max(ans,b[pos+x]+tb);
        else
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
}
