typedef int s32;

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

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry_18 {
    short delta;
    short index;
    void (*fn)(void *, void *);
};

struct VEntry_58 {
    short delta;
    short index;
    s32 (*fn)(void *);
};

extern "C" void func_002BAAE0(void *arg0, int arg1);
extern "C" void func_002BAB38(void *arg0, void *arg1);
extern "C" void func_002BE800(void *self, Str *src);
extern "C" void func_002BE908(Obj *arg0, s32 arg1);
extern "C" void func_002BE938(Obj *arg0, s32 arg1);
extern "C" void func_002BE968(Obj *arg0, s32 arg1);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void MModelFace__setModelSetPath(void *arg0, void *arg1, s32 arg2, Obj **arg3) {
    s32 buf[4];
    Str s;
    Str *ps;
    if (arg2 == 4) {
        func_002BAB38(buf, arg1);
        ps = &s;
        {
            s32 h = buf[0];
            Obj *o = arg3[0];
            VEntry_18 *e = (VEntry_18 *)(o->vtbl + 0x18);
            e->fn(ps, (char *)o + e->delta);
            func_002BE800((void *)h, ps);
        }
        {
            Rep *q = (Rep *)(ps->p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
        {
            Obj *o1 = arg3[1];
            s32 hv = buf[0];
            VEntry_58 *e1 = (VEntry_58 *)(o1->vtbl + 0x58);
            func_002BE908((Obj *)hv, e1->fn((char *)o1 + e1->delta) != 0);
        }
        {
            Obj *o2 = arg3[2];
            s32 hv2 = buf[0];
            VEntry_58 *e2 = (VEntry_58 *)(o2->vtbl + 0x58);
            func_002BE938((Obj *)hv2, e2->fn((char *)o2 + e2->delta) != 0);
        }
        {
            Obj *o3 = arg3[3];
            s32 hv3 = buf[0];
            VEntry_58 *e3 = (VEntry_58 *)(o3->vtbl + 0x58);
            func_002BE968((Obj *)hv3, e3->fn((char *)o3 + e3->delta) != 0);
        }
        func_002BAAE0(buf, 2);
    }
}
