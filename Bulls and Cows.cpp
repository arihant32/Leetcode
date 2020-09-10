/*
Bulls and Cows

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

*/



class Solution {
public:
    string getHint(string secret, string guess) {
        
        vector<int> digit_s(10,0);
        vector<int> digit_g(10,0);
        
        int i = 0, bull = 0, cows = 0;
        
        while(i < secret.size()) {
            if(secret[i] == guess[i]) {
                bull++;
            }else{
                digit_s[secret[i]-48] +=1;
                digit_g[guess[i]-48] +=1;
            }
            i++;
        }
        
        for(int i=0; i<10; i++) {
            if(digit_s[i] >0 && digit_g[i]>0) {
                if(digit_s[i] == digit_g[i] || digit_s[i] > digit_g[i])
                    cows += digit_g[i];
                else
                    cows += digit_s[i];
            } 
        }
        return to_string(bull) + "A" + to_string(cows) + "B";
    }
};
