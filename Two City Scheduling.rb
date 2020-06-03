=begin

Two City Scheduling : https://www.youtube.com/watch?v=vtNoP43hGJA

There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000



=end


# @param {Integer[][]} costs
# @return {Integer}


def two_city_sched_cost(costs)
    h1 = {}
    h2 = {}
    ln = costs.size
    min_cost1 = min_cost2 = 0
    costs.each do |c|
        h1[c] = c[0]-c[1]
        h2[c] = c[1]-c[0]
    end
    new_arr1 = h1.sort_by {|k,v| v}.reverse
    new_arr2 = h2.sort_by {|k,v| v}.reverse
    i = 0
    new_arr1.each do |arr|
        if i < ln/2
            min_cost1 += arr[0][0]
        else
            min_cost1 += arr[0][1]
        end
        i = i + 1
    end
    
    i = 0
    new_arr2.each do |arr|
        if i < ln/2
            min_cost2 += arr[0][0]
        else
            min_cost2 += arr[0][1]
        end
        i = i + 1
    end
    
    return [min_cost1, min_cost2].min
end
