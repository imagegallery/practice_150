/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
        if(a->val <= b->val){
            a->next = merge(a->next, b);
            return a;
        }else{
            b->next = merge(a, b->next);
            return b;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        // time complexity -> O(log(n).k)
        while(n > 1){
            for(int i = 0; i < n/2; i++){
                lists[i] = merge(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists[0];
        // time complexity -> O(n.k)
        // ListNode* res = lists[0];
        // for(int i = 1; i < n; i++){
        //     res = merge(res, lists[i]);
        // }
        //return res;
    }
};