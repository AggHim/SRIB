/*
Given N * M string array of O's and X's. The task is to find the number of 'X' total shapes. 'X' shape consists of one or more adjacent X's (diagonals not included).

Input: The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:
For each testcase, print number of shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

Explanation:
Testcase 1: Given input is like:
OOOOXXO
OXOXOOX
XXXXOXO
OXXXOOO

So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). So, there are 4 different groups in the given matrix.

Testcase 2: Given input is like:
XXO
OOX
OXO
OOO
XOX
XOX
OXO
XXO
XXX
OOO

So, this matrix has 6 groups with is having adjacent Xs. Total number of groups is 6.
*/

#include <iostream>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool check(int n, int m, int r, int c){
    if(r>=0 && c>=0 && r<n && c<m){
        return true;
    }
    return false;
}

void dfs(char** arr, int n, int m, int r, int c, bool** visited){
    visited[r][c]=true;
    for(int i=0;i<8;i++){
        int x = r + dx[i];
        int y = c + dy[i];
        if(check(n,m,x,y) && arr[x][y]=='X' && visited[x][y]==false){
            dfs(arr,n,m,x,y,visited);
        }
    }
}

int getShapes(char** arr, int n, int m, bool** visited){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='X' && visited[i][j]==false){
                dfs(arr,n,m,i,j,visited);
                count+=1;
            }
        }
    }
    return count;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	int n,m;
	cin >> n >> m;
	char** arr = new char*[n];
	bool** visited = new bool*[n];
	for(int i=0;i<n;i++){
	    arr[i] = new char[m];
	    visited[i] = new bool[m];
	    for(int j=0;j<m;j++){
	        cin >> arr[i][j];
	        visited[i][j]=false;
	    }
	}
	cout << getShapes(arr,n,m,visited) << endl;
	}
	return 0;
}
