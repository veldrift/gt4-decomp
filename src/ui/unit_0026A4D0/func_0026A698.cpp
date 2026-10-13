typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

extern "C" void func_005DEE78(void *ret, void *mid, void *key);
extern "C" s32 func_005C2A50(void *self, void *other, u32 pos, u32 n);
extern "C" char *func_005C2560(Rep *r);
extern "C" void func_00328738(s32 *a, s32 *b);
extern "C" void func_0028BBF0(void *a, void *b);
extern "C" void func_005DEEF8(void *ret, void *mid, void *a2, void *a3);
extern "C" void func_0028BC08(void *a, s32 n);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

extern "C" void func_0026A698(char *arg0, s32 *arg1, s32 *arg2) {
    s32 sp0[4];   /* sp+0x00: out of func_005DEE78, later the out of func_005DEEF8 */
    s32 sp10[4];  /* sp+0x10: header temporary */
    s32 sp20[4];  /* sp+0x20: out value of func_005DEEF8 */
    s32 sp30[4];  /* sp+0x30: node pointer kept for the calls */
    s32 sp40[4];  /* sp+0x40: string pointer, object at +4 */
    s32 sp50[4];  /* sp+0x50: object */
    s32 sp60[4];  /* sp+0x60: pointer argument for func_005DEEF8 */
    s32 sp70[4];  /* sp+0x70: zero word, the flag of func_00328738 */
    char *s1 = arg0 + 0x20;

    func_005DEE78(sp0, s1, arg1);
    s32 missing = 0;
    sp10[0] = ((s32 *)s1)[1];
    if (sp0[0] == sp10[0] ||
        func_005C2A50(arg1, (char *)sp0[0] + 0x10, 0, (u32)-1) < 0) {
        missing = 1;
    }

    if (missing != 0) {
        s32 *pa = sp30;
        s32 *pb = sp50;
        s32 *pk = sp40;
        pa[0] = sp0[0];
        sp70[0] = 0;
        func_00328738(pb, sp70);

        char *src = (char *)arg1[0];
        Rep *r = (Rep *)(src - 0x10);
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
            d = src;
        }
        pk[0] = (s32)d;
        func_0028BBF0(pk + 1, pb);
        s32 *p60 = sp60;
        p60[0] = pa[0];
        func_005DEEF8(sp20, s1, p60, pk);
        sp0[0] = sp20[0];
        func_0028BC08(sp40 + 1, 2);

        Rep *q = (Rep *)(pk[0] - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
        func_0028BC08(pb, 2);
    }

    char *dst = (char *)sp0[0] + 0x14;
    if (dst != (char *)arg2) {
        s32 newVal = arg2[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        s32 oldVal = *(s32 *)dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *(s32 *)dst = newVal;
    }
}
