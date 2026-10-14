/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Handle {
    s32 p;
    char pad[0xC];
};

struct VEntry58 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntry1E0 {
    s16 delta;
    s16 index;
    float (*fn)(void *, s32, s32);
};

struct VObj {
    char pad[4];
    char *vtbl;
};

static inline s32 vcall_58(VObj *o) {
    VEntry58 *e = (VEntry58 *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_0024E378(void *arg0, int arg1) throw();
extern "C" void func_0024E3D0(void *arg0, void *arg1) throw();
extern "C" void func_002F7B68(void *arg0, int arg1);
extern "C" void func_002F9360(void *arg0, float fparg0);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MUpdateContext__getPadAnalogChannel(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Handle a;
    VObj **args = arg3;
    s32 *dst = arg0;
    if (arg2 == 2) {
        Handle h;
        Handle *ph;
        func_0024E3D0(&a, arg1);
        {
            VObj *self = (VObj *)a.p;
            VEntry1E0 *e = (VEntry1E0 *)(self->vtbl + 0x1E0);
            void *adj = (char *)self + e->delta;
            s32 x = vcall_58(args[0]);
            s32 y = vcall_58(args[1]);
            float f = e->fn(adj, x, y);
            ph = &h;
            func_002F9360(ph, f);
        }
        if ((void *)dst != (void *)ph) {
            s32 newVal = ph->p;
            s32 oldVal;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *dst;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *dst = newVal;
        }
        func_002F7B68(ph, 2);
        func_0024E378(&a, 2);
    }
}
