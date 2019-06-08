#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int** graph, int n, int sv, bool* visited){
    visited[sv] = true;
    cout << sv << " ";
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
    while(q.empty()==false){
        int current = q.front();
        cout << current << " ";
        q.pop();
        for(int i=0;i<n;i++){
            if(i!=current && visited[i]==false && graph[current][i]==1){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

bool hasPathDFS(int** graph, int n, int s, int e, bool* visited){
    if(s==e){
        return true;
    }
    visited[s] = true;
    for(int i=0;i<n;i++){
        if(i!=s && visited[i]==false && graph[s][i]==1){
            if(hasPathDFS(graph,n,i,e,visited)){
                return true;
            }
        }
    }
    return false;
}

bool hasPathBFS(int** graph, int n, int s, int e, bool* visited){
    if(s==e){
        return true;
    }
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(q.empty()==false){
        int c = q.front();
        if(c==e){
            return true;
        }
        q.pop();
        for(int i=0;i<n;i++){
            if(visited[i]==false && graph[c][i]==1){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

vector<int>* getPathDFS(int** graph, int n, int s, int e, bool* visited){
    if(s==e){
        vector<int>* v = new vector<int>();
        v->push_back(s);
        return v;
    }
    /*
       Do not forget to mark s as visited in DFS or BFS
    */
    visited[s]=true;
    for(int i=0;i<n;i++){
        if(i!=s && visited[i]==false && graph[s][i]==1){
            vector<int>* v = getPathDFS(graph,n,i,e,visited);
            if(v!=NULL){
                /*
                   We will push 's' into the vector not 'i'
                */
                v->push_back(s);
                return v;
            }
        }
    }
    return NULL;
}

void getPathBFS(int** graph, int n, int s, int e, bool* visited, int* parent){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(q.empty()==false){
        int c = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(visited[i]==false && graph[c][i]==1){
                parent[i] = c;
                q.push(i);
                visited[i]=true;
                if(i==e){
                    break;
                }
            }
        }
    }
    if(parent[e]==-1){
        return;
    }
    int start = e;
    while(start!=-1){
        cout << start << " ";
        start = parent[start];
    }
    cout << endl;
}

int main(){
    int n,k;
    cin >> n >> k;
    int** graph = new int*[n];
    int* parent = new int[n];
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        graph[i]= new int[n];
        parent[i]=-1;
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
    int s,e;
    cin >> s >> e;
    return 0;
}
