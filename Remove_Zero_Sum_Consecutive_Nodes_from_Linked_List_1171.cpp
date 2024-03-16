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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> prefixSumMap;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        prefixSumMap[0] = dummy;
        int prefixSum = 0;

        while (head != nullptr) {
            prefixSum += head->val;
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                ListNode* prev = prefixSumMap[prefixSum];
                ListNode* start = prev;
                int sum = prefixSum;
                while (start != head) {
                    start = start->next;
                    sum += start->val;
                    if (start != head) {
                        prefixSumMap.erase(sum);
                    }
                }
                prev->next = head->next;
            } else {
                prefixSumMap[prefixSum] = head;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
