#include <memory>

namespace Q19 {
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1 {
 public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);  // 虚拟头节点
        dummy->next = head;

        // 删除倒数第 n 个节点, 就是要找到第n + 1个节点
        ListNode* p = findFromEnd(dummy, n + 1);
        // 删除倒数第 n 个节点
        p->next = p->next->next;
        return dummy->next;
    }

 private:
    inline ListNode* findFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        // p1 先走 k 步
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }

        ListNode* p2 = head;
        // p1 和 p2 同时走 n - k 步
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        // p2 现在指向了 n - k 个节点
        return p2;
    }
};

class Solution2 {
 public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::unique_ptr<ListNode> dummy(new ListNode(-1));  // 虚拟头节点
        dummy->next = head;

        // 删除倒数第 n 个节点, 就是要找到第n + 1个节点
        ListNode* p = findFromEnd(dummy, n + 1);
        // 删除倒数第 n 个节点
        p->next = p->next->next;
        return dummy->next;
    }

 private:
    inline ListNode* findFromEnd(std::unique_ptr<ListNode>& head, int k) {
        ListNode* p1 = head.get();
        // p1 先走 k 步
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }

        ListNode* p2 = head.get();
        // p1 和 p2 同时走 n - k 步
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        // p2 现在指向了 n - k 个节点
        return p2;
    }
};

}  // namespace Q19