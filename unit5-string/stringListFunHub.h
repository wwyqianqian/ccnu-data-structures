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


} 






void SubString(&Sub, S, pos, len); // atom
int Index(S, T, pos);
void Replace(&S, T, V);
void StrInsert(&S, pos, T);
void StrDelete(&S, pos, len);
void DestroyString(&S);

#endif