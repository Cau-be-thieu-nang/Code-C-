
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
#define data _data
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
int n,m,k,arrx[iat],lenx,arry[iat],leny,num_vertex,ans,res,cntE,cntV;
pair<int, int> vertex[iat];
set <pair<int, int>> E;
set <int> adj[iat];
set <int> V;
bool used[105][105],ok[iat];
struct data
{
    int x,y,u,v;
    void read()
    {
        cin>>x>>y>>u>>v;
        if(x>u)swap(x,u);
        if(y>v)swap(y,v);
    }
}a[55];
void add_vertex(const int &x, const int &y)
{
    num_vertex++;
    vertex[num_vertex]={x,y};
}
void add_x(const int &x, const int &u, const int &v)
{
    for(int i=1; i<=leny; i++)
    {
        if(arry[i]>u && arry[i]<=v)
        {
            int a=lower_bound(vertex+1,vertex+num_vertex+1,make_pair(x,arry[i-1]))-vertex;
            int b=lower_bound(vertex+1,vertex+num_vertex+1,make_pair(x,arry[i]))-vertex;
            adj[a].emplace(b);
            adj[b].emplace(a);
            V.emplace(a);
            V.emplace(b);
        }
    }
}
void add_y(const int &y, const int &u, const int &v)
{
    for(int i=1; i<=lenx; i++)
    {
        if(arrx[i]>u && arrx[i]<=v)
        {
            int a=lower_bound(vertex+1,vertex+num_vertex+1,make_pair(arrx[i-1],y))-vertex;
            int b=lower_bound(vertex+1,vertex+num_vertex+1,make_pair(arrx[i],y))-vertex;
            adj[a].emplace(b);
            adj[b].emplace(a);
            V.emplace(a);
            V.emplace(b);
        }
    }
}
void hihi(const int &x)
{
    ok[x]=true;
    cntV++;
    for(auto it=adj[x].begin(); it!=adj[x].end(); it++)
    {
        int u=*it;
        if(!E.count({min(x,u),max(x,u)}))
        {
            E.emplace(min(x,u),max(x,u));
            cntE++;
        }
        if(!ok[u])hihi(u);
    }
}
signed main()
{
    fast_IO();
    while(true)
    {
        cin>>m>>n;
        if(m==0 && n==0)break;
        cin>>k;
        for(int i=1; i<=k; i++)a[i].read();
        ++k;
        a[k].x=0;
        a[k].y=0;
        a[k].u=n;
        a[k].v=m;
        for(int i=1; i<=k; i++)
        {
            arrx[i]=a[i].x;
            arrx[i+k]=a[i].u;
            arry[i]=a[i].y;
            arry[i+k]=a[i].v;
        }
        sort(arrx+1,arrx+2*k+1);
        sort(arry+1,arry+2*k+1);
        lenx=1;
        leny=1;
        for(int i=2; i<=2*k; i++)
        {
            if(arrx[i]>arrx[i-1])
            {
                lenx++;
                arrx[lenx]=arrx[i];
            }
            if(arry[i]>arry[i-1])
            {
                leny++;
                arry[leny]=arry[i];
            }
        }
        num_vertex=0;
        for(int i=1; i<=lenx; i++)
        {
            for(int j=1; j<=leny; j++)add_vertex(arrx[i],arry[j]);
        }
        sort(vertex+1,vertex+num_vertex+1);
        int num=1;
        for(int i=1; i<=num_vertex; i++)
        {
            if(vertex[i]>vertex[i-1])
            {
                num++;
                vertex[num]=vertex[i];
            }
        }
        num_vertex=num;
        V.clear();
        for(int i=1; i<=num_vertex; i++)adj[i].clear();
        for(int i=1; i<=k; i++)
        {
            add_x(a[i].x,a[i].y,a[i].v);
            add_x(a[i].u,a[i].y,a[i].v);
            add_y(a[i].y,a[i].x,a[i].u);
            add_y(a[i].v,a[i].x,a[i].u);
        }
        res=0;
        for(auto it=V.begin(); it!=V.end(); it++)ok[*it]=false;
        for(auto it=V.begin(); it!=V.end(); it++)
        {
            if(!ok[*it])
            {
                cntE=0;
                cntV=0;
                E.clear();
                hihi(*it);
                res+=cntE-cntV+1;
            }
        }
        cout<<res<<'\n';
    }
}
