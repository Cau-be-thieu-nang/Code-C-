
/// (*^_^*) Author : Cau_be_thieu_nang

#include <bits/stdc++.h>
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define FIRST_BIT(mask) __builtin_ctz((mask)&(-mask))
#define ERASE_BIT(mask) (mask)^((mask)&(-mask))
#define left _left
#define right _right
#define task "SAMPLE"
#define data _data
using namespace std;
const ll INF=1e18;
const int iat=3e5+9;
const int mod=1e9+7;
void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen(task".INP","r"))
    {
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
}
int n,m,c[iat];
ll ans;
struct data
{
    int p,v;
}a[iat];
bool cmp(data x, data y)
{
    return x.p<y.p;
}
signed main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i].p>>a[i].v;
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=m; i++)cin>>c[i];
    sort(c+1,c+m+1);
    int j=1;
    priority_queue <int> pq;
    for(int i=1; i<=m; i++)
    {
        while(j<=n && a[j].p<=c[i])pq.push(a[j].v),j++;
        if(!pq.empty())ans+=pq.top(),pq.pop();
    }
    cout<<ans;
}
