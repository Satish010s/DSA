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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next|| !head->next->next) return {-1,-1};
        vector<int>arr;
        long long i=1;
        ListNode*temp=head->next;
        ListNode *prev=head;
        while(temp->next!=nullptr){
                if((temp->val)>prev->val && (temp->val)>(temp->next->val)){
                    arr.push_back(i);
                }
                if((temp->val)<prev->val && (temp->val)<(temp->next->val)){
                    arr.push_back(i);
                }
                prev=temp;
                temp=temp->next;
                i++;
        }
        if (arr.size() < 2) {
            return {-1, -1};
        }
        int minD=INT_MAX;
        for(int i=1;i<arr.size();i++){
            minD=min(minD,arr[i]-arr[i-1]);
        }
        int maxD=arr[arr.size()-1]-arr[0];
        return {minD,maxD};
    }
};