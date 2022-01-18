/*
JZ6 从尾到头打印链表
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> rst;
        if (NULL == head)
            return rst;
        stack<ListNode*> nodes;
        ListNode* phead = head;
        while (NULL != phead)
        {
            nodes.push(phead);
            phead = phead->next;
        }
        while (!nodes.empty())
        {
            phead = nodes.top();
            rst.push_back(phead->val);
            nodes.pop();
        }
        return rst;
    }
};