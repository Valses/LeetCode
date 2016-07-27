//Given two strings s and t, write a function to determine if t is an anagram of s.
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//
//
//sorting way
//
int CMP(const void *a, const void *b){
    return *(char *)a - *(char*)b;
}
bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t))
        return false;
    qsort(s,strlen(s),sizeof(char),CMP);
    qsort(t,strlen(t),sizeof(char),CMP);
    int i;
    for(i=0;i<strlen(s);i++){
        if(*(s+i) != *(t+i))
            return false;
    }
    return true;
}
