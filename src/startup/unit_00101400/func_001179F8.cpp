/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Item { char pad[0x20]; };
struct B60 { s32 cnt; s32 p4; s32 p8; };
struct Q { char pad[0x60]; s32 p60; char pad64[0xC]; void *p70; };
struct W { char pad[0x6C]; s32 q; };
extern "C" {
void func_0042F448(char *, void *, s32, u8, u8, s32);
s32 func_004334F8(void *, s32);
void *func_00433C10(char *, void *);
s32 func_00445350(char *);
void *func_004472A0(void *);
}
extern char *D_00622F4C;
static inline s32 keyOf(s32 *p) { return *p; }
extern "C" void func_001179F8(W *self, s32 *a1) {
    Q *q = (Q *)self->q;
    s32 flag = 0;
    func_00445350((char *)((s32 *)((B60 *)q->p60)->p8)[0] + 0x20);
    void *nm = func_004472A0(q->p70);
    void *e = func_00433C10(D_00622F4C + 0x14A30, nm);
    if (keyOf(a1) != 0x157529FF && func_004334F8(e, 0) == keyOf(a1)) {
        s32 r = func_004334F8(e, 1);
        flag = r != keyOf(a1);
    }
    func_0042F448(D_00622F4C + 0x568, nm, 1, 0xF, flag ? 0xD : 0xE, keyOf(a1));
}
