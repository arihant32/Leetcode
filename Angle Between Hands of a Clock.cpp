/*

Angle Between Hands of a Clock

Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.

 

Example 1:



Input: hour = 12, minutes = 30
Output: 165
Example 2:



Input: hour = 3, minutes = 30
Output: 75
Example 3:



Input: hour = 3, minutes = 15
Output: 7.5
Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.
*/



class Solution {
public:
    double angleClock(int hour, int minutes) {
        // hour hand
        // 1hr angle is = 30 degree
        // 1min angle is = 1/2 degree
        
        // minute hand
        // 1hr is = 0 degree
        // 1min is = 360/60 = 6 degree
        
        float hr_angle = hour*30 + (0.5)*minutes;
        float min_angle = hour*0 + (6)*minutes;
        float angle1 = abs(hr_angle - min_angle);  
        float angle2 = 360 - angle1;
        if(angle1 > angle2) 
            return angle2;
        else
            return angle1;
    }
};
