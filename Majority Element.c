/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
int majorityElement(int* nums, int numsSize) {
    int cnt = 0, res;
    for(int i = 0; i < numsSize; i ++)
    {
        if(cnt == 0)
            res = nums[i];
        if(res == nums[i])
            cnt++;
        else
            cnt--;
    }
    return res;
}
