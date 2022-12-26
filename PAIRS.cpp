
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
void find_div(int n)
{
    int cnt=0;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            if(n/i==i)cnt++;
            else cnt+=2;
        }
    }
    cout<<cnt<<'\n';
}
signed main()
{
    fast_IO();
    int n;
    while(cin>>n)
    {
        find_div(n);
    }
}
