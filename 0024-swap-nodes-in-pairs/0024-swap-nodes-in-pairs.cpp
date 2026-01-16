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
    ListNode* swapPairs(ListNode* head) {
        int k = 2;
                int n = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            if(n==k){
                break;
            }
            temp = temp->next;
            n++;
        }
        if(n<k)return head;
        n = 1;
        temp = head;
        ListNode* p = head;
        ListNode* prev = NULL;
        while(n <= k){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            n++;
            if(n == k+1){
                p->next = swapPairs(temp);
            }

        }
        return prev;
    }
};