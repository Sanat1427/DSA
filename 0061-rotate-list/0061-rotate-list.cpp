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
ListNode*findNthnode(ListNode*head,int k){
    int cnt =1;
    while(head!=nullptr){
        if(cnt==k)return head;
        cnt++;
        head= head->next;
    }
    return head;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)
        return head;
        int len  = 1;
        ListNode*temp = head;
        while(temp != nullptr && temp->next!=nullptr){
            len++;
            temp= temp->next;
        }
        if(k%len==0)return head;;
        k= k%len;
        temp->next=head;
        ListNode*newlast= findNthnode(head,len-k);
        head = newlast->next;
        newlast->next= nullptr;
        return head;
    }
};