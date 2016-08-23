//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction 
//(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//
int maxProfit(int* prices, int pricesSize) {
    if(pricesSize < 2)
        return 0;
    if(pricesSize == 2)
        return *(prices+1)-*prices > 0 ? *(prices+1)-*prices : 0;
    int p[pricesSize],m[pricesSize];
    p[0] = 0;
    p[1] = *(prices+1)-*prices > 0 ? *(prices+1)-*prices : 0;
    m[0] = *prices;
    m[1] = m[0] < *(prices+1) ? m[0] : *(prices+1);
    int i;
    for(i = 2;i < pricesSize;i++){
        p[i] = p[i-1] > *(prices+i)-m[i-1] ? p[i-1] : *(prices+i)-m[i-1];
        m[i] = m[i-1] < *(prices+i) ? m[i-1] : *(prices+i);
    }
    return p[pricesSize-1];
}
