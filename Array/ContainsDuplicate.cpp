/*
Link: https://leetcode.com/problems/contains-duplicate/

Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    // We can use an unordered map in order to keep track of the numbers occurrences
    // map<number, occurrences>
    unordered_map<int, int> map;

    for (int n : nums){
        // The number hasn't been seen. We need to save it in our map
        if (map[n] < 1){
            map[n] = 1;
        } 
        // The number is in the map, in other words, it has already been seen (repeated)
        else{
            return true;
        }
    }

    // We didn't find any duplicates
    return false;
}

int main(){
    // Test 1
    vector<int> v1 {1, 2, 3, 1};
    string ans1 = containsDuplicate(v1) ? "True" : "False";
    cout << "Test 1: " << ans1 << endl;
    
    // Test 2
    vector<int> v2 {1, 2, 3, 4};
    string ans2 = containsDuplicate(v2) ? "True" : "False";
    cout << "Test 2: " << ans2 << endl;
}