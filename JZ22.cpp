/*
JZ22 链表中倒数最后k个结点
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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (k <= 0 || pHead == NULL)
            return NULL;
        ListNode* pNode = pHead;
        while (k && pNode)
        {
            --k;
            pNode = pNode->next;
        }
        
        if (0 != k)
            return NULL;
        while (pNode)
        {
            pHead = pHead->next;
            pNode = pNode->next;
        }
        return pHead;
    }
};
