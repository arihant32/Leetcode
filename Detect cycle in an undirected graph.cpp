/*

Given an undirected graph, how to check if there is a cycle in the graph?

Example,

Input: n = 4, e = 4
Output: Yes
Explanation:
0 1, 1 2, 2 3, 0 2

*/


#include<iostream>
#include <vector>
using namespace std;

int n;

// Appying DFS
bool isCycle(int vertex, vector<vector<int>> &graph, vector<bool> &visited, int parent) {
    
    visited[vertex] = true;
    
    for(int i=0; i<n; i++)
    {
        if(graph[vertex][i] == 1)
        {
            if(visited[i]==false)
            {
                if(isCycle(i, graph,visited, vertex))
                    return true;
            }
            // If an adjacent is visited and not parent of current vertex, 
            // then there is a cycle. 
            else if(i != parent)
                return true;
        }
    }
    
    return false;
}

int main()
{
    int v = 5;
    n = v;
    vector<vector<int>> graph(v,vector<int>(v,0));
    vector<bool> visited(v,false);
    
    graph[1][0] = 1;
    graph[0][2] = 1;
    graph[2][1] = 1;
    graph[0][3] = 1;
    graph[3][4] = 1;

    bool flag = false;
    for(int i=0; i<v; i++)
    {
        if(visited[i] == false)
        {
            
            if(isCycle(i, graph, visited, -1)) // parent -1 for starting vertex
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
