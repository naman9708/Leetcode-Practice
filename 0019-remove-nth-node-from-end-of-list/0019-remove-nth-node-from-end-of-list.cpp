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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* r = head;
        ListNode* t = head;
        int cnt = 0;
        while(t->next != NULL){
            cnt ++;
            t = t->next;
        }
        int cn = 0;
        ListNode* prev = head;
        while(r->next!=NULL){
            if(cnt-cn+1==n){
                break;  
            }
            cn++;
            prev = r;
            r = r->next;
        }
        
        cout<<r->val<<cnt<<prev->val;
        if(n==1){
            if(cnt+1 == 1){
                head = NULL;
                return head;
            }
            prev->next = NULL;
            return head;
        }
        if(r==head){
            head = head->next;
            return head;
        }
        prev->next = r->next;
        return head;
    }
};