=begin

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

=end

# @param {Integer[]} nums
# @return {Integer}
def find_max_length(nums)
    count = 0
    hh = {}
    max_len = 0
    (0...nums.size).each do |i|
        count = count + (nums[i] == 0 ? -1 : 1 )
        if count == 0
            # to find max or min of tow number in ruby say no 4,10 -> [4,10].max ==> 10
            max_len = [max_len, i+1].max
        elsif hh.key?(count)
            max_len = [max_len, i - hh[count]].max
        else
            hh[count] = i
        end
    end
    max_len
end
