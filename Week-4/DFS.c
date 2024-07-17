#include<stdio.h>

int vis[20];
int res[20];
int j;

void dfs(int u,int n,int a[n][n]){
    vis[u]=1;
    for(int i=0;i<n;i++){
        if(a[u][i]==1 && vis[i]==0){
            dfs(i,n,a);
        }
    }
    res[j++]=u;

}

int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter adjacency matrix: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    j=0;

    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i,n,a);
        }
    }

    for(int i=n-1;i>=0;i--){
        printf("%d ",res[i]);
    }
}
