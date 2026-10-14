/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct E { s16 delta; s16 index; s32 (*fn)(void *); };
struct Host { char pad[4]; char *vtbl; };

extern "C" void func_001240D8(void *, int) throw();
extern "C" s32 func_00124130(void *, void *) throw();
extern "C" s32 *func_00127B88(s32, s32);
extern "C" void func_00202C48(void *, s32);
extern "C" void func_00203118(void *, int);
extern "C" void func_00203620(void *, int);
extern "C" void func_00204558(void *, void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002EEEB0(void *, s32, void *);
extern "C" void func_002EFBF0(void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MQuickWork__getColorChipInfo(s32 *arg0, void *arg1, s32 cnt, Host **pp) {
    s32 obj[4];
    s32 r10[4];
    s32 r20[4];
    s32 r30[4];
    s32 r40[4];
    s32 v;
    func_00124130(obj, arg1);
    v = 0;
    if (cnt > 0) {
        Host *o = *pp;
        E *e = (E *)(o->vtbl + 0x58);
        v = e->fn((char *)o + e->delta);
    }
    s32 i = 3;
    s32 *p = func_00127B88(obj[0], v);
    s32 *p10 = r10;
    func_002EFBF0(p10);
    s32 *p20 = r20;
    s32 *p30 = r30;
    s32 *p40 = r40;
    do {
        s32 a = *p;
        p++;
        i--;
        func_00202C48(p20, a);
        s32 s0 = p10[0];
        func_00204558(p40, p20);
        func_002EEEB0(p30, s0, p40);
        func_00309378(p30, 2);
        func_00203620(p40, 2);
        func_00203118(p20, 2);
    } while (i >= 0);
    if (arg0 != p10) {
        s32 nv = p10[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*arg0 != 0)
            func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_002ED5C0(p10, 2);
    func_001240D8(obj, 2);
}
