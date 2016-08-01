//
//Reverse bits of a given 32 bits unsigned integer.
//
//
//
//Solution:
//Compare the bits from two side,change when unequal.
//
uint32_t reverseBits(uint32_t n) {
    unsigned int i = 0x1;                //mask1
    unsigned int j = 0x80000000;         //mask2
    int k = 31;
    while(i < j){
        if((n&i) != ((n&j)>>k)){
            n = n^i^j;
        }
        k -= 2;
        i = i<<1;
        j = j>>1;
    }
    return n;
}
