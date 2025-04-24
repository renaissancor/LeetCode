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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head; 
        ListNode* prev = nullptr; 
        ListNode* iter = head; 
        ListNode* post = head->next; 

        while(post)
        {
            iter->next = prev; 
            prev = iter; 
            iter = post; 
            post = post->next; 
        }

        iter->next = prev; 

        return iter;         
    }
};