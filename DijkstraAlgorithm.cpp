/*
Initially weights for all vertices will be marked as Infinity, now there will be a visited array to keep track
of the vertices that are visited. We chose vertex with minimum weight from the unvisited and explore all it's neighbours
that are also unvisited and update their weights and parents is distance is lower than current weight.
*/

#include <iostream>
#include <climits>
using namespace std;

int getMin(int* distance, bool* visited, int n){
    int minIndex = -1;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(minIndex==-1 || distance[i]<distance[minIndex]){
                minIndex = i;
            }
        }
    }
    return minIndex;
}

void dijkstra(int** graph, int n){
    bool* visited = new bool[n];
    int* distance = new int[n];
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }
    distance[0] = 0;
    for(int i=0;i<n-1;i++){
        int minVertex = getMin(distance,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(graph[minVertex][j]!=0 && visited[j]==false){
                int d = distance[minVertex]+graph[i][j];
                if(d < distance[j]){
                    distance[j] = d;
                    parent[j] = minVertex;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << i << " Distance: " << distance[i] << " Parent: " << parent[i] << endl;
    }
    delete [] distance;
    delete [] visited;
}

int main() {
    int n,k;
    cin >> n >> k;
    int** graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[n];
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<k;i++){
        int s,e,w;
        cin >> s >> e >> w;
        graph[s][e]=w;
        graph[e][s]=w;
    }
    dijkstra(graph,n);
}
