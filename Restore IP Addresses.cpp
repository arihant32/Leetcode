/*

Restore IP Addresses


Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]
Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

*/


class Solution {
public:
    bool isValidIp(string ip) {
        vector<string> splits;
        string temp = "";
        for(int i=0; i<ip.size(); i++) {
            if(ip[i] == '.'){
                splits.push_back(temp);
                temp = "";
            }else{
                temp = temp + ip[i];
            }
        }
        splits.push_back(temp);
        
        if(splits.size() != 4) return false;
        
        string one = splits[0];
        string two = splits[1];
        string three = splits[2];
        string four = splits[3];
        //".012" is invalid as after dot zero is not posible
        if(one.size() > 1 && one[0] == '0') return false;
        if(two.size() > 1 && two[0] == '0') return false;
        if(three.size() > 1 && three[0] == '0') return false;
        if(four.size() > 1 && four[0] == '0') return false;
        
        
        if(stoi(one) >255 || stoi(two) >255 || stoi(three) >255 || stoi(four) >255) return false;
        
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        if(s.size() > 12 || s.size() < 3) return results;
        for(int i=0; i<3; i++) {
            string ns = s;
            ns.insert(i+1,".");
            for(int j=i+2; j<i+3+2 && j<s.size(); j++) {
                string nns = ns;
                nns.insert(j+1,".");
                for(int k=j+2; k<j+3+2 && k<=s.size(); k++) {
                    string nnns = nns;
                    nnns.insert(k+1,".");
                    if(isValidIp(nnns))
                        results.push_back(nnns);
                }
            }
        }
        return results;
    }
};
