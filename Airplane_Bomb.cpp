#include <iostream>
using namespace std;
int maxi = -1;

int dx[] = {-1,-1,-1};
int dy[] = {0,1,-1};

void detonate(int** arr, int n, int row, int** restore){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            restore[i][j]=0;
        }
    }
    for(int i=row;i>row-5;i--){
        for(int j=0;j<5;j++){
            if(i>=0 && arr[i][j]==2){
                restore[row-i][j] = 2;
                arr[i][j] = 0;
            }
        }
    }
}

void undetonate(int** arr, int n, int row, int** restore){
    for(int i=row;i>row-5;i--){
        for(int j=0;j<5;j++){
            if(i>=0 && restore[row-i][j]==2){
                arr[i][j] = 2;
            }
        }
    }
}

void dfs(int** arr, int n, int row, int col, int score){
    if(score<0){
        return;
    }
    if(row==0){
        if(score > maxi){
            maxi = score;
        }
        return;
    }
    for(int i=0;i<3;i++){
        int r = row + dx[i];
        int c = col + dy[i];
        /*
        Don't forget to add this boundary condition
        */
        if(r>=0 && c>=0 && r<n && c<5){
            if(arr[r][c]==1){
                dfs(arr,n,r,c,score+1);
            }else if(arr[r][c]==2){
                dfs(arr,n,r,c,score-1);
            }else{
                dfs(arr,n,r,c,score);
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
        dfs(arr,n,n,2,0);
        int** restore = new int*[5];
        for(int i=0;i<5;i++){
            restore[i] = new int[5];
        }
        for(int i=0;i<n;i++){
            detonate(arr,n,n-i-1,restore);
            dfs(arr,n,n,2,0);
            undetonate(arr,n,n-i-1,restore);
        }
        cout << maxi << endl;
        for(int i=0;i<n;i++){
            delete [] restore[i];
            delete [] arr[i];
        }
        delete [] arr;
        delete [] restore;
    }
}
