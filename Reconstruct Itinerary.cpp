/*

Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
             

*/


class Solution {
public:
    void dfs(string src,unordered_map<string,vector<string>> &mp,vector<string> &result){
        while(!mp[src].empty()){
            string s = mp[src].back();
            mp[src].pop_back();
            dfs(s,mp,result);
        }
        result.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        vector<string> result;
        int ln = tickets.size();
        for(auto tkt : tickets) {
           string from = tkt[0];
           string to = tkt[1];
           mp[from].push_back(to);
        }
        
        // sorting as need lexical order
        // Sorting in descending order since we will be popping elements from the end of the vecotr
        for(auto ptr=mp.begin(); ptr!=mp.end(); ptr++) {
            sort(ptr->second.begin(), ptr->second.end(), greater<string>());
        }
        
        // for(auto ptr=mp.begin(); ptr!=mp.end(); ptr++) {
        //     cout<<ptr->first<<"->";
        //     for(auto i : ptr->second) cout<<i<<" ";
        //     cout<<"\n";
        // }
        
        // ATL->SFO JFK 
        // JFK->SFO ATL 
        // SFO->ATL 
        
        dfs("JFK",mp,result);
        reverse(result.begin(),result.end());
        return result;
    }
};
