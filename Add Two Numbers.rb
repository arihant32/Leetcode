=begin

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

=end


# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
    sum = l1.val + l2.val
    val = sum%10
    carry = sum/10
    new_list = ListNode.new(val)
    l1 = l1.next
    l2 = l2.next
    temp = new_list

    while l1 && l2
        sum = l1.val + l2.val + carry
        val = sum%10
        carry = sum/10
        temp.next = ListNode.new(val)
        temp = temp.next
        l1 = l1.next
        l2 = l2.next
    end
    
    while l1
        sum = l1.val + carry
        val = sum%10
        carry = sum/10
        temp.next = ListNode.new(val)
        temp = temp.next
        l1 = l1.next
    end
    
    while l2
        sum = l2.val + carry
        val = sum%10
        carry = sum/10
        temp.next = ListNode.new(val)
        temp = temp.next
        l2 = l2.next
    end
    
    if carry > 0
        temp.next = ListNode.new(carry)
    end
    
    return new_list
    
end
