/*
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any 
profit, return 0.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    // We know that on day 1, the minValue is the current price and the maxProfit is 0
    int minValue = prices[0], maxProfit = 0;

    // We will traverse the array to compute the maxProfit
    for (int p : prices){
        // The minValue needs to update in every iteration. The only condition is to check
        // if the current value is lesser/smaller than the minValue
        minValue = min(minValue, p);

        // MaxProfit checks if the current MaxProfit is greater than the current computed
        // maximum profit. If minValue is greater than the current stock's price, that'll give a 
        // negative value, then, maxProfit won't update. If for some reason, minValue's always 
        // greater than the current stock's price, maxProfit will be 0
        maxProfit = max(maxProfit, p - minValue);
    }

    return maxProfit;
}

int main(){
    // Test 1
    vector<int> v1 {7, 1, 5, 3, 6, 4};
    cout << "Test 1: " << maxProfit(v1) << endl;

    // Test 2
    vector<int> v2 {7, 6, 4, 3, 1};
    cout << "Test 2: " << maxProfit(v2) << endl;
}