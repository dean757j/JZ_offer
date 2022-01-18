/*
JZ24 反转链表
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (NULL == pHead)
            return NULL;
        if (NULL == pHead->next)
            return pHead;
        ListNode* pNext = pHead->next;
        pHead->next = NULL;
        while (pNext != NULL)
        {
            ListNode* tmp = pNext->next;
            pNext->next = pHead;
            pHead = pNext;
            pNext = tmp;
        }
        return pHead;
    }
};