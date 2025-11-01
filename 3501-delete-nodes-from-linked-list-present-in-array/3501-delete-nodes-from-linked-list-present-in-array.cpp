class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        // Dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        while (current->next != nullptr) {
            if (valuesToRemove.count(current->next->val)) {
                // Just unlink, don't delete
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return dummy.next;
    }
};
