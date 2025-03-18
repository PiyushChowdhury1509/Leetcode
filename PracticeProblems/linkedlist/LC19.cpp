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
            if(!head->next){
                if(n==1) return {};
                return head;
            }
            ListNode*slow=new ListNode(-1);
            ListNode*dummy=slow;
            slow->next=head;
            ListNode*fast=head;
            int copy=n;
            while(copy--) fast=fast->next;
            while(fast){
                fast=fast->next;
                slow=slow->next;
            }
            if(slow==dummy) return head->next;
            slow->next=slow->next->next;
            return head;
        }
    };