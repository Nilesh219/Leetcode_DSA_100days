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
// Function to reverse a linked list (used in one approach)
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true; // Empty list or single element is a palindrome
        }

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list (omit middle element for odd length)
        slow = reverseList(slow);

        // Compare elements from beginning and reversed second half
        while (slow) {
            if (slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }

        return true;
    }

};