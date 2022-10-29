
/// (*^_^*) Author : Cau_be_thieu_nang

#include <bits/stdc++.h>
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i)) // 2 luy thua i
#define BIT(x,i) (((x) >> (i)) & 1) // lay ra bit thu i cua so x
#define left _left
#define right _right
#define task "t"
using namespace std;
const ll INF=1e18;
const int iat=1e5+9;
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
int n,k,h[iat],sz,len[400];
bool check[iat];
pair <int,int> seg[400][400];
void update(int pos)
{
    for(int i=0; i<sz; i++)seg[pos][i]={-1,-1};
    int cnt=0;
    int l=pos*sz,r=min(n-1,(pos+1)*sz-1);
    for(int i=l; i<=r; i++)
    {
        if(!check[i])
        {
            if(seg[pos][cnt%k].first<h[i])seg[pos][cnt%k]={h[i],i};
            cnt++;
        }
    }
    len[pos]=cnt;
}
signed main()
{
    fast_IO();
    cin>>n>>k;
    for(int i=0; i<n; i++)cin>>h[i];
    sz=sqrt(n)+1;
    for(int i=0; i<sz; i++)update(i);
    for(int i=0; i<n; i++)
    {
        int cnt=0;
        pair <int,int> maxi={-1,-1};
        int pos=-1;
        for(int j=0; j<sz; j++)
        {
            if(len[j]==0)continue;
            int p=(k-cnt%k)%k;
            if(p<sz && seg[j][p].first>maxi.first)maxi=seg[j][p],pos=j;
            cnt+=len[j];
        }
        cout<<maxi.first<<" ";
        check[maxi.second]=true;
        update(pos);
    }
}
