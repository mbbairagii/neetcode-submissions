class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int x:nums){
            st.insert(x);
        }

        int ans=0;
        for(int x:st){
            if(st.count(x-1)==0){
                int curr=x;
                int len=1;
                while(st.count(curr+1)){
                    curr++;
                    len++;
                }

                ans=max(ans, len);
            }
        }

        return ans;
    }
};
