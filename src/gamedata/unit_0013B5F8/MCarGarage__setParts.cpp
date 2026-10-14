/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef long long s64;
typedef unsigned short u16;
struct VEnt { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x58]; VEnt e; };
struct VO { char pad[4]; VT *vt; };
struct Arg { VO *a; VO *b; };
extern "C" {
void func_0013BD68(void *, int) throw();
void func_0013BDC0(void *) throw();
int func_00147D80(s32);
void func_00440B50(s32, s64, s32);
s32 func_00441248(s32);
void func_00446AE0(s32, u16);
s64 func_0044A048(s32, s64, s32);
int func_0044A250(int);

static inline s32 vcall(VO *o) {
    VEnt *e = &o->vt->e;
    return e->fn((char *)o + e->delta);
}

void MCarGarage__setParts(void *arg0, s32 arg1, s32 arg2, Arg *arg3) {
    if (arg2 >= 2) {
        s32 obj;
        func_0013BDC0(&obj);
        s32 s0 = vcall(arg3->a);
        s32 s2 = vcall(arg3->b);
        s64 r = func_0044A048(obj + 0x18, s0, s2);
        s32 ne = (r != -1);
        if (!ne) {
            if (s2 == 0 && func_0044A250(s0) != 0) {
                s0 &= 0xFFFF;
                func_00446AE0(func_00441248(func_00147D80(obj)), s0);
            }
        } else {
            func_00440B50(func_00147D80(obj), r, obj + 0x30);
        }
        func_0013BD68(&obj, 2);
    }
}
}
