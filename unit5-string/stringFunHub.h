#ifndef STRING_FUN_HUB_H
#define STRING_FUN_HUB_H

void StrAssign(&T, chars);
void StrCopy(&T, S);
bool StrEmpty(S);
int StrCompare(S, T);
int StrLength(S);
void Concat(&T, S1, S2);
void SubString(&Sub, S, pos, len);
int Index(S, T, pos);
void Replace(&S, T, V);
void StrInsert(&S, pos, T);
void StrDelete(&S, pos, len);
void DestroyString(&S);

#endif