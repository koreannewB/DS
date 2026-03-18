#include <stdio.h>
#include <stdlib.h>


// gcc exroad1.c -o exroad1
// ./exroad1
void mping (int **map, int *rownum, int *colnum, int *currentrow, int *currentcol, int *endrow, int *endcol, int *count);
void mping (int **map, int *rownum, int *colnum, int *currentrow, int *currentcol, int *endrow, int *endcol, int *count)
    {
        
       
        
        for (int i = 0; i < *rownum; i++)
    {
        for (int j = 0; j < *colnum; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
        //오류체크용
        printf("현재 좌표(%d, %d)\n", *currentrow, *currentcol);
        printf("목적지 좌표(%d, %d)\n", *endrow, *endcol);
        printf("미로의 크기 (%d x %d)\n", *rownum, *colnum);
        if (map[*currentrow+1][*currentcol] == 1 && map[*currentrow][*currentcol+1] == 1){
            printf("양쪽길 모두 존재");
            mping(map, rownum, colnum, currentrow, currentcol, endrow, endcol);
        }
        if (map[*currentrow+1][*currentcol] == 1){
            printf("아래길 존재");
            (*currentrow)++;
            mping(map, rownum, colnum, currentrow, currentcol, endrow, endcol);
        }
        if (map[*currentrow][*currentcol+1] == 1){
            printf("오른쪽길 존재");
            (*currentcol)++;
            mping(map, rownum, colnum, currentrow, currentcol, endrow, endcol);
        }
        else{
            printf("길이 없습니다.");
            if (*currentrow == *endrow && *currentcol == *endcol)
            {
                printf("탈출했습니다.\n");
                printf("탈출한 경우의 수는 %d입니다.\n", *count);
                return;
            }
        }

        // switch(map[*currentrow+1][*currentcol])
        //     {
        //         case 0:
        //             printf("0입니다.\n");
        //             if (*currentrow == *endrow && *currentcol == *endcol)
        //             {
        //                 printf("탈출했습니다.\n");
        //                 count++;
        //                 return;
        //             }
        //             break;
        //         case 1:
        //             printf("1입니다.\n");
        //             (*currentrow)++;
        //             mping(map, rownum, colnum, currentrow, currentcol, endrow, endcol);
        //             break;
        //         default:
        //             printf("그 외의 숫자입니다.\n");
        //     }
        // switch(map[*currentrow][*currentcol+1])
        //     {
        //         case 0:
        //             printf("0입니다.\n");
        //             if (*currentrow == *endrow && *currentcol == *endcol)
        //             {
        //                 printf("탈출했습니다.\n");
        //                 count++;
        //                 return;
        //             }
        //             break;
        //         case 1:
        //             printf("1입니다.\n");
        //             (*currentcol)++;
        //             mping(map, rownum, colnum, currentrow, currentcol, endrow, endcol);
        //             break;
        //         default:
        //             printf("그 외의 숫자입니다.\n");
        //     }
    } 
   
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

    
    int startrow = 0, startcol = 0;
    int endrow = rownum - 1, endcol = colnum - 1;
    int currentrow = startrow, currentcol = startcol;
    int count = 0;
   
    mping(map,&rownum, &colnum,&currentrow, &currentcol, &endrow, &endcol, &count);
    //printf("탈출한 경우의 수는 %d입니다.\n", count);









    // 초기화
    for (int i = 0; i < rownum; i++)
    {
        free(map[i]);
    }
    free(map);
    fclose(fs);
    return 0;
}