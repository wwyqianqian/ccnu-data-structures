#ifndef STRING_LIST_FUN_HUB_H
#define STRING_LIST_FUN_HUB_H

const int LIST_INIT_SIZE = 100;

typedef char String[LIST_INIT_SIZE + 1];


// Function1: Assign a string
void StrAssign(String &T, chars *ch) { // atom
    for (int i = 0; ch[i] != '\0' && i < LIST_INIT_SIZE; ++i) {
    	T[i] = ch[i];
    }
    T[i] = '\0';
    cout << "Finished StrAssign()" << endl;
} 


// Function2: Copy a String
void StrCopy(String &T, String S) {
    for (int i = 0; S[i] != '\0' && i < LIST_INIT_SIZE; ++i) {
        T[i] = S[i];
    }
    T[i] = '\0';
    cout << "Finished StrCopy()" << endl;
}


// Function3: Return the length of the string
int StrLength(String S) { // atom
    int i = 0;
    while (S[i] != '\0') {
    	i++;
    }
    return i;
}


// Function4: Return true if the string is empty
bool StrEmpty(String S) {
    if (StrLength(S) == 0) {
    	return true;
    } else {
    	return false;
    }
}


// Function5: Return 0 if S = T, 1 of S > T and -1 of S < T
int StrCompare(String S, String T) { // atom
    int i = 0;
    while (i < StrLength(S) && i < StrLength(T)) {
        if (S[i] < T[i]) {
            return -1;
        } else if (S[i] > T[i]) {
            return 1;
        } else {
            i++;
        }
    }
    if (StrLength(S) == StrLength(T)) {
        return 0;
    } else if (StrLength(S) < StrLength(T)) {
        return -1;
    } else {
        return 1;
    }
}


// Function6: T = S1 + S2
void Concat(String &T, String S1, String S2) { // atom
    if (StrLength(S1) + StrLength(S2) <= LIST_INIT_SIZE) { // 直接相加就好
        int i = 0, j = 0;
        for (i; S1[i] != '\0'; i++) {
            T[i] = S1[i];
        }
        j = i;
        for (i = 0; S2[i] != '\0'; i++, j++) {
            T[j] = S2[i];
        }
        T[j] = '\0';
    } else {                                  // 长度过于长，需要截断后面的部分 string(S1 默认未超长)
        int i = 0, j = 0;
        for (i; S1[i] != '\0'; i++) {
            T[i] = S1[i];
        }
        j = i;
        for (i = 0; S2[i] != '\0' && j <= LIST_INIT_SIZE - 1; i++, j++) {
            T[j] = S2[i];
        }
        T[j] = '\0';
    }
} 


// Function7:  Return the part of the string between the start and end indexes, or to the end of the string.
bool SubString(String &Sub, String S, int pos, int len) { // atom  
    if (pos < 0 || pos > LIST_INIT_SIZE || len < 0 || len + pos > LIST_INIT_SIZE + 1) { // About pos: If this is equal to the string length, the function returns an empty string.
        return false;
    } else {                                                                            // The first character is denoted by a value of 0 (not 1).
        for(int i = 0; i < len; i++) {
            Sub[i] = S[i + pos];
        }
        Sub[i] = '\0';
        return true;
    }
}


// Function8: 模式匹配（朴素/KMP）
int Index(S, T, pos);
void Replace(&S, T, V);
void StrInsert(&S, pos, T);
void StrDelete(&S, pos, len);
void DestroyString(&S);

#endif