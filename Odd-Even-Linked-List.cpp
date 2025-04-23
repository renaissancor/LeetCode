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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* o_prev = head; // 1st index 
        if(o_prev == nullptr) return head; 
        ListNode* e_prev = head->next; // 2nd index 
        if(e_prev == nullptr) return head; 
        ListNode* e_head = e_prev; // Mark 2nd index, for last  

        ListNode* iter = e_prev->next; // 3rd index, odd, can be nullptr 

        while(iter != nullptr)
        {
            o_prev->next = iter; // 1st index node-> next = 3rd index node ptr 
            o_prev = iter;  // o_prev is now 3rd node from 1st index 

            if(iter->next == nullptr) break; // Check before move 
            iter = iter->next; // Move from 3rd to 4th 

            e_prev->next = iter; // 2nd index next 4th index 
            e_prev = iter;  // Now e_prev is 4th node 

            iter = iter->next; 
        }

        o_prev->next = e_head; 
        e_prev->next = nullptr; 

        return head; 
    }
};