#include<bits/stdc++.h>
using namespace std;
int par[100000],size[100000];
struct cmp{
    bool operator()( pair<int,int>a,pair<int,int>b )
    {
        return a.second<b.second;
    }
    
    //to maintain a sorted order of size
};
multiset<pair<int,int>,cmp>S;
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        S.insert(make_pair(i,1));
        size[i]=1;
    }
    
}
int root(int x)
{
    while(par[x]!=x)
    {
        par[x]=par[par[x]];
        x=par[x];
    }
    
    return par[x];
    
    //path compression algorithm to find root in connected componenet
}

void munion(int x,int y)
{
    int root_x=root(x);
    int root_y=root(y);
    
    if(root_x==root_y)
    return ;
    
    if(size[root_x]<size[root_y])
    swap(root_x,root_y);
    
    S.erase(S.find(make_pair(root_x,size[root_x])));
    S.erase(S.find(make_pair(root_y,size[root_y])));
    
    par[root_y]=root_x;
    size[root_x]+=size[root_y];
    
    S.insert(make_pair(root_x,size[root_x]));
    
    //modified merging or union to keep track of each vertex's connected component size

}
int main()
{
    int n,k;
    cin>>n>>k;
    init(n);
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        munion(x,y);
        
        int lar=(*(S.rbegin())).second;
        int sml=(*(S.begin())).second;
        
        cout<<lar-sml<<'\n';

    }
    
}
