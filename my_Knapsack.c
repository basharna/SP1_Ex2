#include <stdio.h>
#include <math.h>

#define MAXWEIGHT 20
#define MAXITEMS 5 

int max(int a, int b) {
    return (a > b) ? a : b;
}

void setInputs(char items[],int weights[], int values[]){
    int i;
    for(i = 0; i < MAXITEMS; i++){
        scanf("%s", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
    
}
int knapSack (int weights[], int values[] , int selected_bool[]){

    int dp[MAXITEMS + 1][MAXWEIGHT + 1];
    int i, w;

    for (i = 0; i <= MAXITEMS; i++) {
        for (w = 0; w <= MAXWEIGHT; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int sz = MAXWEIGHT;
    for (int i = MAXITEMS; i > 0; i--)
    {
        if (dp[i][sz] != dp[i - 1][sz])
        {
            selected_bool[i - 1] = 1;
            sz -= weights[i - 1];
        }
    }
    

    return dp[MAXITEMS][MAXWEIGHT];
}

int main() {
    char items[MAXITEMS];
    int weights[MAXITEMS];
    int values[MAXITEMS];
    int result[MAXITEMS] = {0};
    setInputs(items, weights, values);
    int profit = knapSack(weights, values, result);
    printf("Maximum profit: %d\n", profit);
    printf("Selected items:");
    for(int i = 0; i < MAXITEMS; i++){
        if(result[i] == 1){
            printf(" %c", items[i]);
        }
    }
    return 0;
}