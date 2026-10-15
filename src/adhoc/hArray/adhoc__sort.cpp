typedef int s32;
struct H { s32 p; s32 pad[3]; };
struct W { char *vp; char sub[4]; int pad[2]; };
extern char D_006734F0[], hArrayCompare__vtable[], FunctionCompare__vtable[];
extern "C" void func_002ED5C0(void *, int) throw();
extern "C" void func_002ED618(void *, s32) throw();
extern "C" void func_002F03C8(s32, W *);
extern "C" void func_002F9B20(void *, void *);
extern "C" void func_002F9B38(void *, int);
extern "C" void func_002F9B90(void *, void *);

static inline void finish(H *it, W *o, char *v) { o->vp=v; func_002ED5C0(it,2); }
extern "C" void adhoc__sort(void *self, s32 unused, s32 sel, void *arg3) {
    H it;
    if (sel == 0) {
        W o;
        func_002ED618(&it, unused);
        char *bv = hArrayCompare__vtable;
        W *po = &o;
        s32 itp = it.p;
        po->vp = D_006734F0;
        func_002F03C8(itp, po);
        finish(&it, po, bv);
    } else if (sel == 1) {
        H s20;
        W s30;
        func_002ED618(&it, unused);
        char *bv = hArrayCompare__vtable;
        H *p20 = &s20;
        func_002F9B90(p20, arg3);
        W *p30 = &s30;
        s32 itp = it.p;
        char *p34 = p30->sub;
        char *v2 = FunctionCompare__vtable;
        p30->vp = v2;
        func_002F9B20(p34, p20);
        func_002F03C8(itp, p30);
        p30->vp = v2;
        func_002F9B38(p34, 2);
        p30->vp = bv;
        func_002F9B38(p20, 2);
        func_002ED5C0(&it, 2);
    }
}
