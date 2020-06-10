/**

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

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
    
    ListNode* merge(ListNode *a, ListNode *b) {    
        if(a == NULL) return b;
        if(b == NULL) return a;
        ListNode *result;
        if(a->val < b->val) {
            result = a;
            a->next = merge(a->next, b);
        }else{
            result = b;
            b->next = merge(a, b->next);
        }
        return result;   
    }
    
    void front_back_split(ListNode *source, ListNode **front, ListNode **back) {
        
        if(source == NULL || source->next == NULL) {
            *front = source;
            *back = NULL;
        }
        
        ListNode *slow = source;
        ListNode *fast = source->next;
        
        // spliting linked list into two part based on slow and past pointer
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        *front = source;
        *back = slow->next;
        slow->next = NULL;      
    }
    
    
    ListNode* sort(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *a, *b;
        front_back_split(head, &a, &b);
        return  merge(sort(a),sort(b));
    }
    ListNode* sortList(ListNode* head) {
        return sort(head);  
    }
};
