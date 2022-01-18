/*
JZ18 删除链表的节点
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == NULL)
            return head;
        ListNode* pHead = head;
        ListNode* pNext = pHead->next;
        if (pHead->val == val)
            head = pNext;
        while (NULL != pNext)
        {
            if (pNext->val == val)
            {
                pHead->next = pNext->next;
                break;
            }
            else
            {
                pHead = pHead->next;
                pNext = pNext->next;
            }
        }
        return head;
    }
};