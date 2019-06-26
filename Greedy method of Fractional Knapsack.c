#include <stdio.h>
 
int n = 4; 
int capacity[10] = {10, 4, 2, 1}; 
int value[10] = {4, 2, 5, 5}; 
int MaxWeight = 11;
 
void fractional_knapsack() {
    int currentweight;
    float totalvalue;
    int i, maximum;
    int used[10];
 
    for (i = 0; i < n; ++i)
        used[i] = 0; 
 
    currentweight = MaxWeight;
    while (currentweight > 0) { 
        
        maximum = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maximum == -1) || ((float)value[i]/capacity[i] > (float)value[maximum]/capacity[maximum])))
                maximum = i;
 
        used[maximum] = 1;
        currentweight -= capacity[maximum]; 
        totalvalue += value[maximum];
        if (currentweight >= 0)
            printf("Added object %d (Rs. %d, %dKg) completely in the bag. Space left: %d.\n", maximum + 1, value[maximum], capacity[maximum], currentweight);
        else {
            printf("Added %d%% (Rs. %d, %dKg) of object %d in the bag.\n", (int)((1 + (float)currentweight/capacity[maximum]) * 100), value[maximum], capacity[maximum], maximum + 1);
            totalvalue -= value[maximum];
            totalvalue += (1 + (float)currentweight/capacity[maximum]) * value[maximum];
        }
    }
 
    printf("Filled the bag with objects worth Rs. %.2f .\n", totalvalue);
}
 
int main(int argc, char *argv[]) {
    fractional_knapsack();
 
    return 0;
}
