/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned long long u64;
struct T { s16 lo; s16 hi; };
struct VEnt { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x58]; VEnt e; };
struct VO { char pad[4]; VT *vt; };
extern "C" {
void func_002ED5C0(void *, int);
void *func_002EEEB0(void *, void *, void *);
void func_002EFBF0(void *);
void func_002FC870(void *, int);
void func_002FE278(void *, s32);
void func_00309348(void *, void *);
void func_00309378(void *, s32);
void func_003285A8(void *);
void func_003285F8(void *);
T func_00579898(s32);

void MCalendar__dayToDate(void **arg0, s32 arg1, VO **arg2) {
    if (arg1 > 0) {
        VO *o = *arg2;
        VEnt *e = &o->vt->e;
        T t = func_00579898(e->fn((char *)o + e->delta));
        void *h[4];
        void *tmp[4];
        void *a[4];
        void *b[4];
        void *c[4];
        void **ph = h;
        func_002EFBF0(ph);
        void *s1 = ph[0];
        void **ptmp = tmp;
        func_002FE278(a, t.lo);
        func_002EEEB0(ptmp, s1, a);
        func_00309378(ptmp, 2);
        func_002FC870(a, 2);
        void *s1b = ph[0];
        func_002FE278(b, (u8)t.hi);
        func_002EEEB0(ptmp, s1b, b);
        func_00309378(ptmp, 2);
        func_002FC870(b, 2);
        void *s1c = ph[0];
        func_002FE278(c, (u8)(t.hi >> 8));
        func_002EEEB0(ptmp, s1c, c);
        func_00309378(ptmp, 2);
        func_002FC870(c, 2);
        if (arg0 != ph) {
            void *p = ph[0];
            if (p != 0) func_003285A8(p);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = p;
        }
        func_002ED5C0(ph, 2);
    } else {
        void *hh[4];
        s32 z;
        z = 0;
        func_00309348(hh, &z);
        if (arg0 != hh) {
            void *p = hh[0];
            if (p != 0) func_003285A8(p);
            if (*arg0 != 0) func_003285F8(*arg0);
            *arg0 = p;
        }
        func_00309378(hh, 2);
    }
}
}
