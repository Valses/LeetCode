//
//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. 
//If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
//You are responsible to gather all the input requirements up front. 
//
//
int myAtoi(char* str) {
    char *p = str;
    int flag = 0;
    long int num = 0;
    while(*p == ' '){
        p++;
    }
    if(*p == '-'){
        flag = 1;
        p++;
    }
    else if(*p == '+')
        p++;
    while(*p >= '0' && *p <= '9'){
        num = num * 10 + *p - '0';
        if(num > 0x7fffffff){
            if(flag)
                return 0x80000000;
            else
                return 0x7fffffff;
        }
        p++;
    }
    if(flag)
        num *= -1;
    return num;
}
