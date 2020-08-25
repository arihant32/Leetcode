/*

Minimum Cost For Tickets


In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: 
For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total you spent $17 and covered all the days of your travel.
 

Note:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000

*/




// Solution One : Recursion


class Solution {
public:
    
    int getMicCost(vector<int>& days, vector<int>& costs, int index) {
        if(index >= days.size()) return 0;
        
        // taking one day pass and going to next day 
        int option_1 = costs[0] + getMicCost(days, costs, index+1);
        
        
        // from present day taking 7 days pass and will buy it again agter 7 days
        // eg : 1 2 3 4 5 6 7 8 9 10 11 12 13 say if we at 3rd day then we can go up to 9 and will again buy pass at 10th day
        int i;
        for(i = index; i<days.size(); i++) {
            if(days[i] >= days[index]+7) break;
        }
        int option_2 = costs[1] + getMicCost(days, costs, i);
        
        // from present day taking 30 days pass and will buy it again agter 30 days
        int j;
        for(j = index; j<days.size(); j++) {
            if(days[j] >= days[index]+30) break;
        }
        int option_3 = costs[2] + getMicCost(days, costs, j);
        
        // now retuning min of all the three options that is 1 day pass, 7 day pass and 30 day pass
        return min(option_1, min(option_2, option_3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return getMicCost(days, costs, 0);
    }
};
