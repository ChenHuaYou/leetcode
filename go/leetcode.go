package main
import "fmt"
import "strings"

func kmp_table(pattern string) []int{
    var pos int = 1;
    var cnd int = 0;
    var patternSize int = strings.Count(pattern,"")-1;
    var T []int = make([]int, patternSize);
    T[0] = -1;
    for(pos < patternSize){
        if(pattern[cnd]==pattern[pos]){
            T[pos] = T[cnd];
        }else{
            T[pos] = cnd;
            for(cnd>=0 && pattern[pos] != pattern[cnd]){
                cnd = T[cnd];
            }
        }
        pos ++;
        cnd ++;
    }
    return T;
}
func strStr(haystack string, needle string) int {
    if(strings.Count(needle,"")-1==0) {
        return 0;
    }
    var j int = 0;
    var k int = 0;
    var m int = -1;
    var T []int = kmp_table(needle);
    var haystackSize int = strings.Count(haystack,"")-1;
    var needleSize int = strings.Count(needle,"")-1;
    for(j<haystackSize){
        if(needle[k]==haystack[j]){
            j++;
            k++;
            if(k==needleSize){
                m = j-k;
                break;
            }
        }else{
            k = T[k];
            if(k<0){
                j++;
                k++;
            }
        }
    }
    return m;
}

func main() {
    var haystack string = "ABC ABCDAB ABCDABCDABDE";
    var needle string = "ABCDABD";
    var index int = strStr(haystack, needle);

    fmt.Printf("index is : %d\n",index);
}
