
///You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
//the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and 
//it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, 
//determine the maximum amount of money you can rob tonight without alerting the police.
//
//

int rob(int* nums, int numsSize) {
    if(!numsSize)
        return 0;
    if(numsSize == 1){
        return *nums;
    }
    int p[numsSize];
    p[0] = *nums;
    p[1] = *nums > *(nums+1) ? *nums : *(nums+1);
    int i;
    for(i = 2;i < numsSize;i++){
        p[i] = p[i-2]+*(nums+i) > p[i-1] ? p[i-2]+*(nums+i) : p[i-1];
    }
    return p[numsSize-1];
}
