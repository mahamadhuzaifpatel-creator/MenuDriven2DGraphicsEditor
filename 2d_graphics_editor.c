#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawLine()
{
    int row, startCol, endCol, i;

    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter start column: ");
    scanf("%d", &startCol);

    printf("Enter end column: ");
    scanf("%d", &endCol);

    if(row >= 0 && row < ROWS)
    {
        for(i = startCol; i <= endCol && i < COLS; i++)
        {
            if(i >= 0)
                canvas[row][i] = '*';
        }
    }
}

void drawRectangle()
{
    int row, col, height, width;
    int i;

    printf("Enter top row: ");
    scanf("%d", &row);

    printf("Enter left column: ");
    scanf("%d", &col);

    printf("Enter height: ");
    scanf("%d", &height);

    printf("Enter width: ");
    scanf("%d", &width);

    for(i = col; i < col + width && i < COLS; i++)
    {
        if(row >= 0 && row < ROWS)
            canvas[row][i] = '*';

        if(row + height - 1 < ROWS)
            canvas[row + height - 1][i] = '*';
    }

    for(i = row; i < row + height && i < ROWS; i++)
    {
        if(col >= 0 && col < COLS)
            canvas[i][col] = '*';

        if(col + width - 1 < COLS)
            canvas[i][col + width - 1] = '*';
    }
}

void drawTriangle()
{
    int row, col, height, i;

    printf("Enter top row: ");
    scanf("%d", &row);

    printf("Enter center column: ");
    scanf("%d", &col);

    printf("Enter height: ");
    scanf("%d", &height);

    for(i = 0; i < height; i++)
    {
        if(row + i < ROWS && col - i >= 0)
            canvas[row + i][col - i] = '*';

        if(row + i < ROWS && col + i < COLS)
            canvas[row + i][col + i] = '*';
    }

    for(i = col - height + 1; i <= col + height - 1; i++)
    {
        if(row + height - 1 < ROWS && i >= 0 && i < COLS)
            canvas[row + height - 1][i] = '*';
    }
}

void drawCircle()
{
    int centerRow, centerCol, radius;
    int x, y;

    printf("Enter center row: ");
    scanf("%d", &centerRow);

    printf("Enter center column: ");
    scanf("%d", &centerCol);

    printf("Enter radius: ");
    scanf("%d", &radius);

    for(x = 0; x < ROWS; x++)
    {
        for(y = 0; y < COLS; y++)
        {
            int dx = x - centerRow;
            int dy = y - centerCol;

            double d = sqrt(dx * dx + dy * dy);

            if(d >= radius - 0.5 && d <= radius + 0.5)
            {
                canvas[x][y] = '*';
            }
        }
    }
}

void deletePoint()
{
    int row, col;

    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter column: ");
    scanf("%d", &col);

    if(row >= 0 && row < ROWS &&
       col >= 0 && col < COLS)
    {
        canvas[row][col] = '_';
    }
}

void modifyPoint()
{
    int row, col;

    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter column: ");
    scanf("%d", &col);

    if(row >= 0 && row < ROWS &&
       col >= 0 && col < COLS)
    {
        canvas[row][col] = '*';
    }
}

int main()
{
    int choice;

    initializeCanvas();

    do
    {
        printf("\n");
        printf("\n===== 2D GRAPHICS EDITOR =====");
        printf("\n1. Draw Line");
        printf("\n2. Draw Rectangle");
        printf("\n3. Draw Triangle");
        printf("\n4. Draw Circle");
        printf("\n5. Delete Point");
        printf("\n6. Modify Point");
        printf("\n7. Display Canvas");
        printf("\n8. Clear Canvas");
        printf("\n9. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                drawLine();
                break;

            case 2:
                drawRectangle();
                break;

            case 3:
                drawTriangle();
                break;

            case 4:
                drawCircle();
                break;

            case 5:
                deletePoint();
                break;

            case 6:
                modifyPoint();
                break;

            case 7:
                displayCanvas();
                break;

            case 8:
                initializeCanvas();
                printf("Canvas Cleared!\n");
                break;

            case 9:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 9);

    return 0;
}