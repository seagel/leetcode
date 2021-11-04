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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minHeap;
        for(int i=0;i<lists.size();i++){
            ListNode* curr = lists[i]; 
            if(curr == NULL)
                continue;
            minHeap.push({curr->val,curr});
        }
        
        ListNode* root = NULL;
        ListNode* point = root;
        
        while(!minHeap.empty()){
            pair<int,ListNode*> curr = minHeap.top();
            minHeap.pop();
            
            if(root == NULL){
                root = curr.second;
                point = root;
            }else{
                point->next = curr.second;
                point = point->next;
            }
            if(curr.second->next != NULL){
                minHeap.push({curr.second->next->val,curr.second->next});
                curr.second->next = NULL;
            }
            
        }
        return root;
        
    }
};
