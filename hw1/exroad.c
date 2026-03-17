#include <stdio.h>
#include <stdlib.h>
int main()
{

    FILE *fs;
    fs = fopen("exinput.txt", "r");
    int roadnum = 0;
    int rownum = 0, colnum = 0;
    fscanf(fs, "%d", &roadnum);
    printf("해결해야할 미로의 숫자는 %d입니다.\n", roadnum);
    fscanf(fs, "%d %d", &rownum, &colnum);
    fscanf(fs, "\n"); // 위의 2번 줄 스킵
    printf("미로의 크기는 %d x %d입니다.\n", rownum, colnum);
    int **map = malloc(sizeof(int *) * rownum);
    for (int i = 0; i < rownum; i++)
    {
        map[i] = malloc(sizeof(int) * colnum);
    }
    char line[100];
    for (int i = 0; i < rownum; i++)
    {
        for (int j = 0; j < colnum; j++)
        {
            fscanf(fs, "%d", &map[i][j]);
        }
    }

    for (int i = 0; i < rownum; i++)
    {
        for (int j = 0; j < colnum; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    

    for (int i = 0; i < rownum; i++)
    {
        free(map[i]);
    }
    free(map);
    fclose(fs);
    return 0;
}