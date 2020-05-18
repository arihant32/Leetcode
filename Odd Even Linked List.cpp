/**
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

**/

// code :-

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // empty or one node or two node
        if(head == NULL || head->next == NULL || head->next->next == NULL) 
            return head;
        
        ListNode* even=head->next;
        ListNode* temp=head->next;
        ListNode* odd=head;
        
        while(odd->next!=NULL)
        {
            if(even!=NULL) 
                odd->next = even->next;
            if(odd->next!=NULL)
                even->next = odd->next->next;
            if(odd->next!=NULL)
                odd = odd->next;
            if(even!=NULL)
                even = even->next;
        }
        odd->next = temp;
        return  head;
         
    }
};