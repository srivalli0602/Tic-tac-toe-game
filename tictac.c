#include<stdio.h>
char board[3][3];
int i,j;
int count=0;
void initialize()
{
	char ch='1';
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			board[i][j]=ch++;
		}
		printf("\n");
	}
}
void printboard()
{
	printf("\n\t Tic Tac Toe\n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf(" %c ",board[i][j]);
			if(j<2)
			{
				printf("|");
			}
		}
		printf("\n");
		if(i<2)
		{
			printf("---|---|---\n");
		}
	}
	printf("\n");
}
int wincheck()
{
	for(i=0;i<3;i++)
	{
	       if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
	       {
		       return 1;
	       }
	       if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
               {
                       return 1;
               }
	}
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
	{
		return 1;
	}
	if(board[0][2]==board[1][1] && board[1][1]==board[2][1])
	{
		return 1;
	}
	return 0;
}
void player1()
{
	int choice,row,col;
   input:printf("Player1(x),enter number:\n");
	scanf("%d",&choice);
	if(choice<1 || choice>9)
	{
		printf("invalid choice\n");
		goto input;
	}
	row=(choice-1)/3;
	col=(choice-1)%3;
	if(board[row][col]=='X' || board[row][col]=='O')
	{
		printf("Already filled\n");
		goto input;
	}
	board[row][col]='X';
}
void player2()
{
	int choice,row,col;
   input:printf("Player2(O),enter number:\n");
        scanf("%d",&choice);
        if(choice<1 || choice>9)
        {
                printf("invalid choice\n");
                goto input;
        }
        row=(choice-1)/3;
        col=(choice-1)%3;
        if(board[row][col]=='X' || board[row][col]=='O')
        {
                printf("Already filled\n");
                goto input;
        }
        board[row][col]='O';
}
int main()
{
	initialize();
	printboard();
	while(count<9)
	{
		player1();
		count++;
		printboard();
		if(wincheck())
		{
			printf("Player1 wins\n");
			break;
		}
		if(count==9)
		{
			printf("Game draw\n");
			break;
		}
		player2();
                count++;
                printboard();
                if(wincheck())
                {
                        printf("Player2 wins\n");
                        break;
                }
	}
}
