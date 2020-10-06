/*

Cutting a Rod


Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if length of the rod is 8 and the values of different pieces are given as following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20


*/


// solution one : recursive

#include<iostream>
#include<vector>
using namespace std;

int cutRod(vector<int> &prices, int rodLen) {
    
    if(rodLen <= 0) return 0;
    
    int maxProfix = INT_MIN;
    
    //Recursively cut the rod in different pieces
    
    for(int i=1; i<=rodLen; i++){
        maxProfix = max(maxProfix, prices[i-1] + cutRod(prices, rodLen - i));
    }
    
    return maxProfix;
}

int main()
{
    vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20};
    int ln = prices.size();
    cout<<"Max Profit is : "<<cutRod(prices, ln)<<"\n";
    
    vector<int> prices1{3, 5, 8, 9, 10, 17, 17, 20};
    ln = prices1.size();
    cout<<"Max Profit is : "<<cutRod(prices1, ln)<<"\n";
    
    return 0;
}

/*

output 

Max Profit is : 22

Max Profit is : 24

*/

