/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
struct B60 { s32 cnt; s32 p4; s32 p8; };
struct Q { char pad[0x60]; s32 p60; };
struct W { char pad[0x6C]; s32 q; };
#define LST(q) ((B60 *)(q)->p60)
#define ITEM(q, i) (((s32 *)LST(q)->p8)[i])
extern char *D_00622F4C;
extern "C" void func_00110CB8(void *, void *);
extern "C" char *func_00445450(char *);
extern "C" s32 func_00445AE8(char *, char *);
extern "C" char *func_005A609C(char *, const char *);

extern "C" void func_00111A40(char *self, W *w) {
    Q *q = (Q *)w->q;
    s32 n = LST(q)->cnt;
    s32 i = 0;
    if (n > 0) do {
        char *c = (char *)ITEM(q, i);
        s32 idx = *(s32 *)(c + 0x3444);
        func_005A609C(self + (idx << 7) + 4, func_00445450(c + 0x20));
        func_00445AE8((char *)ITEM(q, i) + 0x20, self + idx * 0x10 + 0x304);
        i++;
    } while (i < n);
    *(s32 *)(self + 0x478) = n;
    *(s32 *)(self + 0x46C) = 0;
    *(s32 *)(self + 0x4A0) = *(s32 *)(ITEM(q, 0) + 0x3444);
    func_005A609C(self + 0x408, D_00622F4C + 4);
    *(s32 *)(self + 0x494) = 1;
    func_00110CB8(self, q);
}
