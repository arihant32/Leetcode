/**

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

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
    struct ListNode* rotateRight(struct ListNode *head, int k) {
        if(k==0)
            return head;
        int num_of_node = 0;
        struct ListNode *pre=NULL,*ptr=head;
        while(ptr!=NULL)
        {
            num_of_node++;
            pre=ptr;
            ptr = ptr->next;
        }
        if(num_of_node==0)
            return head;
        k = k%num_of_node;
        
        while(num_of_node!=k)
        {
            pre->next = head;
            pre = head;
            head = head->next;
            num_of_node--;  
        }
        pre->next = NULL;
        
        return head;
    }
    
};
