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
        ListNode* oddEvenList(ListNode* head) {
            ListNode*odd=new ListNode(-1);
            ListNode*even=new ListNode(-2);
            ListNode*ans1=odd;
            ListNode*ans2=even;
            ListNode*temp=head;
            int count=0;
            while(temp){
                if(count%2==0){
                    odd->next=temp;
                    odd=odd->next;
                    temp=temp->next;
                }
                else{
                    even->next=temp;
                    even=even->next;
                    temp=temp->next;
                }
                count++;
            }
            odd->next=ans2->next;
            even->next=nullptr;
            return ans1->next;
        }
    };