/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct E {
    char b;
    char pad1[3];
    void *p4;
    short n8;
    char pad0A[2];
    s32 c;
};

extern "C" {
void func_004C2030(s32, void *);
s32 func_004C2048(s32, s32, s32, void **);
s32 func_004C2348(s32, s32, s32, void **);
void func_004C4070(void *, void *, s32);
s32 func_004C4DE8(s32);
void *func_004C8C20(s32, s32);
s32 func_004C8ED0(s32);
}

extern "C" s32 func_004C1E68(s32 a0, s32 a1, s32 a2, E **out)
{
    void *sp0;
    void *sp4;
    s32 b = func_004C8ED0(a1);
    s32 n1;
    s32 n2;
    s32 tot;
    void *blk;
    E *e;

    *out = 0;
    sp0 = 0;
    if (func_004C4DE8(a1) < 0) {
        return 0;
    }
    n1 = func_004C2048(a0, a1, a2, &sp0);
    if (n1 < 0) {
        return n1;
    }
    n2 = func_004C2348(a0, a1, a2, &sp4);
    if (n2 < 0) {
        if (n1 > 0) {
            func_004C2030(a0, sp0);
        }
        return n2;
    }
    tot = n1 + n2;
    if (tot == 0) {
        return 0;
    }
    blk = func_004C8C20(a0, tot * 16);
    if (blk == 0) {
        if (n1 > 0) {
            func_004C2030(a0, sp0);
        }
        if (n2 > 0) {
            func_004C2030(a0, sp4);
        }
        return (s32)0x80000321;
    }
    if (n1 > 0) {
        func_004C4070(blk, sp0, n1 * 16);
        func_004C2030(a0, sp0);
    }
    sp0 = blk;
    if (n2 > 0) {
        s32 off = n1 * 16;
        n1 = tot;
        func_004C4070((char *)blk + off, sp4, n2 * 16);
        func_004C2030(a0, sp4);
    }
    if (n1 == 0) {
        return 0;
    }
    e = (E *)func_004C8C20(a0, 0x10);
    if (e == 0) {
        func_004C2030(a0, sp0);
        return (s32)0x80000321;
    }
    e->b = b;
    e->p4 = sp0;
    e->n8 = n1;
    e->c = 0;
    *out = e;
    return n1;
}
