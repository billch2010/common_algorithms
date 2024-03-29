/*
模式字符串匹配问题，kmp减少重复比较的次数
KMP模式匹配详解可参考 <https://www.cnblogs.com/zhangtianq/p/5839909.html> 
如果文本串的长度为n，模式串的长度为m，那么匹配过程的时间复杂度为O(n)，计算next的O(m)时间，KMP的整体时间复杂度为O(m + n)
*/
// pattern为空，返回0
int strstr(string raw, string pattern) {
    if (pattern.empty()) return 0;
    if (raw.empty()) return -1;
    int la = raw.size();
    int lb = pattern.size();
    if (la < lb) return -1;
    vector<int> next(lb, 0);
    
    // method 1
    #if 0
    int i = 0, j = -1, k = -1;
    next[0] = j;
    for (int i = 1; i < lb; ++i) {
        while (j > -1 && pattern[i] != pattern[j + 1]) 
            j = next[j];
        if (pattern[i] == pattern[j+1])
            ++j;
        next[i] = j;
    }
    for (int i = 0, j = -1; i < la; ++i) {
        while (j > -1 && raw[i] != pattern[j + 1]) 
            j = next[j];
        if (raw[i] == pattern[j+1])
            ++j; 
        if (j == lb - 1) {
            return i - j;
        }
    }
    #endif 
    
    // method 2
    #if 0
    int i = 0; 
    int k = -1;
    next[0] = -1;
    while (i < nlen-1) {
        if (k == -1 || pattern[i] == pattern[k]) {
            ++k;
            ++i;
            if (pattern[i] != pattern[k]) 
                next[i] = k;
            else
                next[i] = next[k];
        } else {
            k = next[k];
        }
    }
    int j = 0;
    i = 0;
    k = -1;
    while (i < hlen && j < nlen) {
        if (j == -1 || raw[i] == pattern[j]) {
            ++i; ++j;
        } else {
            j = next[j];
        }
    }
    if (j == nlen) 
        return i - j;    
    #endif
    
    return -1;
}
