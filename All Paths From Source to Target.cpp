/*

All Paths From Source to Target


Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.

*/


class Solution {
public: 
    
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<vector<int>> result;
    int ln;
    
    void dfs(int src, int des, vector<int> &tmp, int ind) {
        tmp[ind] = src;
        visited[src] = true;
        if(src==des) {
             vector<int> cp;
             for(int k=0; k<=ind; k++) cp.push_back(tmp[k]);
             result.push_back(cp);
        }
        for(int i=0; i<ln; i++) {
            if(adj[src][i]==1 && !visited[i]) {
                dfs(i, des, tmp, ind+1);
            }
        }
        visited[src] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ln = graph.size();
        adj.resize(ln,vector<int>(ln,0));
        visited.resize(ln,false);
        
        for(int i=0; i<ln; i++) {
            int v = i;
            for(int j=0; j<graph[i].size(); j++) {
                int e = graph[i][j];
                adj[v][e] = 1;
            }
        }
        
        vector<int> tmp(ln);
        // source destination
        dfs(0, ln-1, tmp, 0);
        return result;   
    }
};
