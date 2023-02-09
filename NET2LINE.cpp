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
int n,u[2001],v[2001],w[2001];
struct edge
{
    int u,v,w;
};
vector <edge> g;
bool cmp(edge x, edge y)
{
    return x.w<y.w;
}
struct DSU
{
    int par[2001],sz[2001];
    void make_set()
    {
        for(int i=1; i<=2*n; i++)par[i]=i,sz[i]=1;
    }
    int find_set(int v)
    {
        if(v==par[v])return v;
        return par[v]=find_set(par[v]);
    }
    bool Union(int a, int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b)return false;
        if(sz[a]<sz[b])swap(sz[a],sz[b]);
        par[b]=a;
        sz[a]+=sz[b];
        return true;
    }
}dsu;
int sum,dist[2001][2001];
bool check[2001][2001];
vector <int> ke[2001];
void kruskal()
{
    sort(g.begin(),g.end(),cmp);
    dsu.make_set();
    for(edge it : g)
    {
        if(dsu.Union(it.u,it.v))sum+=it.w,check[it.u][it.v]=true;
    }
    if(sum%2)
    {
        int ans=INT_MAX;
        for(edge it : g)
        {
            if(!check[it.u][it.v] && dist[it.u][it.v]%2!=0)ans=min(ans,sum+dist[it.u][it.v]);
            if(check[it.u][it.v])
            {
                dsu.make_set();
                for(edge e : g)
                {
                    if((e.u!=it.u || e.v!=it.v) && check[e.u][e.v])dsu.Union(e.u,e.v);
                }
                int tmp=sum-dist[it.u][it.v];
                for(edge e : g)
                {
                    if(!check[e.u][e.v])
                    {
                        if(dsu.find_set(e.u)!=dsu.find_set(e.v) && tmp%2==dist[e.u][e.v]%2)ans=min(ans,tmp+dist[e.u][e.v]);
                    }
                }
            }
        }
        if(ans==INT_MAX)cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
    else cout<<sum<<'\n';
}
void solve()
{
    memset(check,false,sizeof(check));
    g.clear(); sum=0;
    cin>>n;
    for(int i=1; i<=2*n; i++)ke[i].clear();
    for(int i=1; i<n; i++)
    {
        cin>>u[i];
        g.push_back({i,i+1,u[i]});
        dist[i][i+1]=dist[i+1][i]=u[i];
        ke[i].push_back(i+1);
        ke[i+1].push_back(i);
    }
    for(int i=1; i<n; i++)
    {
        cin>>v[i];
        g.push_back({n+i,n+i+1,v[i]});
        dist[n+i][n+i+1]=dist[n+i+1][n+i]=v[i];
        ke[n+i].push_back(n+i+1);
        ke[n+i+1].push_back(n+i);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];
        g.push_back({i,i+n,w[i]});
        dist[i][i+n]=dist[i+n][i]=w[i];
        ke[i].push_back(i+n);
        ke[i+n].push_back(i);
    }
    kruskal();
}
signed main()
{
    fast_IO();
    int t;
    cin>>t;
    while(t--)solve();
}
