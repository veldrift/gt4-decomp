typedef int s32;
typedef short s16;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32, s32, s32);
};

extern "C" void func_00204D30(void *arg0, int arg1);
extern "C" void func_00204D88(void *arg0, void *arg1);
extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);

extern "C" void func_00205530(void *arg0, void *arg1, s32 n, Obj **args) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 small = n < 3;
    if (n == 2) {
        s32 *p1;
        s32 *p2;
        func_00204D88(buf0, arg1);
        p1 = buf1;
        func_00255110(p1, args);
        p2 = buf2;
        func_00255110(p2, (char *)args + 4);
        {
            Obj *o = (Obj *)buf0[0];
            VEntry *e = (VEntry *)(o->vtbl + 0x328);
            e->fn((char *)o + e->delta, 0, p1[0], p2[0]);
        }
        func_002550B8(p2, 2);
        func_002550B8(p1, 2);
        func_00204D30(buf0, 2);
    } else if (!small) {
        s32 *p3;
        s32 *p4;
        s32 *p5;
        func_00204D88(buf0, arg1);
        p3 = buf3;
        func_0022AD20(p3, args);
        p4 = buf4;
        func_00255110(p4, (char *)args + 4);
        p5 = buf5;
        func_00255110(p5, (char *)args + 8);
        {
            Obj *o = (Obj *)buf0[0];
            VEntry *e = (VEntry *)(o->vtbl + 0x328);
            e->fn((char *)o + e->delta, p3[0], p4[0], p5[0]);
        }
        func_002550B8(p5, 2);
        func_002550B8(p4, 2);
        func_0022ACC8(p3, 2);
        func_00204D30(buf0, 2);
    }
}
