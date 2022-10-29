
/// (*^_^*) Author : Cau_be_thieu_nang

#include <bits/stdc++.h>
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i)) // 2 luy thua i
#define BIT(x,i) (((x) >> (i)) & 1) // lay ra bit thu i cua so x
#define left _left
#define right _right
#define task "t"
#define int long long
using namespace std;
const ll INF=1e15;
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
int n,m,k,distA[iat],distB[iat],distAK[iat],distBN[iat],ans=INT_MAX;
vector <tuple<int,int,int>> g[iat],revg[iat];
void dijkstra(int s, int d[], bool type, bool tight)
{
    for(int i=1; i<=n; i++)d[i]=INF;
    d[s]=0;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
    p.push({0,s});
    while(!p.empty())
    {
        pair<int,int> top=p.top();
        p.pop();
        int u=top.second,length=top.first;
        if(length>d[u])continue;
        if(!tight)
        {
            for(auto it : g[u])
            {
                int v=get<0>(it),w=(type ? get<2>(it) : get<1>(it));
                if(d[v]>d[u]+w)d[v]=d[u]+w,p.push({d[v],v});
            }
        }
        else
        {
            for(auto it : revg[u])
            {
                int v=get<0>(it),w=(type ? get<2>(it) : get<1>(it));
                if(d[v]>d[u]+w)d[v]=d[u]+w,p.push({d[v],v});
            }
        }
    }
}
signed main()
{
    fast_IO();
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        int u,v,w1,w2;
        cin>>u>>v>>w1>>w2;
        g[u].push_back({v,w1,w2});
        revg[v].push_back({u,w1,w2});
    }
    dijkstra(1,distA,0,0);
    dijkstra(1,distB,1,0);
    dijkstra(k,distAK,0,1);
    dijkstra(n,distBN,1,1);
    for(int i=1; i<=n; i++)
    {
        if(distB[i]+distAK[i]<=59)ans=min(ans,distB[i]+distBN[i]);
    }
    cout<<ans;
}
