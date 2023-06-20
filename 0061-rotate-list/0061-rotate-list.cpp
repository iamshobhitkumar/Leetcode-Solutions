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
    ListNode* rotateRight(ListNode* head, int k) {
        int n  = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        if(n==0 || k==0 || n==k) return head;
        k%=n;
        if(k==0) return head;
        n-=k;
        temp = head;
        while(--n){
            temp = temp->next;
        }
        ListNode* temp2 = temp;
        temp2 = temp2->next;
        ListNode* ans = temp2;
        temp->next = NULL;
        while(temp2->next){
            temp2 = temp2->next;
        }
        temp2->next = head;
        return ans;
    }
};