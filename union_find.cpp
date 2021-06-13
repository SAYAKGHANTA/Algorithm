#include<bits/stdc++.h>
using namespace std;

int parent[1000001];

int find(int u)
{ 
    //find operation use to find the parent
    if(parent[u]==u){
        return u;
    }
    return find(parent[u]);
}

void union1(int u,int v)
{
    //adding node v and u to the same set
    u=find(u);
    v=find(v);
    parent[u]=v;
}

bool hasCycle(int u,int v)
{
    //checking wheter cycle is present or not
    if(find(u)==find(v)){
        return true;
    }
    union1(u,v);
    return false;
}


int main()
{
    for(int i=0;i<1000001;i++)parent[i]=i;
    vector<vector<int>>edge;
    int e;
    cin>>e;
    bool res=false;
    for(int i=0;i<e;++i){
        int u,v;
        cin>>u>>v;
        if(hasCycle(u,v))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}