/*
Link: https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same 
element twice.
You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // We can use a hashmap in order to store the values ​​of both the number and its index
    // map<number, index>
    unordered_map<int, int> map;

    // We need to traverse the vector and compute the missing value to complete the target
    for (int i = 0; i < nums.size(); i++){
        int missingValue = target - nums[i];

        // If we have already saved that value in our unordered map, we return both the current 
        // index and the missing value's index
        if (map.find(missingValue) != map.end()){
            return {i, map[missingValue]};
        }

        // Otherwise, we store the new value and its index for future calculations
        map[nums[i]] = i;
    }
    
    // No solution exists
    return {-1, -1};
}

int main(){
    // Test 1
    vector<int> nums1 {2, 7, 11, 15}, test1;
    int target1 = 9;
    test1 = twoSum(nums1, target1);

    cout << "Test 1: ";
    for (int n : test1){
        cout << to_string(n) + " "; 
    }

    // Test 2
    cout << "\nTest 2: ";
    vector<int> nums2 {3, 2, 4}, test2;
    int target2 = 6;
    test2 = twoSum(nums2, target2);

    for (int n : test2){
        cout << to_string(n) + " "; 
    }

    // Test 3
    cout << "\nTest 3: ";
    vector<int> nums3 {3, 3}, test3;
    int target3 = 6;
    test3 = twoSum(nums3, target3);

    for (int n : test3){
        cout << to_string(n) + " "; 
    }

    cout << endl;
}