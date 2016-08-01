
//You are climbing a stair case. It takes n steps to reach to the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
//
//
//
//Solution:
//for i > 2,when climbing i steps,the distinct ways can be discribed as:
//1.climbing i-1 steps and 1 step;
//2.climbing i-2 steps and 2 steps;
//Therefore we have : way[i] = way[i-1] + way[i-2].
//
int climbStairs(int n) {
    int way[n+1];
    way[1] = 1;
    way[2] = 2;
    int i;
    for(i = 3;i <= n;i++)
        way[i] = way[i-1] + way[i-2];
    return way[n];
}
