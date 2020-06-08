/**

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

**/

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
    
    ListNode* merge_two_lists(ListNode* l1, ListNode* l2) {

        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* temp = NULL, *head = NULL;
        
        if(l1->val < l2->val) {
            temp = l1;
            l1 = l1->next;   
        }
        else {
            temp = l2;
            l2 = l2->next;
        }
        
        head = temp;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;   
            }
            else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        
        while(l1) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next; 
        }
        
        while(l2) {
            temp->next = l2;
            temp = l2;
            l2 = l2->next; 
        }
        
        return head;  
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* head = lists[0];
        // used concept of merge two linked lists
        for(int i=1; i<lists.size(); i++)
            head = merge_two_lists(head, lists[i]);
        
        return head;
    }
};
