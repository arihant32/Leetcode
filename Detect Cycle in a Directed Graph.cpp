/*

Detect Cycle in a Directed Graph : https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.
Example,

Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes

*/

#include<iostream>
#include <vector>
using namespace std;


int n;

// Appying DFS
bool isCycle(int vertex, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack) {
    
    visited[vertex] = true;
    recStack[vertex] = true;
    
    for(int i=0; i<n; i++)
    {
        if(graph[vertex][i] == 1)
        {
            if(visited[i]==false)
            {
                if(isCycle(i, graph,visited,recStack))
                    return true;
            }
            else if(recStack[i])
                return true;
        }
    }
    
    recStack[vertex] = false;
    return false;
}

int main()
{
    //Input: n = 4, e = 6
    //0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
    // Output : Yes
    // vertex and edges
    
    int v = 4, e=6;
    n = v;
    vector<vector<int>> graph(v,vector<int>(v,0));
    vector<bool> visited(v,false);
    vector<bool> recStack(v,false);
    
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[2][3] = 1;
    graph[3][3] = 1;
    
    
    bool flag = false;
    for(int i=0; i<v; i++)
    {
        if(visited[i] == false)
        {
            if(isCycle(i, graph, visited, recStack))
            {
                flag = true;
                break;
            }
        }
    }
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
    
    return 0;
}
