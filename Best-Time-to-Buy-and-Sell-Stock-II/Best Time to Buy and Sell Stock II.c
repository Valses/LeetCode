//
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. 
//You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
//However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
//
//
int maxProfit(int* prices, int pricesSize) {
    if(pricesSize < 2)
        return 0;
    int i = 0,flag = 0,add = 0;
    int p = 0;
    while(*(prices + i) >= *(prices + i+1) && i+1 < pricesSize)
        i++;                            //持续走低，则不买入
    if(i+1 >= pricesSize)
        return 0;
    p -= *(prices + (i++));             //买入
    for(i;i<pricesSize-1;i++){
        if(*(prices + i) > *(prices + i+1)){           //今日价高于明日
            p = p + *(prices + i) - *(prices + i+1);   //今日卖出明日买进
            add = i + 1;                               //记录最近一次买入日期
        }
    }
    if(*(prices + i) >= *(prices + i-1))               //最后一日价高于前一日，则卖出
        p += *(prices + i);
    else
        p += *(prices + add);                         //否则，将最近一次买入撤销
    return p;
}
