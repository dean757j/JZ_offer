/*
JZ35 复杂链表的复制
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while (pNode)
        {
            RandomListNode* pClone = new RandomListNode(pNode->label);
            pClone->next = pNode->next;
            pClone->random = nullptr;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }

    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while (pNode)
        {
            RandomListNode* pClone = pNode->next;
            if (pNode->random)
                pClone->random = pNode->random->next;
            pNode = pClone->next;
        }
    }

    RandomListNode* ReconnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = pHead->next;
        RandomListNode* pClone = pNode->next;
        while (pNode)
        {
            pNode->next = pNode->next->next;
            if (pClone->next)
                pClone->next = pClone->next->next;
            pNode = pNode->next;
            pClone = pClone->next;
        }
        return pCloneHead;
    }

    RandomListNode* Clone(RandomListNode* pHead) {
        while (!pHead)
            return pHead;
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }
};