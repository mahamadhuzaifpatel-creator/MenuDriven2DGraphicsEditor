#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            canvas[i][j]='_';
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
            printf("%c",canvas[i][j]);
        printf("\n");
    }
}

void drawLine()
{
    int row,startCol,endCol,i;

    printf("Enter row: ");
    scanf("%d",&row);

    printf("Enter start column: ");
    scanf("%d",&startCol);

    printf("Enter end column: ");
    scanf("%d",&endCol);

    for(i=startCol;i<=endCol;i++)
    {
        canvas[row][i]='*';
    }
}

void drawRectangle()
{
    int row,col,height,width;
    int i;

    printf("Enter top row: ");
    scanf("%d",&row);

    printf("Enter left column: ");
    scanf("%d",&col);

    printf("Enter height: ");
    scanf("%d",&height);

    printf("Enter width: ");
    scanf("%d",&width);

    for(i=col;i<col+width;i++)
    {
        canvas[row][i]='*';
        canvas[row+height-1][i]='*';
    }

    for(i=row;i<row+height;i++)
    {
        canvas[i][col]='*';
        canvas[i][col+width-1]='*';
    }
}
int main()
{
    initializeCanvas();

    drawLine();
    drawRectangle();

    displayCanvas();

    return 0;
}