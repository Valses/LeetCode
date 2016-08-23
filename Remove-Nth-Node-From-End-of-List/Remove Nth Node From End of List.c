//
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//   Given linked list: 1->2->3->4->5, and n = 2.
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *p = head, *q = head;
    int i = 0;
    for(i; i < n; i++){
        p = p->next;
    }
    if(!p){
        head = head->next;
        return head;
    }
        
    while(p->next){
        p = p->next;
        q = q->next;
    }
    q->next = q->next->next;
    return head;
}
