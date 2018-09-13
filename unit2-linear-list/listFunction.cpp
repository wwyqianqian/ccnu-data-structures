InitList(&L)
//  构造空 linear List

DestroyList(&L)
// L 存在，销毁 L

ClearList(&L)
// L 存在，重置为空表 L

ListEmpty(L)
// L 存在，L 为空返回 True；否则 False

ListLength(L)
// L 存在，返回元素个数，即 L 长度

GetElem(L, i, &e)
// 1 <= i <= ListLength(L)，返回 L 中第 i 元素的值，作为 e

LocateElem(L, e)
// L 存在，返回第一个与 e 相同值的位序，不存在就返回 0

PriorElem(L, cur_e, &pre_e)
// L 存在，cur_e 为 L 元素，而且不是第一个，就返回他的前驱。否则操作失败无意义。

NextElem(L, cur_e, &next_e)
// L 存在，cur_e 为 L 元素，而且不是最后一个，就返回他的后继。否则操作失败无意义。

ListInsert(&L, i, e)
// L 存在，1 <= i <= LengthList(L) + 1，在 L 的第 i 个元素之前插入新元素 e，L 长度加一。

ListDelete(&L, i, &e)
// L 存在而且非空，1 <= i <= LengthList(L)。删除 L 的第 i 个元素，并且用 e 返回其值，L 长度减一。

ListTraverse(L)
// L 存在，依次输出 L 中每个元素。
