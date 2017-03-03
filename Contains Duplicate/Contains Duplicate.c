//Given an array of integers, find if the array contains any duplicates. 
//Your function should return true if any value appears at least twice in the array
//And it should return false if every element is distinct. 
//

int CMP(const void *a,const void *b){
    return *(int *)a - *(int *)b;
    
}
bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), CMP);
    int i;
    for(i = 0; i < numsSize-1; i++){
        if(*(nums + i) == *(nums + i + 1))
            return true;
    }
    return false;
}
