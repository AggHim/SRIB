/*
Given a matrix of size NxM where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. 
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, 
just left and just right of it.

Examples:

Input: mat[N][M] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Output: mat[N][M] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'X', 'X', 'X'},
                      {'O', 'X', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'O', 'X', 'O'},
                      {'O', 'O', 'X', 'O', 'O', 'O'},
                    };

Input: mat[N][M] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'O', 'O', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
Input: mat[N][M] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1<=T<=10
1<=mat[][]<=100
1<=n,m<=20

Example:

Input:
2
1 5
X O X O X 
3 3
X X X X O X X X X

Output:
X O X O X
X X X X X X X X X
*/

#include <iostream>
using namespace std;

int dx[] = {0,0,1,1};
int dy[] = {1,-1,0,0};

void rHelp(char** graph, int n, int m, int row, int col, bool** visited){
    visited[row][col] =true;
    graph[row][col] = 'X'; 
    for(int i=0;i<8;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(r>=0 && c>=0 && r<n && c<m){
            if(visited[r][c]==false && graph[r][c]=='O'){
                rHelp(graph,n,m,r,c,visited);
            }
        }
    }
}

bool dfs(char** graph, int n, int m, int row, int col, bool** visited){
    visited[row][col] =true;
    int flag = 0;
    for(int i=0;i<8;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(r>=0 && c>=0 && r<n && c<m){
            if(visited[r][c]==false && graph[r][c]=='O'){
                bool b = dfs(graph,n,m,r,c,visited);
                /*
                Here do not return false, because then other vertices of this 
                group will not be explored, and they will be changed to X, because,
                they will not be marked visited, as function returns earlier.
                */
                if(b==false){
                    flag=-1;
                }
            }
        }else{
            flag=-1;
        }
    }
    if(flag==-1){
        return false;
    }
    return true;
}

void replace(char** arr, int n, int m){
    bool** visited = new bool*[n];
    bool** v = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        v[i] = new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
            v[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==false && arr[i][j]=='O'){
                bool smallAns = dfs(arr,n,m,i,j,visited);
                if(smallAns==true){
                    rHelp(arr,n,m,i,j,v);
                }
            }
        }
    }
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    char** arr = new char*[n];
	    for(int i=0;i<n;i++){
	        arr[i] = new char[m];
	        for(int j=0;j<m;j++){
	            cin >> arr[i][j];
	        }
	    }
	    replace(arr,n,m);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout << arr[i][j] << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}
