/*


Majority Element II


Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]


*/


class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> results;
        
        int ln = nums.size();
        
        if(ln == 0) return results;
        
        int count1 = 0, count2 = 0;
        
        int candidate1 = nums[0], candidate2 = nums[0];
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(candidate1 == nums[i]) 
                count1++;
            else if(candidate2 == nums[i]) 
                count2++;
            else if(count1 == 0){
                count1 = 1;
                candidate1 = nums[i];   
            }else if(count2 == 0){
                count2 = 1;
                candidate2 = nums[i];   
            }else {
                count1--;
                count2--;
            } 
        }
        
        count1 = 0, count2 = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == candidate1)
                count1++;
            
            if(nums[i] == candidate2)
                count2++;
        }
        
        if(count1 > ln/3)
            results.push_back(candidate1);
        
        if(count2 > ln/3 && candidate1 != candidate2)
            results.push_back(candidate2);
        
        return results;   
    }
};



   
