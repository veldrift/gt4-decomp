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
s32 func_0043F3A8(s32, s32, s32);
int func_0044A1B8(int);
int func_0044A250(int);

static inline s32 vcall(VO *o) {
    VEnt *e = &o->vt->e;
    return e->fn((char *)o + e->delta);
}

void MCarGarage__isHavingParts(void **arg0, s32 arg1, s32 arg2, Arg *arg3) {
    if (arg2 >= 2) {
        void *obj;
        void *h[4];
        func_0013BDC0(&obj);
        s32 s0 = vcall(arg3->a);
        s32 s2 = vcall(arg3->b);
        if (func_0044A250(s0) != 0 && func_0044A1B8(s0) == 0 && s2 == 0) {
            void **ph = h;
            func_002FE278(ph, 1);
            if (arg0 != ph) {
                void *p = ph[0];
                if (p != 0) func_003285A8(p);
                if (*arg0 != 0) func_003285F8(*arg0);
                *arg0 = p;
            }
            func_002FC870(ph, 2);
        } else if (func_0043F3A8(func_00147D80(obj), s0, s2) == 0) {
            void **ph = h;
            func_002FE278(ph, 0);
            if (arg0 != ph) {
                void *p = ph[0];
                if (p != 0) func_003285A8(p);
                if (*arg0 != 0) func_003285F8(*arg0);
                *arg0 = p;
            }
            func_002FC870(ph, 2);
        } else {
            void **ph = h;
            func_002FE278(ph, 1);
            if (arg0 != ph) {
                void *p = ph[0];
                if (p != 0) func_003285A8(p);
                if (*arg0 != 0) func_003285F8(*arg0);
                *arg0 = p;
            }
            func_002FC870(ph, 2);
        }
        func_0013BD68(&obj, 2);
    }
}
}
