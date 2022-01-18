/*
JZ52 两个链表的第一个公共结点
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
    int ListLength(ListNode* pHead)
    {
        int length = 0;
        ListNode* pNode = pHead;
        while (pNode)
        {
            ++length;
            pNode = pNode->next;
        }
        return length;
    }

    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = ListLength(pHead1);
        int len2 = ListLength(pHead2);
        int lenDiff = len1 - len2;
        ListNode* pLong = pHead1;
        ListNode* pShort = pHead2;
        if (len1 < len2)
        {
            lenDiff  = len2 - len1;
            pLong = pHead2;
            pShort = pHead1;
        }
        while (lenDiff--)
            pLong = pLong->next;
        while (pLong && pShort && pLong != pShort)
        {
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return pLong;
    }
};
