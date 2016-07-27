//Write a program to check whether a given number is an ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//Note that 1 is typically treated as an ugly number.
//
//
//
//
//
//
bool isUgly(int num) {
    if (num <1) return false;
    if (num >= 1&&num <= 6){
        return true;
    }
    while(!(num%5)){
        num = num/5;
    }
    while(!(num%3)){
        num = num/3;
    }
    if(!(num&(num-1)) || num == 1)
        return true;
    else
        return false;
    
}
