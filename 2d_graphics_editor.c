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

void drawTriangle()
{
    int row,col,height,i;

    printf("Enter top row: ");
    scanf("%d",&row);

    printf("Enter center column: ");
    scanf("%d",&col);

    printf("Enter height: ");
    scanf("%d",&height);

    for(i=0;i<height;i++)
    {
        canvas[row+i][col-i]='*';
        canvas[row+i][col+i]='*';
    }

    for(i=col-height+1;i<=col+height-1;i++)
    {
        canvas[row+height-1][i]='*';
    }
}

void drawCircle()
{
    int centerRow,centerCol,radius;
    int x,y;

    printf("Enter center row: ");
    scanf("%d",&centerRow);

    printf("Enter center column: ");
    scanf("%d",&centerCol);

    printf("Enter radius: ");
    scanf("%d",&radius);

    for(x=0;x<ROWS;x++)
    {
        for(y=0;y<COLS;y++)
        {
            int dx=x-centerRow;
            int dy=y-centerCol;

            double d=sqrt(dx*dx+dy*dy);

            if(d>=radius-0.5 && d<=radius+0.5)
            {
                canvas[x][y]='*';
            }
        }
    }
}

int main()
{
    initializeCanvas();

    drawLine();
    drawRectangle();
    drawTriangle();
    drawCircle();

    displayCanvas();

    return 0;
}