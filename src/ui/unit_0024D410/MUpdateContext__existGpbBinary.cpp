/* compiler: ee-gcc2.96-no-strict-aliasing */
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

struct VEntry18 {
    s16 delta;
    s16 index;
    Str (*fn)(void *);
};

struct VEntry1D0 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, Str *);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

extern "C" void func_0024E378(void *arg0, int arg1) throw();
extern "C" void func_0024E3D0(void *arg0, void *arg1) throw();
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" struct S00659988 *func_005C11A8(void);

extern "C" void MUpdateContext__existGpbBinary(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Handle h;
    Handle a;
    if (arg2 > 0) {
        Handle *pa = &a;
        func_0024E3D0(pa, arg1);
        {
            VObj *self = (VObj *)pa->p;
            VEntry1D0 *e = (VEntry1D0 *)(self->vtbl + 0x1D0);
            void *adj = (char *)self + e->delta;
            VObj *o = *arg3;
            VEntry18 *e2 = (VEntry18 *)(o->vtbl + 0x18);
            Str s = e2->fn((char *)o + e2->delta);
            Str *ps = &s;
            s32 r = e->fn(adj, ps);
            func_002FE278(&h, r != 0);
            if ((void *)arg0 != (void *)&h) {
                s32 newVal = h.p;
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
            func_002FC870(&h, 2);
            {
                Rep *q = (Rep *)(ps->p - 0x10);
                if (--q->ref == 0) {
                    s32 size = q->cap + 0x10;
                    func_00326798(q, size, 4, func_005C11A8()->name);
                }
            }
        }
        func_0024E378(pa, 2);
    }
}
