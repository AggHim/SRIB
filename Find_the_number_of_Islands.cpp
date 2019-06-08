/*
A group of connected 1's forms an island. The task is to complete the method findIslands() which returns the number of islands present. The function takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size(N*M) of the matrix A .

Input:
The first line of input will be the number of testcases T, then T test cases follow. The first line of each testcase contains two space separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .

Output:
For each testcase in a new line, print the number of islands present.

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[i][j] <= 1

Example :

Input
2
3 3
1 1 0 
0 0 1 
1 0 1
4 4
1 1 0 0 
0 0 1 0 
0 0 0 1 
0 1 0 0

Output
2
2

Explanation:
Testcase 1: The graph will look like
1 1 0
0 0 1
1 0 1
Here, two islands will be formed
*/

#include <iostream>
using namespace std;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

bool check(int n, int m, int r, int c){
    if(r>=0 && c>=0 && r<n && c<m){
        return true;
    }
    return false;
}

void dfs(int** graph, int n, int m, int row, int col, bool ** visited){
    visited[row][col]=true;
    for(int i=0;i<8;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(check(n,m,r,c) && graph[r][c]==1 && visited[r][c]==false){
            dfs(graph,n,m,r,c,visited);
        }
    }
}

int findIslands(int** graph, int n, int m, bool ** visited){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            /*
            Important Note:
            Only count when graph[i][j]==1
            */
            if(graph[i][j]==1 && visited[i][j]==false){
                dfs(graph,n,m,i,j,visited);
                count +=1;
            }
        }
    }
    return count;
}

int main(){
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
    cout << findIslands(arr,n,m,visited);
    return 0;
}

