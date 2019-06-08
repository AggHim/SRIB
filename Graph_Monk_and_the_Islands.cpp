/*
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. 
Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. 
He is standing at Island #1 and wants to reach the Island #N. 
Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
*/

#include<bits/stdc++.h>
#include <queue>
using namespace std;

int bfs(int** graph, int n, int s, int e, bool* visited, int* level){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    while(q.empty()==false){
        int c = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(i!= c && visited[i]==false && graph[c][i]==1){
                visited[i] = true;
                level[i]=level[c]+1;
                q.push(i);
                if(i==e){
                    break;
                }
            }
        }
    }
    return level[e];
}

int main()
{
	//code
    int t;
    cin >> t;
    while(t--){
            int n,k;
        cin >> n >> k;
        int** graph = new int*[n];
        int* level = new int[n];
        bool* visited = new bool[n];
        for(int i=0;i<n;i++){
            graph[i]= new int[n];
            level[i] = -1;
            visited[i] = false;
            for(int j=0;j<n;j++){
                graph[i][j]=0;
            }
        }
        for(int i=0;i<k;i++){
            int x,y;
            cin >> x >> y;
            graph[x-1][y-1]=1;
            graph[y-1][x-1]=1;
        }
        int s = 0;
        int e = n-1;
        if(s==e){
            return 0;
        }
        cout << bfs(graph,n,s,e,visited,level) << endl;
    }
	return 0;
}
