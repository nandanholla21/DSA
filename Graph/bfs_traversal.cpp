#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int node, vector<int> adj[], vector<int> &visi){
    vector<int> result;
    visi[node] = 1;
    queue<int> que;
    que.push(node);
    while(!que.empty()){
        int top = que.front();
        que.pop();
        result.push_back(top);
        for(auto x:adj[top]){
            if(visi[x] !=1){
                que.push(x);
                visi[x] = 1;
            }
        }
    }
    //printing result
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
int main(){
    int n,m; //n is number of vertices and m is number if edges
    cout<<"Enter the number of vertices and number of edges of the graph ";
    cin>>n>>m;
    vector<int> adj[n];
    int u,v;
    cout<<"Enter the graph ";
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    } 
    vector<int> visi(n+1,0);
    int source;
    cout<<"Enter the source vertex ";
    cin>>source;
    bfs(source,adj,visi); 
}