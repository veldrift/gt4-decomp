/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEnt { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x58]; VEnt e; };
struct VO { char pad[4]; VT *vt; };
struct Arg { VO *a; VO *b; };
extern "C" {
void func_0013BD68(void *, int) throw();
void func_0013BDC0(void *) throw();
int func_00147D80(void *);
void func_002FC870(void *, int);
void func_002FE278(void *, int);
void func_003285A8(void *);
void func_003285F8(void *);
s32 func_0043F3E0(s32, s32, s32);
s32 func_0044A190(s32, s32, s32);

static inline s32 vcall(VO *o) {
    VEnt *e = &o->vt->e;
    return e->fn((char *)o + e->delta);
}

void MCarGarage__isAllowedParts(void **arg0, s32 arg1, s32 arg2, Arg *arg3) {
    if (arg2 >= 2) {
        s32 obj;
        void *h[4];
        func_0013BDC0(&obj);
        s32 s2 = vcall(arg3->a);
        s32 s0 = vcall(arg3->b);
        s32 r = func_0043F3E0(func_00147D80((void *)obj), s2, s0);
        if (r != 0 || (s0 > 0 && func_0044A190(obj + 0x18, s2, s0 - 1) == 0)) {
            void **ph = h;
            func_002FE278(ph, 1);
            if (arg0 != ph) {
                void *p = ph[0];
                if (p != 0) func_003285A8(p);
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                    *arg0 = p;
                } else {
                    *arg0 = p;
                }
            }
            func_002FC870(ph, 2);
        } else {
            void **ph = h;
            func_002FE278(ph, 0);
            if (arg0 != ph) {
                void *p = ph[0];
                if (p != 0) func_003285A8(p);
                if (*arg0 != 0) {
                    func_003285F8(*arg0);
                    *arg0 = p;
                } else {
                    *arg0 = p;
                }
            }
            func_002FC870(ph, 2);
        }
        func_0013BD68(&obj, 2);
    }
}
}
