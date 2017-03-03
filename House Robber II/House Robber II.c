//Note: This is an extension of House Robber.

//After robbing those houses on that street, 
//the thief has found himself a new place for his thievery so that he will not get too much attention. 
//This time, all houses at this place are arranged in a circle. 
//That means the first house is the neighbor of the last one. Meanwhile, 
//the security system for these houses remain the same as for those in the previous street.

//Given a list of non-negative integers representing the amount of money of each house, 
//determine the maximum amount of money you can rob tonight without alerting the police.

int rob(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return *nums;
    
    int p[numsSize];
    p[0] = *nums;
    p[1] = *(nums+1) > *nums ? *(nums+1) : *nums;    
    if(numsSize == 2)
        return p[1];
    p[2] = p[1] > *(nums+2) ? p[1] : *(nums+2);
    if(numsSize == 3)
        return p[2];
    int q[numsSize],w[numsSize];
    q[0] = 0;
    q[1] = *(nums+1);
    q[2] = *(nums+1) > *(nums+2) ? *(nums+1) : *(nums+2);
    w[0] = p[0];
    w[1] = p[1];
    w[2] = *(nums+2)+*nums > *(nums+1) ? *(nums+2)+*nums : *(nums+1);
    int i;
    for(i = 3;i < numsSize;i++){
        p[i] = w[i-1] > q[i-2]+*(nums+i) ? w[i-1] : q[i-2]+*(nums+i);
        w[i] = w[i-2]+*(nums+i) > w[i-1] ? w[i-2]+*(nums+i) : w[i-1];
        q[i] = q[i-2]+*(nums+i) > q[i-1] ? q[i-2]+*(nums+i) : q[i-1];
    }
    return p[numsSize-1];
    
}
