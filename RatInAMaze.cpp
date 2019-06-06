int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool check(int row, int col, int n){
    if(row>=0 && row<n && col>=0 && col<n){
        return true;
    }
    return false;
}

void print(int path[][20], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << path[i][j] << " ";
        }
    }
    cout << endl;
}

void ratInAMazeHelper(int maze[][20], int path[][20], int n, int r, int c){
    if(r==n-1 && c==n-1){
        path[r][c]=1;
        print(path,n);
        path[r][c]=0;
        return;
    }
    for(int i=0;i<4;i++){
        int r1 = r + dx[i];
        int c1 = c + dy[i];
        if(check(r1,c1,n) && path[r1][c1]==0 && maze[r1][c1]==1){
            path[r][c]=1;
            ratInAMazeHelper(maze,path,n,r1,c1);
            path[r][c]=0;
        }
    }
}

void ratInAMaze(int maze[][20], int n){
  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int path[n][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j]=0;
        }
    }
    ratInAMazeHelper(maze,path,n,0,0);
}
