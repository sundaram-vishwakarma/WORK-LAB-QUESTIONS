class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0); // Dummy node
        ListNode* current = ans;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return ans->next; // Return the head of the merged list
    }
};

