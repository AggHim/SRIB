/*
Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers n and m. Then in the next line are the nxm inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, N <= 50
0 <= A[][] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with total 6 1s (colored in Red).
*/

#include <iostream>
using namespace std;

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,-1,1,1,-1};

int dfs(int** graph, int n, int m, int row, int col, bool** visited){
    visited[row][col] = true;
    int sum = 0;
    for(int i=0;i<8;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(r>=0 && c>=0 && r<n && c<m){
            if(visited[r][c]==false && graph[r][c]==1){
                sum += dfs(graph,n,m,r,c,visited);
            }
        }
    }
    return 1+sum;
}

int getMax(int** graph, int n, int m, bool** visited){
    int max = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==false && graph[i][j]==1){
                int smallAns = dfs(graph,n,m,i,j,visited);
                if(smallAns > max){
                    max = smallAns;
                }
            }
        }
    }
    return max;
}

int main() {
	//code
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
	    cout << getMax(arr,n,m,visited) << endl;
	}
	return 0;
}
