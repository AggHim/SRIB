#include <iostream>
using namespace std;

int dx[] = {-1,-1,-1};
int dy[] = {0,1,-1};
int maxi = -1;

void dfs(int** arr, int n, int row, int col, int score, int bomb){
    if(row==0){
        if(score>maxi){
            maxi = score;
        }
        return;
    }
    if(score<0){
        return;
    }
    for(int i=0;i<3;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(r>=0 && c>=0 && r<n && c<5){
            if(arr[r][c]==0){
                dfs(arr,n-1,r,c,score,bomb);
            }else if(arr[r][c]==1){
                dfs(arr,n-1,r,c,score+1,bomb);
            }else{
                dfs(arr,n-1,r,c,score-1,bomb);
            }
        }
    }
    if(bomb>=1){
    for(int k=0;k<5;k++){
        for(int j=0;j<5;j++){
            if(row-k-1 >=0 && arr[row-k-1][j]==2){
                arr[row-k-1][j]=0;
            }
        }
    }
    for(int i=0;i<3;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        if(r>=0 && c>=0 && r<n && c<5){
            if(arr[r][c]==0){
                dfs(arr,n-1,r,c,score,bomb-1);
            }else if(arr[r][c]==1){
                dfs(arr,n-1,r,c,score+1,bomb-1);
            }else{
                dfs(arr,n-1,r,c,score-1,bomb-1);
            }
        }
    }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        maxi = -1;
        int n;
        cin >> n;
        int** arr = new int*[n];
        for(int i=0;i<n;i++){
            arr[i] = new int[5];
            for(int j=0;j<5;j++){
                cin >> arr[i][j];
            }
        }
        dfs(arr,n,n,2,0,1);
        cout << maxi << endl;
    }
}
