=begin


Unique Paths : https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.


=end


# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def unique_paths(m, n)
    # m -> col
    # n -> row
    two_d = Array.new(n) { Array.new(m, 0) };

    # 1st row
    (0...m).each { |i| two_d[0][i] = 1 }
    
    # 1st col
    (0...n).each { |i| two_d[i][0] = 1 }
    
    #row
    (1...n).each do |i|
        #col
        (1...m).each do |j|
            # [    ] [top]
            # [left] [here]
            # no of way top + no of way right
            two_d[i][j] = two_d[i-1][j] + two_d[i][j-1]
        end
    end
    return two_d[n-1][m-1]
end
