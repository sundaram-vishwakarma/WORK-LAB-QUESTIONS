class Solution {
private:
    // Helper function to reverse a linked list
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find the middle of the linked list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* revSecHalf = reverseLL(slow);

        // Compare the first half and the reversed second half
        while (revSecHalf != nullptr) {
            if (revSecHalf->val != head->val) {
                return false;
            }
            revSecHalf = revSecHalf->next;
            head = head->next;
        }

        return true;
    }
};
