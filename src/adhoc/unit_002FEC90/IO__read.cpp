typedef int s32;
typedef short s16;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Handle {
    s32 p;
    char pad[0xC];
};

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32);
};

struct VObj {
    char pad[4];
    VEntry *vtbl;
};

extern Rep D_00659FA8;

extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" s32 func_002FE250(s32 arg0);
extern "C" void func_002FEAB0(void *arg0, int arg1) throw();
extern "C" void func_002FEB08(void *arg0) throw();
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_0030BB18(void *a0);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C15B0(s32 n);
extern "C" void func_005C1648(void *p);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

extern "C" void IO__read(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    Handle o;
    if (arg2 == 1) {
        Handle buf1;
        Handle *pb;
        Str s;
        Handle h;
        s32 n;
        char *b;
        s32 len;
        Str *ps;
        func_002FEB08(&o);
        pb = &buf1;
        func_002FC8C8(pb, arg3);
        n = func_002FE250(pb->p);
        b = func_005C15B0(n);
        {
            VObj *vo = (VObj *)o.p;
            VEntry *e = (VEntry *)((char *)vo->vtbl + 0x190);
            len = e->fn((char *)vo + e->delta, b, n);
        }
        ps = &s;
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, b, len);
        if (b != 0) {
            func_005C1648(b);
        }
        {
            Handle *ph = &h;
            func_00314B20(ph, ps);
            if ((void *)arg0 != (void *)ph) {
                s32 newVal = ph->p;
                s32 oldVal;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = *arg0;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                *arg0 = newVal;
            }
            func_00312318(ph, 2);
        }
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
        func_002FC870(pb, 2);
        func_002FEAB0(&o, 2);
    } else {
        func_0030BB18(&o);
        if ((void *)arg0 != (void *)&o) {
            s32 newVal = o.p;
            s32 oldVal;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00309378(&o, 2);
    }
}
