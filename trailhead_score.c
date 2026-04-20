#include <stdio.h>
#include<string.h>

void dfs(int i, int j,int r, int c, int grid[100][100], int visited9[100][100], int*count)
{
    //If current cell is 9, count it(only once)
    if(grid[i][j] == 9)
    {
        if(visited9[i][j] == 0)
        {
            visited9[i][j] =1;
            (*count)++;
        }
        return;
    }
    int curr =grid[i][j];
    
    //up 
    if(i- 1>=0 && grid[i- 1][j]==curr + 1)
        dfs(i-1, j, r, c, grid, visited9, count);
    //down    
    if(i+1<r && grid[i + 1][j]==curr + 1)
        dfs(i+ 1, j, r, c, grid,visited9, count);
    //left    
    if(j- 1>=0 && grid[i][j- 1]==curr + 1)
        dfs(i, j- 1, r ,c ,grid, visited9, count);
    //right    
    if(j+1<c&& grid[i][j+ 1]==curr + 1)
        dfs(i, j+ 1, r, c, grid, visited9, count);
}

int main()
{
    int r,c;
    int total_score=0;
    printf("Enter the no of rows and column:");
    scanf("%d %d", &r, &c);
    
    int grid[100][100];
    int visited9[100][100]={0};
    int count =0;
    printf("Enter the grid values:\n");
    for(int i =0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }
    printf("Grid is:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
        
    }
    //Traverse grid to find all trailheads (cells with value 0)
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           if(grid[i][j]==0)
           {
               //reset before each Trailhead
               memset(visited9, 0, sizeof(visited9));
               count =0;
               
               printf("Starting DFS from(%d %d)\n", i,j);
               dfs(i, j, r, c, grid, visited9, &count);
               printf("\n");
               printf("Score for this trailhead:%d\n", count);
               total_score += count;
           }
        }
    }
    
    printf("Final total score:%d\n",total_score);
    
    return 0;
}
