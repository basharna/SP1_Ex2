#include <stdio.h>
#include "my_mat.h"

int main()
{
    int mat[10][10];

    char c;
    int i, j;
    while(1){
        scanf("%c", &c);
        switch (c)
        {
        case 'A':
            setMatrix(mat);
            break;
        case 'B':

            break;
        case 'C':
            scanf("%d", &i);
            scanf("%d", &j);
            printf("%d\n", shortestPath(i, j));
            break;
        case 'D':
            return 0;
        default:
            break;
        }
        
        
    }
    
    return 0;
}
