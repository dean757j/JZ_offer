/*
JZ76 删除链表中重复的结点
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead)
            return pHead;
        ListNode* vHead = new ListNode(-1);
        vHead->next = pHead;
        ListNode* preNode = vHead;
        ListNode* curNode = pHead;
        while (curNode)
        {
            if (curNode->next && curNode->val == curNode->next->val)
            {
                curNode = curNode->next;
                while (curNode->next && curNode->val == curNode->next->val)
                    curNode = curNode->next;
                curNode = curNode->next;
                preNode->next = curNode;
            }
            else
            {
                preNode = curNode;
                curNode = curNode->next;
            }
        }
        return vHead->next;
    }
};