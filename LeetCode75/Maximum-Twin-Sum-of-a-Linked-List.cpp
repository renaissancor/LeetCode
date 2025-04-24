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
 #include <stack> 

class Solution {
public:
    int pairSum(ListNode* head) {

        unsigned int cnt = 0; 
        int ans = INT_MIN; 
        
        ListNode *iter = nullptr; 

        iter = head;  
        while(iter)
        {
            ++cnt; // count total number 
            iter = iter->next; 
        }
        
        iter = head; // Reset iter to head node, must not be nullptr based on input 
        ListNode *prev = nullptr; 
        ListNode *post = head->next; 

        for(unsigned int i=0; i<cnt/2; ++i)
        {
            // if(post == nullptr) break; // Unnecessary? 

            iter->next = prev; 
            prev = iter; 
            iter = post; 
            post = post->next; 
        } 

        // prev and iter became two pointers, of two lists with exact size cnt/2 

        for(unsigned int i=0; i<cnt/2; ++i)
        {
            int tmp = prev->val + iter->val; 
            ans = ans > tmp ? ans : tmp; 
            prev = prev->next; 
            iter = iter->next; 
        }

        return ans;        
    }
};