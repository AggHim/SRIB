/*
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:

Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.

Testcase 2: The matrix for the above given input is:
0 3 2
3 0 0
1 0 0
From the matrix we can see that there does not exists any path to reach destination 2 from source 1.
*/


#include <iostream>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool check(int n ,int row, int col){
    if(row>=0 && row<n && col>=0 && col<n){
        return true;
    }
    return false;
}

bool getPath(int** arr, int n, int row, int col, bool** visited){
    if(arr[row][col]==2){
        return true;
    }
    visited[row][col]=true;
    for(int i=0;i<4;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(check(n,r,c)){
            
            /* Important Note:
            Here we will need to check if any neighbour is 2
            or not otherwise, we will never reach the true 
            condition if we only call getPath for '3'
            */
            
            if(arr[r][c]==2){
                return true;
            }
            if(arr[r][c]==3 && visited[r][c]==false){
                bool smallAns = getPath(arr,n,r,c,visited);
                if(smallAns==true){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    //code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int** arr = new int*[n];
	    bool** visited = new bool*[n];
	    int r,c;
	    for(int i=0;i<n;i++){
	        arr[i] = new int[n];
	        visited[i] = new bool[n];
	        for(int j=0;j<n;j++){
	            cin >> arr[i][j];
	            if(arr[i][j]==1){
	                r=i;
	                c=j;
	            }
	            visited[i][j]=false;
	        }
	    }
	    bool b1 = getPath(arr,n,r,c,visited);
	    if(b1==true){
	        cout << "1" << endl;
	    }else{
	        cout << "0" << endl;
	    }
	}
	return 0;
}
