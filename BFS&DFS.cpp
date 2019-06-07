#include <iostream>
#include <queue>
using namespace std;

void dfs(int** graph, int n, int sv, bool* visited){
    visited[sv] = true;
    cout << sv+1 << " ";
    for(int i=0;i<n;i++){
        if(i!=sv && graph[sv][i]==1 && visited[i]==false){
            dfs(graph,n,i,visited);
        }
    }
}

void bfs(int** graph, int n, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    cout << sv << " ";
    while(q.empty()==false){
        int current = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(i!=current && visited[i]==false && graph[current][i]==1){
                q.push(i);
                cout << i << " ";
                visited[i]=true;
            }
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    int** graph = new int*[n];
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        graph[i]= new int[n];
        visited[i] = false;
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    bfs(graph,n,0,visited);
    return 0;
}
