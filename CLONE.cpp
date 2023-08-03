#include <bits/stdc++.h>
#define ll long long
#define LOG 20
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define FIRST_BIT(mask) __builtin_ctz((mask)&(-mask))
#define ERASE_BIT(mask) (mask)^((mask)&(-mask))
#define left _left
#define right _right
#define task "t"
using namespace std;
const ll INF=1e18;
const int iat=1e6+9;
const int MAX=15e5;
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
int n,x;
char c[3]={'C','A','B'};
signed main()
{
    fast_IO();
    int t=10;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        if(x==1)
        {
            cout<<"A";
            continue;
        }
        if(x==2)
        {
            cout<<"B";
            continue;
        }
        int mini=(x-3+1)/4+((x-3+1)%4!=0),maxi=(n-x+1)/2+((n-x+1)%2!=0);
        if(mini<maxi)
        {
            int mod=(x-3+1)%4;
            if(!mod)mod=4;
            int pos=2+6*(mini-1)+mod+2;
            cout<<c[pos%3];
        }
        else
        {
            int mod=(n-x+1)%2;
            if(!mod)mod=2;
            int pos=2+6*(maxi-1)+mod;
            cout<<c[pos%3];
        }
    }

}
