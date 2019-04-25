#include<stdio.h>
int count = 0;

int notDanger(int row, int col, int(*chess)[8])
{
	int i, j;
	for(i = 0; i < 8; i++)
	{
		if(chess[i][col])
			return 0;
	}
	for(i = row,j = col; i>=0 && j>=0;i--,j--)
	{
		if(chess[i][j])
			return 0;
	}
	for(i = row,j = col; i>=0 && j<8;i--,j++)
	{
		if(chess[i][j])
			return 0;
	}
	for(i = row,j = col; i<8 && j>=0;i++,j--)
	{
		if(chess[i][j])
			return 0;
	}
	for(i = row,j = col; i<8 && j<8;i++,j++)
	{
		if(chess[i][j])
			return 0;
	}
	return 1;
}

void EQ(int row, int n, int(*chess)[8])
{
	int chess2[8][8] = {0};
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}
	if(8 == row)
	{
		printf("the %d solution\n", count+1);
		for(int i = 0; i< 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				printf("%d ", chess2[i][j]);
			}
			printf("\n");
		}
		count++;
	}
	else
	{
		for(int j = 0; j < n; j++)
		{
			if(notDanger(row, j, chess))
			{
				// printf("1\n");
				for(int i = 0; i < 8; i++)
				{
					chess2[row][i] = 0;
				}
				chess2[row][j] = 1;
				EQ(row+1, n, chess2);
			}
		}
	}
}
int main()
{
	int chess[8][8] = {0};
	EQ(0,8,chess);
	return 0;

}