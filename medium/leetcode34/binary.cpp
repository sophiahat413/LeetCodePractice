class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2,-1);
        int low = 0, high = nums.size()-1,i;
        int mid = (nums.size()-1) >> 1;
        while(high >= low){
            mid = low + (high - low) / 2;
            //cout<<"mid: "<<mid<<" ";
            if(target > nums[mid])
                low = mid+1;
            else if(target < nums[mid])
                high = mid-1;
            else{
                //target on right ans left of mid
                if(mid>0 && nums[mid-1] == target && mid<nums.size()-1 && nums[mid+1] == target){
                    int left = mid-1, right = mid+1;
                    while(nums[left] == target && left >= 0)
                        left--;
                    while(nums[right] == target && right < nums.size())
                        right++;
                    ans[0] = left+1;
                    ans[1] = right-1;
                    return ans;
                }
                //target only on right of mid
                else if(mid<nums.size()-1 && nums[mid+1] == target){
                    //cout<<"mid: "<<mid<<endl;
                    int right = mid+1;
                    while(nums[right] == target && right < nums.size())
                        right++;
                    ans[0] = mid;
                    ans[1] = right-1;
                    return ans;
                }
                else if(mid>0 && nums[mid-1] == target){
                    int left = mid - 1;
                    while(nums[left] == target && left >= 0)
                        left--;
                    ans[0] = left+1;
                    ans[1] = mid;
                    return ans;
                }
                else{
                    ans[0] = mid;
                    ans[1] = mid;
                    return ans;
                }
                /*i = mid;
                while(nums[i] == target && i >= 0)
                    i--;
                ans[0] = i+1;
                i = mid;
                while(nums[i] == target && i < nums.size())
                    i++;
                ans[1] = i-1;
                break;*/
            }
        }
        return ans;
    }
};
