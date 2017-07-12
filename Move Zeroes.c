/* 
Given an array nums, write a function to move all 0's to 
the end of it while maintaining the relative order of the 
non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling 
your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/ 

//mine 
void moveZeroes(int* nums, int numsSize) {
    int i, j;
    for (i = 1; i < numsSize; i++) {
        int flag = 0;
        for (j = 0; j < numsSize - i; j++) {
            if (nums[j] == 0) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}


//others better 
void moveZeroes(int* nums, int numsSize) {
    int     *p = nums;
    for(int i=0; i < numsSize; i++)
        if(nums[i])
            *p++ = nums[i];
    for(int i = &nums[numsSize] - p;i--;)
        *p++ = 0;
}
