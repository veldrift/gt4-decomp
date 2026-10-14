/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct E {
    char pad[0x1C];
    u32 *a;
    u16 *b;
    char pad24[4];
    u16 *cnt;
};
struct T {
    E e[4];
    u8 n;
};
struct Obj {
    char pad[0xC];
    u32 *lim;
    char pad10[0x14];
    T *t;
};
extern "C" void func_004C1118(Obj *, u32, u32, u32, int, int);

struct Counts { u16 *b; int pad; u16 *cnt; };
static inline u16 count(T *t, u32 i) { return *t->e[i].cnt; }
static inline u16 dec(T *t, u32 i) { return --*t->e[i].cnt; }
static inline u32 value(T *t, u32 i, u32 j) {
    u16 b = t->e[i].b[j];
    u32 a = t->e[i].a[j];
    return (b << 12) | (a >> 20);
}
extern "C" int func_004C0F30(Obj *obj, u32 arg1) {
    u32 i = 0;
    u32 wrap = *obj->lim < arg1;
    for (; i < obj->t->n; i = (i + 1) & 65535) {
        u32 j = 0;
        while (j < count(obj->t, i)) {
            u32 val = value(obj->t, i, j);
            if ((wrap == 0 && *obj->lim >= val && arg1 < val) ||
                (wrap == 1 && (*obj->lim >= val || arg1 < val))) {
                u16 n = dec(obj->t, i);
                func_004C1118(obj, i, n, j, 0, 0);
                if (count(obj->t, i) == 0) break;
            } else {
                j = (j + 1) & 65535;
            }
        }
    }
    return 0;
}
