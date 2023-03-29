struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

namespace Q2 {
class Solution {
 public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        int carry = 0;
        while (p1 != nullptr || p2 != nullptr || carry > 0) {
            int val = carry;
            if (p1 != nullptr) {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                val += p2->val;
                p2 = p2->next;
            }

            carry = val / 10;
            val = val % 10;

            p->next = new ListNode(val);
            p = p->next;
        }

        return dummy->next;
    }
};
}  // namespace Q2