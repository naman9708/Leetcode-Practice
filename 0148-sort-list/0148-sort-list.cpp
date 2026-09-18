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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* node = head;
        while(node!= NULL){
            arr.push_back(node->val);
            node = node->next;
        }
        sort(arr.begin(),arr.end());
        node = head;
        int i = 0;
        while(i<arr.size()){
            node->val = arr[i];
            node = node->next;
            i++;
        }
        return head;
    }
};