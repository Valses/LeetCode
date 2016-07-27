//
//
//
//依次按位求和
int getSum(int a, int b) {
    int c = 0,sum = 0;
    int at,bt,s,i;
    int mask = 0x1;
    for(i=0;i<32;i++){
        at = (a&(mask<<i))>>i;
        bt = (b&(mask<<i))>>i;
        s = at^bt^c;
        c = at&bt | at&c | bt&c;
        sum = sum|(s<<i);
    }
    return sum;
}
