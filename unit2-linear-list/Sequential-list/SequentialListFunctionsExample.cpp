// 课程例题
// 2.1 求两个集合 A，B 的并集

void union1(List &LA, List &LB) {
    La_len = ListLength(LA);
    while (!ListEmpty(LB)) {
        ListDelete(LB, 1, e);
        if (!LocateElem(LA, e)) {
            ListInsert(LA, ++La_len, e);
        }
    }
    DestroyList(LB);
}

void union2(List &LA, List &LB) {
    La_len = ListLength(LA);
    Lb_len = ListLength(LB);
    for (int i = 0; i < Lb_len; i++) {
        if (!LocateElem(LA, GetElem(LB, i , e))) {
            ListInsert(LA, ++La_len, e);
        }
    }
}


// 2.2 非纯集合 B，构造纯集合A，包含 B 中所有值不相同的元素

void purge(List &LA, List &LB) {
    InitList(LA);
    La_len = 0;
    while (!ListEmpty(LB)) {
        ListDelete(LB, 1, e);
        if (!LocateElem(LA, e)) {
            ListInsert(LA, ++La_len, e);
        }
    }
    DestroyList(Lb);
}


// 2.3 判断 A B 集合是否相等

bool isequal(List LA, List Lb) {
    La_len = ListLength(LA);
    Lb_len = ListLength(LB);
    if (La_len != Lb_len) {
        return FALSE;
    } else {
        InitList(LC);
        for (int k = 1; k <= La_len; ++k) {
            GetElem(LA, k, e);
            ListInsert(LC, k, e);
        } // copy List LA to List LC
        found = TRUE;
        for (int k = 1; k <= Lb_len, found; ++k) {
            GetElem(LB, k, e);
            i = LocateElem(LC, e);
            if (i == 0) {
                found = FALSE;
            } else {
                ListDelete(LC, i, e);
            }
        }
        if (found && ListEmpty(LC)) {
            DestroyList(LC);
            return TRUE;
        } else {
            DestroyList(LC);
            return FALSE;
        }
    }
}