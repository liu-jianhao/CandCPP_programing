/* 
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. Please 
note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you 
may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/ 


// mine 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i, j;
    int *result = (int *)malloc(sizeof(int) * 2);
    
    for (i = 0; i < numbersSize - 1; i++) {
        for(j = i + 1; j < numbersSize; j++) {
            if ((numbers[i] + numbers[j]) == target) {
                *returnSize = 2;
                result[0] = i+1;
                result[1] = j+1;
                return result;
            }
        }
    }
    *returnSize = 0;
    return result;
}

// others better 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int find(int* nums, int numsSize, int target){
	int index;
	if (numsSize > 1){
		if (nums[numsSize / 2] > target){
			index = find(nums, numsSize / 2, target);
			if (index == -1)
				return -1;
			return index;
		}
		else if (nums[numsSize / 2] < target){
			index = find(nums + numsSize / 2 + 1, numsSize - numsSize / 2 - 1, target);
			if (index == -1)
				return -1;
			return index + numsSize / 2 + 1;
		}
		else
			return numsSize/2;
	}
	else if(numsSize == 1){
		if (nums[numsSize / 2] == target)
			return numsSize / 2;
		else
			return -1;
	}
	return -1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	int i;
	int desire;
	int index;
	int *pair;
	pair = (int *)malloc(sizeof(int)* 3);
	for (i = 0; i < numbersSize; i++){
		desire = target - numbers[i];
		index = find(numbers, i, desire);
		if (index != -1){
			pair[0] = index+1;
			pair[1] = i+1;
			break;
		}
	}
    *returnSize = 2;
	return pair;
}
