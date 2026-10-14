typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" void func_002AE9C0(void *, void *) throw();
extern "C" void func_002AE968(void *, s32) throw();
extern "C" s32 func_002B4DA0(s32, s32, s32);
extern "C" void func_00309348(void *, void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0022AC98(void *, void *);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MListBox__getItemWidget(s32 *arg0, void *arg1, s32 arg2, s32 *arg3) {
    s32 buf0[4];
    s32 h1[4];
    s32 buf2[4];
    s32 h3[4];
    s32 t[4];
    if (arg2 == 1) {
        func_002AE9C0(buf0, arg1);
        char *obj = (char *)arg3[0];
        s32 v_s0 = buf0[0];
        s32 *pt = t;
        t[0] = func_002B4DA0(v_s0, vcall_58(obj), 0);
        s32 *p = h1;
        func_00309348(p, pt);
        if (arg0 != p) {
            s32 nv = p[0];
            if (nv != 0)
                func_003285A8(nv);
            if (arg0[0] != 0)
                func_003285F8(arg0[0]);
            arg0[0] = nv;
        }
        func_00309378(p, 2);
        func_002AE968(buf0, 2);
    } else if (arg2 == 2) {
        func_002AE9C0(buf0, arg1);
        s32 *q = &t[1];
        *q = arg3[1];
        s32 *b2 = buf2;
        func_0022AC98(b2, q);
        char *obj = (char *)arg3[0];
        s32 v_s0 = buf0[0];
        s32 *pt = &t[2];
        *pt = func_002B4DA0(v_s0, vcall_58(obj), b2[0]);
        s32 *p = h3;
        func_00309348(p, pt);
        if (arg0 != p) {
            s32 nv = p[0];
            if (nv != 0)
                func_003285A8(nv);
            if (arg0[0] != 0)
                func_003285F8(arg0[0]);
            arg0[0] = nv;
        }
        func_00309378(p, 2);
        func_0022ACC8(b2, 2);
        func_002AE968(buf0, 2);
    }
}
