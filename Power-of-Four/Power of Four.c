//
//
//
//
bool isPowerOfFour(int num) {
    if(!(num & (num-1))){       //power of two first
        if(num & 0x55555555)
            return true;
    }
    return false;
}
