/*

Critical Connections in a Network

There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.


*/



class Solution {
public:
    
    vector<vector<int>> adj, bridges;
    vector<bool> visited; 
    vector<int> disc, low;
    
    void dfs(int v, int parent)
    {
        static int tim = 1;
        disc[v] = low[v] = tim;
        tim++;
        visited[v] = true;
        
        for(auto next_v: adj[v])
        {
            if(!visited[next_v])
            {
                dfs(next_v, v);
                low[v] = min(low[v], low[next_v]);
                if(low[next_v] > disc[v])
                {
                    vector <int> temp;
                    temp.push_back(v);
                    temp.push_back(next_v);
                    bridges.push_back(temp);
                }
            }
            else if (next_v != parent)
            {
                low[v] = min(low[v], disc[next_v]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        adj.resize(n);
        visited.resize(n, false);
        disc.resize(n, INT_MAX);
        low.resize(n, INT_MAX);
        
        for(int i = 0; i<connections.size(); i++)
        {
            // undirected graph
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
//         for(int i=0; i<n; i++) {
//             cout<<i<<"--> ";
//             for(int j=0; j<adj[i].size(); j++) {
//                 cout<<adj[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//         0--> 1 2 
//         1--> 0 2 3 
//         2--> 1 0 
//         3--> 1 

        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i]) 
                dfs(i, -1); // initially parent is -1 for starting vertex
        }
                
        return bridges;
    }
};
