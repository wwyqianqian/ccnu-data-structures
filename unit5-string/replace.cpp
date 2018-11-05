// 使用原子操作写 replace 函数，伪代码
void replace(String &S, String T, String V) {
    n = StrLength(S);
    m = StrLength(T);
    pos = 0;

    StrAssign(news, "");
    i = 1;

    while (pos <= n - m && i != -1) {
        i = Index(S, T, pos);
        if (i != -1) {
            SubString(sub, S, pos, i - pos);
            Concat(news, news, sub);
            Concat(news, news, V);
            pos = i + m;
        }
    }

    SubString(sub, S, pos, n - pos);
    Concat(news, news, sub);
}