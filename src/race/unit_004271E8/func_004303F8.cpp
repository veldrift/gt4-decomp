typedef long long s64;
typedef int s32;
union Item { s64 v; char c; };
struct T { char pad[8]; s32 cap; s32 cnt; Item items[1]; };
extern "C" s32 func_004303B0(T *, s64);
extern "C" s32 func_004303F8(T *t, s64 v) {
    if (func_004303B0(t, v) >= 0) return -1;
    s32 n = t->cnt;
    if (n >= t->cap) return -1;
    Item *p = t->items + n;
    p->v = v;
    t->cnt++;
    return n;
}
