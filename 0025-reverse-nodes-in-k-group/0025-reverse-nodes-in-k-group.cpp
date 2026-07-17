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
  ListNode* reversell(ListNode*head){
    ListNode*temp= head;
    ListNode*prev= nullptr;
    while(temp!=nullptr){
        ListNode*front = temp->next;
        temp->next= prev;
        prev=temp;
        temp= front;
    }
    return prev;
  }
   ListNode*getkth(ListNode*temp,int k){
    k-=1;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
   }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp = head;
        ListNode*prev = nullptr;
        while(temp!=nullptr){
            ListNode*kth= getkth(temp,k);
            // first check like k= 2 and linkled list left is 1
            if(kth==nullptr){
                if(prev){
                    prev->next=temp;
                }
                break;
            }
            ListNode*nextnode = kth->next;
            kth->next=nullptr; // to divide the ll in k ll
            reversell(temp);
            if(temp==head){
                head= kth;
            }
            else{
                prev->next=kth;
            }
            prev= temp;
            temp=nextnode;
        }
        return head;
        
    }
};