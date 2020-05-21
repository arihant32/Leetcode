/**

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

**/


class Solution {
public:
    string intToRoman(int num) {
    int arr[7] = {1,5,10,50,100,500,1000};
    map<int,char> m;
    m[1]='I';
    m[5]='V';
    m[10]='X';
    m[50]='L';
    m[100]='C';
    m[500]='D';
    m[1000]='M';
    string str="";
    int i=6;
    int n=num;
    int rem=0,qc=0;
    while(i >=0 && n > 0)
    {
        qc = n/arr[i];
        rem = n%arr[i];
        if(qc==0 && rem==n)
        {
            i--;
        }
        else if(n>= 900 && n<1000)
        {
            str = str + m[100]+m[1000];
            n=n-900;
            i--;
        }
        else if(n>= 400 && n<500)
        {
            str = str + m[100]+m[500];
            n=n-400;
            i--;
        }
        else if(n>= 90 && n<100)
        {
            str = str + m[10]+m[100];
            n=n-90;
            i--;
        }
        else if(n>= 40 && n<50)
        {
            str = str + m[10]+m[50];
            n=n-40;
            i--;
        }
        else if(n>= 9 && n<10)
        {
            str = str + m[1]+m[10];
            n=n-9;
            i--;
        }
        else if(n>= 4 && n<5)
        {
            str = str + m[1]+m[5];
            n=n-4;
            i--;
        }
        else
        {
             while(qc--) { str = str + m[arr[i]];}
             n=rem;
             i--;
        }
    }
    return str;
    //cout << "str="<<str<<endl;
        
    }
};
