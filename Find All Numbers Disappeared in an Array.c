/* 
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/ 

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *result = (int *) malloc(sizeof(int) * (numsSize + 1));
    memset(result, 0, sizeof(int) * numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        result[nums[i]] ++;
    }
    
    result[0] = 1;
    for (int i = 1; i <= numsSize; i++) {
        if (result[i] == 0) {
            result[result[0]] = i;
            result[0]++;
        }
    }
    *returnSize = result[0] - 1;
    return &result[1];
} 
