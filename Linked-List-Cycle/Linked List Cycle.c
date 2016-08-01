//
//Given a linked list, determine if it has a cycle in it. 
//
//
//
//Solution:
//Two pointers,one is slow and another is fast.If they meet each other,then the cycle exist.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head || !head->next)
        return false;
    struct ListNode *fast = head->next, *slow = head;
    while(fast != slow){
        if(!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }
    return true;
}
