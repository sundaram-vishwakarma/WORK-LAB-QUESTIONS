class Solution {
public:
    int getLength(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = getLength(head);
        k = k % len;
        if (k == 0) return head;

        // Find the new tail (at position len - k - 1)
        ListNode* cutNode = head;
        for (int i = 0; i < len - k - 1; ++i) {
            cutNode = cutNode->next;
        }

        // New head is the next node
        ListNode* newHead = cutNode->next;
        cutNode->next = nullptr;

        // Go to the end of the new list and connect it to the old head
        ListNode* tail = newHead;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }
};

