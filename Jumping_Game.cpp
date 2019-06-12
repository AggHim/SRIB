#include <iostream>
using namespace std;

bool dfs(int** arr, int n, int m, int row, int col, int k, bool** visited){
    int dx[2*k+2];
    int dy[2*k+2];
    dx[0] = 0;
    dx[1] = 0;
    dy[0] = 1;
    dy[1] = -1;
    int l = 2;
    for(int i=0;i<k;i++){
        dx[l] = -(k-i); 
        dx[l+k] = (k-i);
        dy[l] = 0;
        dy[l+k] = 0;
        l++;
    }
    visited[row][col]=true;
    for(int i=0;i<2*k+2;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(r>=0 && c>=0 && r<n && c<m){
            if(visited[r][c]==false){
                if(arr[r][c]==3){
                    return true;
                }
                if(arr[r][c]==1){
                    bool b = dfs(arr,n,m,r,c,k,visited);
                    if(b==true){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
    int n,m;
    cin >> n >> m;
    int** arr = new int*[n];
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
        visited[i] = new bool[m];
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            visited[i][j]=false;
        }
    }
    int flag = 0;
    for(int k=0;k<=n;k++){
        bool b = dfs(arr,n,m,n-1,0,k,visited);
        if(b==true && flag==0){
            cout << k << endl;
            flag = -1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=false;
            }
        }
    }
    if(flag==0){
        cout << -1 << endl;
    }
    }
}

/*

Input:
3
6 5
0 0 3 0 0
0 1 0 1 0
1 0 0 0 1
0 1 0 1 0
0 0 1 0 0
1 1 1 1 1
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
2 1 1 1 1 1 1 1
8 10
3 1 1 1 1 1 1 1 1 1 
0 0 0 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0
1 0 0 0 0 0 1 1 1 1
0 0 1 1 1 1 1 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
2 1 1 1 1 1 1 1 1 1 

Output:
4 
2
2

*/
