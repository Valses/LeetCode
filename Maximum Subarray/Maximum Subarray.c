//Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 
//



int max(int x, int y){
    return x > y ? x : y;
}

int maxSubArray(int* nums, int numsSize) {
    if(!numsSize){
        return 0;
    }
    if(numsSize == 1){
        return nums[0];
    }
    int i, maxSum;
    int sum = nums[numsSize - 1]；
    maxSum = nums[numsSize - 1];
    for(i = numsSize - 2; i >= 0; i--){
        sum = max(nums[i], nums[i] + sum); //从i点开始的最大子串和
        maxSum = max(maxSum, sum); //当前最大子串和
    }
    return maxSum;
}
