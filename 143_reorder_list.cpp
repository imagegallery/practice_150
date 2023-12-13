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
    
    ListNode* reverse(ListNode* l){
        if(l == NULL)
            return NULL;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while(l != NULL){
            nextNode = (l)->next;
            l->next = prev;
            prev = l;
            l = nextNode; 
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return;
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        ListNode* l2 = reverse(slow->next);
        ListNode* temp = head;
        slow->next = NULL;
        
        //rearrange pointers
        ListNode* NextNode = NULL;
        ListNode* L2Next = NULL;
        while(l2 && temp){
            NextNode = temp ->next;
            temp->next = l2;
            L2Next = l2->next;
            l2->next = NextNode;
            l2 = L2Next;
            temp = temp->next->next;
        }
        
        if(temp != NULL){
            temp->next = NULL;
        }
        
        return;    
    }
};