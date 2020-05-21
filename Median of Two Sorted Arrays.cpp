/**

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

**/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        
        vector<int> nv;
        int s1=v1.size();
        int s2=v2.size();
        int i=0,j=0;
        while(i<s1 && j<s2)
        {
            if(v1[i] < v2[j]){
                nv.push_back(v1[i]);
                i++;
            }
            else{
                nv.push_back(v2[j]);
                j++;
            }
        }
        while(i<s1)
        {
            nv.push_back(v1[i]);
            i++;
        }
        while(j<s2)
        {
            nv.push_back(v2[j]);
            j++;
        }
        double ans=0;
        int ind=0;
        int type = (s1+s2)%2;
        if(type==0)
        {
            ind = (s1+s2+1)/2;
            ans = (nv[ind-1]+nv[ind])/2.0;
            return ans;
        }
        else
        {
            ind = (s1+s2+1)/2;
            ans = nv[ind-1]/1.0;
            return ans;
        }
        
    }
};
