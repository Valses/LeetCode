//
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//(you may want to display this pattern in a fixed font for better legibility) 
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//          string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
//
//
//
//
//
//找规律啊找规律
//
//
char* convert(char* s, int numRows) {
    if(numRows == 1)
        return s;
    int length = strlen(s);
    int i,j;
    int arr[numRows][2];                  //Z字型每行两字母之间跨越距离数组，共numRows行
    arr[0][0] = arr[numRows-1][1] = (numRows-1)*2;
    arr[0][1] = arr[numRows-1][0] = 0;
    for(i = 1; i < numRows-1; i++){
        arr[i][0] = arr[i-1][0] - 2;
        arr[i][1] = arr[i-1][1] + 2;
    }
    char *p = (char *)malloc((length+1) * sizeof(char));
    char *q = p;
    for(i = 0;i < numRows; i++){
        j = i;
        *(p++) = *(s+i);
        while(j < length){
            j = j + arr[i][0];
            if(j < length && arr[i][0]){     //j未超过字符串总长 && 不是首行
                *(p++) = *(s+j);
            }
            j = j + arr[i][1];
            if(j < length && arr[i][1]){     //j未超过字符串总长 && 不是尾行
                *(p++) = *(s+j);
            }
        }
    }
    *(p) = '\0';
    return q;
}
