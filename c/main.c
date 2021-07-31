#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    char *s[] = {"III","IV","IX","LVIII","MCMXCIV"};
    for(int i=0;i<5;i++){
        int num = romanToInt(s[i]);
        printf("%d\n",num);
    }

}
