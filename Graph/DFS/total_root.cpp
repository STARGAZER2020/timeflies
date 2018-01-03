// calculate total no of different nodes
#include<bits/stdc++.h>
using namespace std; 
#define ll long long
vector<ll> g[100001];
bool v[100001];

void intialise(int n)
{
    for(int i=0;i<n;++i) v[i]=false;
}
void dfs(ll s)
{
    v[s]=true;
    for(ll i=0;i<g[s].size();++i)
    {
        if(v[g[s][i]]==false)
        {
            dfs(g[s][i]);
        }
    }
}
int main()
{
    int n,m,x,y,total_root=0;
    cin>>n>>m;
    intialise(n);
   
    for(int i=1;i<=m;++i)
    { 
        cin>>x>>y;
        g[y].push_back(x);
        g[x].push_back(y);
    } 
    for(int i=1;i<=n;++i){
       if(v[i]==false) 
      {
         dfs(x); 
         total_root++;
      }
    }
    cout<<total_root<<" ";
    return 0;
}
