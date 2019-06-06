void print(int** arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

bool check(int** arr, int row, int col, int n){
    int i,j;
    for(i=row,j=col;i>=0&&j>=0;i--,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(i=row,j=col;i>=0&&j<n;i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    for(i=row;i>=0;i--){
        if(arr[i][col]==1){
            return false;
        }
    }
    return true;
}

void nQueens(int** arr, int n, int r){
    if(r==n){
        return;
    }
    for(int i=0;i<n;i++){
        if(check(arr,r,i,n)){
            arr[r][i]=1;
            if(r==n-1){
                print(arr,n);
            }else{
                nQueens(arr,n,r+1);
            }
            arr[r][i]=0;
        }
    }
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    } 
    nQueens(arr,n,0);
}
