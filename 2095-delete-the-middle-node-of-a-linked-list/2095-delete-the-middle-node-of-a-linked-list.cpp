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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == NULL) return NULL;
        ListNode* a = head;
        ListNode* b = head;
        ListNode* prev = NULL;
        while(b!=NULL && b->next!=NULL){
            prev = a;
            a = a->next;
            b = b->next->next;
        }
        ListNode* n = a->next;
        prev->next = n;
        return head;
    }
};