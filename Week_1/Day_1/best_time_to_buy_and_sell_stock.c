#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int buyday=0;
    int maxprofit=0;
    int profit=0;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]>prices[buyday]){
            profit=prices[i]-prices[buyday];
            if(profit>maxprofit){
                maxprofit=profit;
            }
        }
        if(prices[i]<prices[buyday]){
            buyday=i;
        }   
    }
    return maxprofit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, pricesSize);

    printf("Maximum Profit: %d\n", result);

    return 0;
}