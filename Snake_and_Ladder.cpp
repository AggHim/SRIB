/*
Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or 
last cell (30th cell) from source (1st cell) .

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1 <= T <= 100
1 <= N <= 10
1 <= a <= 30
1 <= b <= 30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30

Output:
3
1

Explanation:

Testcase 1: 
For 1st throw get a 2, which contains ladder to reach 22
For 2nd throw get a 6, which will lead to 28
Finally get a 2, to reach at the end 30. Thus 3 dice throws required to reach 30.
*/


#include <queue>
#include <iostream>
using namespace std;

int bfs(int** graph, int sv, int* level, int* visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    level[sv]=0;
    while(q.empty()==false){
        int c = q.front();
        q.pop();
        for(int i=0;i<30;i++){
            if(visited[i]==false && graph[c][i]==1){
                visited[i]=true;
                level[i]=level[c]+1;
                q.push(i);
                if(i==29){
                    break;
                }
            }
        }
    }
    return level[29];
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	int** arr = new int*[30];
	int* visited = new int[30];
	int* level = new int[30];
	for(int i=0;i<30;i++){
	    arr[i] = new int[30];
	    for(int j=0;j<30;j++){
	        visited[j] = false;
	        level[j]=-1;
	        if((j-i)>0 && (j-i)<=6){
	            arr[i][j]=1;
	        }else{
	            arr[i][j]=0;
	        }
	    }
	}
	int k;
	cin >> k;
	for(int i=0;i<k;i++){
	    int x,y;
	    cin >> x >> y;
	    x = x-1;
	    y = y-1;
	    for(int j=x-1;j>=0&&j>=x-6;j--){
	        arr[j][y] = 1;
	    }
	}
	cout << bfs(arr,0,level,visited) << endl;
	}
	return 0;
}

/*
In this problem we will create edges from every last 6 nodes of any ladder or snake starting, to the ladder or snake ending,
By this, every node knows that there is a path to reach particular node, in some way out of 1,2,3,4,5,6 move.
*/
