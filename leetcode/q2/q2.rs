struct Solution;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut result = None;
        let mut tail = &mut result;
        let mut tup = (l1, l2, 0, 0); // l1, l2, sum, carry

        loop {
            tup = match tup {
                (None, None, _, 0) => break, // l1和l2都走完了, 而且没有进位, 结束
                (None, None, _, carry) => (None, None, carry, 0), // l1和l2都走完了, 但是有进位, 继续
                (Some(l), None, _, carry) | (None, Some(l), _, carry) if l.val + carry >= 10 => {
                    // 其中一个走到了尾部, 取节点值+进位, 但是进位大于10
                    (l.next, None, (l.val + carry) % 10, (l.val + carry) / 10)
                }
                (Some(l), None, _, carry) | (None, Some(l), _, carry) => {
                    (l.next, None, l.val + carry, 0)
                }
                (Some(l1), Some(l2), _, carry) if l1.val + l2.val + carry >= 10 => {
                    // l1和l2都没有走完, 取节点值+进位, 但是进位大于10
                    (l1.next, l2.next, (l1.val + l2.val + carry) % 10, (l1.val + l2.val + carry) / 10)
                }
                (Some(l1), Some(l2), _, carry) => {
                    // l1和l2都没有走完, 取节点值+进位, 但是进位小于10
                    (l1.next, l2.next, l1.val + l2.val + carry, 0)
                }
            };

            *tail = Some(Box::new(ListNode::new(tup.2)));
            tail = &mut tail.as_mut().unwrap().next;
        }
        result
    }
}