
//  3. link : [ https://leetcode.com/problems/merge-two-sorted-lists ]

#include<bits/stdc++.h>
using namespace std;

// node class
class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int data){
        this->val = data;
        next = NULL;
    }

};


 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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
       
        return head->next;   
}

ListNode* takeInput(){
    ListNode* head = NULL;
    ListNode* tail = NULL;
    
    int data;
    while(cin >> data && data != -1){
        ListNode* node = new ListNode(data);
        if(head == NULL){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void print(ListNode* head){
    if(head == NULL)
     return;

     while(head){
         cout << head->val << " ";
         head = head->next;
     }
     cout << endl;
}



/*
1
1
1 3 4 5 6 -1
-2 -4 3 7 9  -1 

-2 -4 1 3 3 4 5 6 7 9 

*/

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

        int test;
        cin >> test;

        while(test--){

           ListNode* l1 = takeInput();
           ListNode* l2 = takeInput();

           ListNode* head = mergeTwoLists(l1, l2);
           print(head);


        }


    return 0;    
}