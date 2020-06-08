/**

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


begin to intersect at node c1.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 

Example 2:


Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 

Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.


**/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(headA == NULL || headB == NULL) return NULL;
        
        int node_cnt_a = 0;
        int node_cnt_b = 0;
        
        struct ListNode *temp, *startA = headA, *startB = headB;
        
        temp = headA;
        
        while(temp) {
            node_cnt_a++;
            temp = temp->next;
        }
        
        temp = headB;
        
        while(temp) {
            node_cnt_b++;
            temp = temp->next;
        }
        
        int node_diff = 0;
        
        if(node_cnt_a > node_cnt_b) {
            node_diff = node_cnt_a - node_cnt_b;
            
            while(node_diff) {
                node_diff--;
                startA = startA->next;
            }
        }
        else {
            node_diff = node_cnt_b - node_cnt_a;
            
            while(node_diff) {
                node_diff--;
                startB = startB->next;
            }
        }
        
        while( startA && startB) {
            if(startA == startB)
                return startA;
            startA = startA->next;
            startB = startB->next;
        }
        
        return NULL;
    }
};


// another and good solution : https://www.youtube.com/watch?v=IpBfg9d4dmQ

