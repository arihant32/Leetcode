/*

Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.


*/

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
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* h = head;
        while(h!=NULL) {
            dq.push_back(h);
            h = h->next;
        }
        ListNode* temp;
        while(!dq.empty()) {
            ListNode* front = dq.front();
            dq.pop_front();
            // if odd number of nodes in the list
            ListNode* back = NULL;
            if(!dq.empty()) {
                back = dq.back();
                dq.pop_back();
            }
            
            if(front == head) {
                front->next = back;
                temp = back;
            } else {
                temp->next = front;
                front->next = back;
                temp = back;
            }
        }
        if(temp) temp->next = NULL; // for last node
    }
};
