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
   
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode* fast = head, *slow = head;
        ListNode* prev = head, *temp = head;
        int count = 1;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast->next != NULL){
                count += 2;
                fast = fast->next;
            } else{
                count += 1;
            }
        }
        if(count == n)
            return head ->next;
        //cout << count << endl;
        while(count - n > 0){
            prev = temp;
            temp = temp->next;
            count -- ;
        }
        prev->next = temp->next;
        //free(temp);
        return head;
    }
};