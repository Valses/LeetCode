//Given two arrays, write a function to compute their intersection.
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//Note:
//Each element in the result must be unique.
//The result can be in any order.
//
//
//
//
// Return an array of size *returnSize.
// Note: The returned array must be malloced, assume caller calls free().
//
int CMP_int_down(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1,nums1Size,sizeof(int),CMP_int_down);
    qsort(nums2,nums2Size,sizeof(int),CMP_int_down);
    int i = 0,j = 0;
    int flag = 0;
    int *renum = NULL;
    while (i != nums1Size && j != nums2Size){
        if(*(nums1+i) < *(nums2+j)){
            i++;
        }
        else if(*(nums1+i) == *(nums2+j)){
            if(flag == 0)
                renum = (int *)malloc(sizeof(int));
            else
                renum = (int *)realloc(renum,(flag+1)*sizeof(int));
            *(renum+flag) = *(nums1+i);
            flag++;
            do{
                i++;
            }while(*(nums1+i-1) == *(nums1+i));
            j++;
        }
        else{
            j++;
        }

    }
    *returnSize = flag;
    return renum;
}
