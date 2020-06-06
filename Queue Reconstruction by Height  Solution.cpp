/**

Queue Reconstruction by Height

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


**/


class Solution {
public:
    static bool compare(vector<int> a, vector<int> b)
    {
        // sorting it in desc order of their height 
        // if height of two people is same then sort it in asc order of their k value
        return ( a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]) );
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        //sorting in desc order of their height
        sort(people.begin(), people.end(), compare);
        
        // for(int i=0; i<people.size(); i++) {
        //     cout<<"("<<people[i][0]<<","<<people[i][1]<<")"<<"  ";
        // }
        
        for(int i=0; i<people.size(); i++) {
            // vector_name.insert (position, val)
            // now we are inserting pair in k position
            result.insert(result.begin()+people[i][1], people[i]);
        }
        return result;
    }
};
