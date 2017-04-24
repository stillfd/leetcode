#include<stdio.h>
#include<string.h>

int islandPerimeter(int grid[][4], int gridRowSize, int gridColSize)
{
    int cnt = 0;
    for(int i = 0; i < gridRowSize; i++)
    {
        for(int j = 0; j < gridColSize; j++)
        {
            int ct = 4;
            if(!grid[i][j])
            {
                continue;
            }
            if(i && grid[i-1][j])
            {
                ct--;
            }           
            if(j && grid[i][j-1])
            {
                ct--;
            }
            if(i< gridRowSize - 1 && grid[i+1][j])
            {
                ct--;
            }
            if(j < gridColSize - 1 && grid[i][j+1])
            {
                ct--;
            }
            cnt += ct;
        }
    }
    return cnt;
}

void main(void)
{
    int grid[4][4] = {{0,1,0,0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int result =  islandPerimeter(grid, 4, 4);
    printf("the perimeter is >> %d\r\n", result);
    return;
}
