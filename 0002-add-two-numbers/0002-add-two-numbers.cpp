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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = NULL;
        int s1 = 1;
        int s2 = 1;

        while (temp1->next != NULL || temp2->next != NULL) {
            if (temp1->next != NULL) {
                s1++;
                temp1 = temp1->next;
            }
            if (temp2->next != NULL) {
                s2++;
                temp2 = temp2->next;
            }
        }
        temp1 = l1;
        temp2 = l2;
        ListNode* temp = NULL;
        if (s1 > s2) {
        int carry = 0;
        while (temp1 != NULL) {
            int n = 0;
            if(temp2 != NULL){
            n = temp1->val + temp2->val;
            temp2 = temp2->next;
            }
            else {
                n = temp1->val;
            }
            int x = -1;
            if ((n+carry)>= 10) {
                n = n + carry;
                x = (n % 10);
                carry = 0;
                n = n / 10;
                carry = n;
            } else {
                x = n + carry;
                carry = 0;
            }

            ListNode* e = new ListNode(x);

            if (temp == NULL) {
                temp = e;
                ans = e;
            } else {
                temp->next = e;
                temp = e;
            }
            temp1 = temp1->next;
        }
        if(carry != 0){
            ListNode* e = new ListNode(carry);
            temp->next = e;
            temp = e;
        }

        } else if (s2 > s1) {
            int carry = 0;
        while (temp2 != NULL) {
            int n = 0;
            if(temp1 != NULL){
             n = temp1->val + temp2->val;
            temp1 = temp1->next;
            }
            else {
                n = temp2->val;
            }
            int x = -1;
            if ((n+carry) >= 10) {
                n =  n + carry;
                x = (n % 10);
                carry = 0;
                n = n / 10;
                carry = n;
            } else {
                x = n + carry;
                carry = 0;
            }

            ListNode* e = new ListNode(x);

            if (temp == NULL) {
                temp = e;
                ans = e;
            } else {
                temp->next = e;
                temp = e;
            }
            temp2 = temp2->next;
        }
         if(carry != 0){
            ListNode* e = new ListNode(carry);
            temp->next = e;
            temp = e;
        }
        
        }
        else{
        int carry = 0;
        while (temp1 != NULL) {
            int n = temp1->val + temp2->val;
            int x = -1;
            if ((n+carry) >= 10) {
                n = n + carry;
                x = (n % 10);
                carry = 0;
                n = n / 10;
                carry = n;
            } else {
                x = n + carry;
                carry = 0;
            }

            ListNode* e = new ListNode(x);

            if (temp == NULL) {
                temp = e;
                ans = e;
            } else {
                temp->next = e;
                temp = e;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(carry != 0){
            ListNode* e = new ListNode(carry);
            temp->next = e;
            temp = e;
        }
        }
        //    if(temp->val >= 10){
        //     int n = temp->val;
        //     int x = n%10;
        //     n = n/10;
        //     temp->val = x;
        //     ListNode* e = new ListNode(n);
        //     temp->next = e;
        //     temp =e;
        // }

        return ans;
    }
    
};