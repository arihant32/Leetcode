/**

Possible Bipartition

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

**/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // 2D matrix for adjacency list. taking size one extra as will start index from 1 instead of 0
        vector<vector<int> > mat(N+1, vector<int> (N+1, 0));  
            
        for(int i=0; i<dislikes.size(); i++) {
            // assigning edges as it's undirected
            mat[dislikes[i][0]][dislikes[i][1]] = 1;
            mat[dislikes[i][1]][dislikes[i][0]] = 1 ;
        }
        
        vector<int> color(N+1, 0);
        
        for(int i=1; i<=N; i++) 
        {
            // assigning color if not yet assigned
            if(color[i] == 0) 
            {
                color[i] = 1;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int index = q.front();
                    q.pop();
                    for(int x = 1; x<=N; x++)
                    {
                        if(mat[index][x] == 1)
                        {
                            // both having same color
                            if(color[index] == color[x])
                                return false;
                            if(color[x] == 0)
                            {
                                color[x] = -color[index];
                                q.push(x);   
                            }
                        }
                    }
                }
            }          
        }

        return true;
    }
};
