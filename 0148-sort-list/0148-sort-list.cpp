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
ListNode*mergesortedlist(ListNode*l1,ListNode*l2){
      ListNode*dummy = new ListNode(-1);
      ListNode*temp = dummy;
      while(l1!=nullptr && l2!=nullptr){
        if(l1->val<=l2->val){
            temp->next=l1;
            
            l1= l1->next;
        }
        else{
            temp->next=l2;
            l2= l2->next;
        }
        temp = temp->next;
      }
      if(l1!=nullptr){
        temp->next=l1;
        l1=l1->next;
      }
      if(l2!=nullptr){
        temp->next=l2;
        l2= l2->next;
      }
      return dummy->next;
}
    ListNode*findmid(ListNode*head){
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode*slow = head;
        ListNode*fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return head;
      ListNode*middle = findmid(head);
      ListNode*left = head;
      ListNode*right = middle->next;
      middle->next=nullptr;
      ListNode*l1 = sortList(left);
      ListNode*l2 = sortList(right);
      return mergesortedlist(l1,l2);
        
    }
};