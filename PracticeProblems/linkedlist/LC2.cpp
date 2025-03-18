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
            ListNode*temp=new ListNode(-1);
            ListNode*temp1=l1;
            ListNode*temp2=l2;
            ListNode*trav=temp;
            int carry=0;
            while(temp1 || temp2){
                int val1=0,val2=0;
                if(temp1){
                    val1=temp1->val;
                    temp1=temp1->next;
                }
                if(temp2){
                    val2=temp2->val;
                    temp2=temp2->next;
                }
                ListNode*a=new ListNode((val1+val2+carry)%10);
                if((val1+val2+carry)>=10) carry=1;
                else carry=0;
                trav->next=a;
                trav=trav->next;
            }
            if(carry>0){
                ListNode*a=new ListNode(1);
                trav->next=a;
            }
            return temp->next;
        }
    };