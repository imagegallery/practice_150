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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        if(list1-> val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    /*
    //one sol without using recursion
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while(list1 != NULL and list2 != NULL){
            if(list1->val <= list2->val){
                result->next = new ListNode(list1->val);
                list1 = list1->next;
                result = result->next;
            }else{
                result->next = new ListNode(list2->val);
                list2 = list2->next;
                result = result->next;
            }
        }
        if(list1 != NULL){
            result->next = list1;
            //list1 = list1->next;
            //result = result->next;
        } 
        if(list2 != NULL){
            result->next = list2;//new ListNode(list2->val);
            //list2 = list2->next;
            //result = result->next;
        }   
        return temp->next;
    }
    */
};