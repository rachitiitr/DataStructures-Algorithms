
//  4. link : [ https://leetcode.com/problems/merge-k-sorted-lists ]


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
    
 
ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
             return NULL;
         if(l1==NULL)
               return l2;
          if(l2==NULL)
            return l1;
    
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        ListNode* tail = new ListNode(0);
        ListNode* head = tail;
        
        
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                ListNode* newNode = new ListNode(temp1->val);
                tail->next = newNode;
                tail = newNode;
                temp1 = temp1->next;
            }else{
                ListNode* newNode = new ListNode(temp2->val);
                tail->next = newNode;
                tail = newNode;
                temp2 = temp2->next;
            }
        }
        
        while(temp1){
            ListNode* newNode = new ListNode(temp1->val);
            tail->next = newNode;
            tail = newNode;
            temp1 = temp1->next;
        }
        
        while(temp2){
            ListNode* newNode = new ListNode(temp2->val);
            tail->next = newNode;
            tail = newNode;
            temp2 = temp2->next;
        }
       
        return (head->next);   
}
    
    ListNode* helper(vector<ListNode*>& lists, int l, int r){
        if(l == r)
            return lists[l];
        
        int mid = l+(r-l)/2;
        
       ListNode* h1 = helper(lists,l,mid);
       ListNode* h2 = helper(lists,mid+1,r);
       
       return merge(h1,h2);
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
       
        int l = 0;
        int r = lists.size()-1;
        
        return helper(lists,l,r);
    }
};