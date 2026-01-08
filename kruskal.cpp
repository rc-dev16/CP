#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findParent(int parent[],int node){
    if(parent[node]==node){
        return node;
    }
    return findParent(parent,parent[node]);
}

void unionSet(int parent[],int rank[],int u,int v){
    u=findParent(parent,u);
    v=findParent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

void kruskal(vector<vector<int>>& edges,int n){
    int parent[n];
    int rank[n];
    int cost = 0;
    
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    
    sort(edges.begin(),edges.end(),[](const vector<int>& a,const vector<int>& b){
        return a[2]<b[2];
    });
    
    cout<<"Edges in MST:"<<endl;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        if(findParent(parent,u)!=findParent(parent,v)){
            unionSet(parent,rank,u,v);
            cost+=w;
            cout<<u<<" - "<<v<<" (weight: "<<w<<")"<<endl;
        }
    }
    
    cout<<"Total cost of MST: "<<cost<<endl;
}
int main(){
    int n,m;
    cout<<"enter the number of vertices and edges"<<endl;
    cin>>n>>m;
    vector<vector<int>> edges(m);
        for(int i=0;i<edges.size();i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]={u,v,w};
    }
    kruskal(edges,n);
    return 0;
}