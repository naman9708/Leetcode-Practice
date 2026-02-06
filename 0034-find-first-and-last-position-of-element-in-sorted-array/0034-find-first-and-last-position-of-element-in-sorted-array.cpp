class Solution {
public:
int firstocc(vector<int>& nums,int key){
    int s=0;
    int sie=nums.size();
    int e=sie-1;
    int ans=-1;
     int mid=s+(e-s)/2;
    while(s<=e){
        if(nums[mid] == key){
            ans=mid;
            e=mid-1;
        }
        else if(key>nums[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    
}
int lastocc(vector<int>& nums,int key){
    int s=0;
    int sie=nums.size();
    int e=sie-1;
    int ans=-1;
     int mid=s+(e-s)/2;
    while(s<=e){
        if(nums[mid] == key){
            ans=mid;
            s=mid+1;
        }
        else if(key>nums[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
       mid=s+(e-s)/2;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstocc(nums,target);
       int second = lastocc(nums,target);
        return {first,second};
        
    }
};