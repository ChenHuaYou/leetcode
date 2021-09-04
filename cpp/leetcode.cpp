#include "leetcode.h"


using namespace std;


/**
* 给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 
*/
bool Solution::checkSubarraySum(vector<int>& nums, int k) {    
    int n = nums.size();  
    int v = accumulate(nums.begin(),nums.end(),0);    
    for(int i=0;i<n-1;i++){       
        int w = v;
        for (int j=n-1;j>i;j--){     
            if(nums[i]!=0&&w<k) break;        
            if (w % k==0){  
                return true;    
            }    
            w = w - nums[j];   
        }  
        v = v - nums[i];  
    }    
    return false;    
}   


/**
 * 两数相加
 */
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int a = 0;
    int b = 0;
    int c = 0;
    int r = 0;
    int o0 = 0; 
    int o1 = 0;
    ListNode* h = nullptr, *p = nullptr;
    while(true){
        o1 = o0;
        if(l1!=nullptr) {
            a = l1->val;
        }else{
            a = 0;
        }
        if(l2!=nullptr) {
            b = l2->val;
        }else{
            b = 0;
        }
        c = a + b + o1;
        if (c>=10){
            r = c - 10;
            o0 = 1;
        }else{
            r = c;
            o0 = 0;
        }
        if (h==nullptr){
            h = p = new ListNode(r);
        }else{
            p->next = new ListNode(r);
            p = p->next;
        }
        if(l1!=nullptr) l1 = l1->next;
        if(l2!=nullptr) l2 = l2->next;
        if(l1==nullptr && l2==nullptr && o0 == 0) break;
    }
    return h;
}


/*
 *给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 
 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 *
 */
vector<int> Solution::twoSum(vector<int>& nums, int target) {
    map<int,int> mymap;
    vector<int> res;
    int n = nums.size();
    for(int i=0;i<n;i++){
        mymap[nums[i]] = i+1;
    }
    for(int i=0;i<n;i++){
        int other = target - nums[i];
        int other_index = mymap[other];
        if (other_index!=0 && other_index-1 != i){
            res.push_back(i);
            res.push_back(other_index-1); 
            break;
        }
    }
    return res;
}


/**
 *给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 */
int Solution::lengthOfLongestSubstring(string s) {
    map<char,int> mymap;
    int count = 0, maxv = 0, start=0;
    for(int i=0; i<s.size(); i++){
        int j = mymap[s[i]];
        mymap[s[i]] = i+1;
        if(j==0){
            count ++;
        }else{
            start = max(j, start);
            count = i + 1 - start;
        }
        if(count>maxv) maxv=count;
    }
    return maxv;
}

/**
 *给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 请你找出并返回这两个正序数组的 中位数 。
 */
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int p=0, q=0;
    int left=0, right=0;
    vector<int> new_nums;
    double res = 0;
    while(true){
        if(p==nums1.size()){
            left = 1e6; 
        }else{
            left = nums1[p];
        }
        if(q==nums2.size()){
            right = 1e6; 
        }else{
            right = nums2[q];
        }
        if(p==nums1.size() && q==nums2.size()){
            break;
        }
        if (left>right){
            new_nums.push_back(right);
            if(q!=nums2.size()) q++;
        }else{
            new_nums.push_back(left);
            if(p!=nums1.size()) p++;
        }
    }
    if(new_nums.size()%2==0){
        res = ((double)new_nums[new_nums.size()/2-1]+(double)new_nums[new_nums.size()/2])/2;
    }else{
        res = (double)new_nums[new_nums.size()/2];
    }
    return res;
}

/**
 *给你一个字符串 s，找到 s 中最长的回文子串。
 */
string Solution::longestPalindrome(string s) {
    string ss ="";
    for(int i=0; i<s.size(); i++){
        if (i==0){
            ss.push_back('^');
        }else{
            ss.push_back('#');
        }
        ss.push_back(s[i]);
    }
    ss.push_back('$');
    int* P = new int[ss.size()];
    int L = 0;
    int R = -1;
    for (int i=0; i<ss.size(); i++){
        P[i] = 0;
        if(i<=R){
            P[i] = min(P[L+R-i],R-i);
        }
        int left = i-P[i]-1;
        int right = i+P[i]+1;
        while(left>=0 && right<ss.size() && ss[left]==ss[right]){
            P[i] ++;
            left --;
            right ++;
        }
        if(i+P[i]>R){
            L = i-P[i];
            R = i+P[i];
        }
    }
    int c = 0;
    int radius = 0;
    for(int i=0; i<ss.size(); i++){
        cout << P[i] << " ";
        if(P[i]>0){
            if(radius<P[i]){
                radius = P[i];
                c = i;
            }else if(radius==P[i]){
                if(i%2==0){
                    c = i;
                }
            }
        }
    }
    ss = ss.substr(c-radius,2*radius+1);
    if(ss.compare("^")==0){
        return s.substr(0,1);
    }
    ss = regex_replace(ss, std::regex("\\#|\\^|\\$"), "");
    return ss;
}


/**
 *将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 P   A   H   N
 A P L S I I G
 Y   I   R
 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 */
string Solution::convert(string s, int numRows) {
    if(numRows<=1) return s;
    int numCols = s.size()/(numRows + numRows-2)*(numRows-1) + s.size()%(numRows + numRows-2) ;
    char P[numRows][numCols];
    bool p[numRows][numCols];

    for(int i=0; i<numRows; i++){
        for(int j=0; j<numCols; j++){
            p[i][j] = false;
        }
    }

    int k=0;
    for(int j=0;j<numCols;j++){
        for(int i=0;i<numRows;i++){
            if(k==s.size()) break;
            int r = j % (numRows-1);
            if(r==0){
                P[i][j] = s[k];
                p[i][j] = true;
                k++;
            }else{
                if ((i+j)%(numRows-1)==0){
                    P[i][j] = s[k];
                    p[i][j] = true;
                    k++;
                }
            }
        }
    }
    string out;
    for(int i=0; i<numRows; i++){
        for(int j=0; j<numCols; j++){
            if(p[i][j]==true){
                out.push_back(P[i][j]);
            }
        }
    }
    return out;
}

long Solution::reverse(long x){
    vector<int> buf;
    int sgn = (x>0)?1:-1;
    x = abs(x);
    while(x>0){
       int q = x / 10;
       int r = x % 10;
       buf.push_back(r);
       x = q;
    }
    long out = 0;
    int n = buf.size();
    for(int i=0; i<n; i++){
       out += pow(10,i) * buf[n-i-1]; 
    }
    out = sgn * out;
    if(out<-pow(2,31) or out>pow(2,31)-1) return 0;
    return out;
}

Pattern::Pattern(string & p){
    int n = p.size();
    int star_count = 0;
    for(int i=0; i<n; i++){
        if(p[i] == '*'){
            star_count ++;
        }
    }
    int ns = n - star_count + 1; // 节点数
    this->graph = make_unique<char[]>(ns*ns);
    cout << graph.use_count()<< endl;
    shared_ptr<char[]> tmp = this->graph;
    cout << tmp.use_count()<< endl;
    this->num_nodes = ns;
    int j = 0;
    for(int i=0; i<n; i++){
        if(p[i]=='*') continue;
        if(i+1<n && p[i+1] =='*'){
            this->graph[j*ns+j] = p[i];
            this->graph[j*ns+j+1] = '*';
        }else{
            this->graph[j*ns+j+1] = p[i];
        }
        j++;
    }
    for(int i=0; i<ns; i++){
        for(int j=0; j<ns; j++){
            char c = this->graph[i*ns+j];
            if(c == 0){
                c = '#';
            }
            printf("%c ",c);
        }
        printf("\n");
    }
}

bool Pattern::subMatch(string & s, int loc, int status){
    printf("%c : %d,%d\n",s[loc],loc,status);

    int n = s.size(); 

    if(status == this->num_nodes-1 && loc <n) return false;

    char ch0 = this->graph[status * this->num_nodes + status];
    char ch1 = ' ';
    if (status+1 < this->num_nodes){
        ch1 = this->graph[status * this->num_nodes + status + 1];
    }

    if(loc ==n) {
        if(status == this->num_nodes-1){
            return true;
        }else{
            if(ch1 != '*'){
                return false;    
            }
        }
    }

    if(ch1 != '*'){ // a* 型
        return (ch1 == s[loc] || ch1 == '.') && subMatch(s, loc+1, status+1);
    }else{
        if(loc==n) return subMatch(s, loc, status+1);
        return (ch0 == s[loc] || ch0 == '.') && subMatch(s, loc+1, status) || subMatch(s, loc, status+1);
    }
}

bool Solution::isMatch(string & s, string & p){
    int n = s.size();
    int m = p.size();
    int j = m-1;
    Pattern pattern(p);
    return pattern.subMatch(s, 0, 0);
}

int Solution::maxArea(vector<int>& height){
    int p=0,q=height.size()-1;
    int max_area = 0;
    while(q>p){
        cout << p << "  " << q << endl;
        int area = (q-p)*min(height[p],height[q]);
        if(max_area<area) max_area = area;
        if(height[p]>=height[q]){
            q--;
        }else{
            p++;
        }
    }
    return max_area;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k){
    ListNode *nodeStack[k];
    ListNode *curr, *tail;
    curr = head;
    tail = nullptr;
    head = nullptr;
    int i = -1;
    while(curr!=nullptr || i==k-1){
        if(i==k-1){
            ListNode *r_curr=nullptr, *r_prev=nullptr, *r_head=nullptr;
            while(i>-1){
                r_curr = nodeStack[i];
                r_curr->next = nullptr;
                if(r_prev==nullptr) {
                    r_head = r_prev = r_curr;
                }else{
                    r_prev->next = r_curr;
                    r_prev = r_curr;
                }
                i--;
            }
            if(tail==nullptr){
                head = r_head;
            }else{
                tail->next = r_head;
            }
            tail = r_curr;
        }else{
            nodeStack[++i]=curr;
            curr = curr->next;
        } 
        printf("%s %d: ",__FILE__,__LINE__);
        printNodes(head);
    }
    if(i>-1 && i<k-1){
        tail->next = nodeStack[0];
    }
    return head;
}

ListNode *createListNodes(vector<int> vec){
    ListNode *head=nullptr, *curr=nullptr;
    for(int i=0; i<vec.size(); i++){
        if(head==nullptr) {
            curr = head = new ListNode(vec[i]);
        }else{
            curr->next = new ListNode(vec[i]);
            curr = curr->next;
        }
    }
    return head;
}

void freeNodes(ListNode *head){
    ListNode *prev;
    while(head!=nullptr){
        prev = head;
        head = head->next;
        delete prev;
    }
}


void printNodes(ListNode * head){
    while(head != nullptr){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}

void printIntVec(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int Solution::removeDuplicates(vector<int>& nums){
    int slow = 1;
    int fast = 1;
    int numsSize = nums.size();
    if(numsSize==0)return 0;
    while(fast<numsSize){
        printIntVec(nums);
        if(nums[fast]!=nums[fast-1]){
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}
