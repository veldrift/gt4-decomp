/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef signed char s8;

struct S_0028EA10;

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VE58 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VE60 {
    s16 delta;
    s16 index;
    float (*fn)(void *);
};

struct Dst {
    char pad0[0x20];
    s16 a20;
    s16 pad22;
    s32 b24;
    float c28;
    float d2c;
};

extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" void func_002550B8(void *arg0, int arg1);
extern "C" void func_00255110(void *arg0, void *arg1);
extern "C" void func_0027F320(void *arg0, int arg1);
extern "C" void func_0027F378(void *arg0, void *arg1);
extern "C" void func_0028EA10(S_0028EA10 *arg0, s32 arg1);
extern "C" void func_0028EA70(s8 *arg0, s32 arg1);

extern "C" void MButtonEvent__global_008333D8(void *arg0, void *arg1, s32 arg2, Obj **args) {
    s32 buf[4];
    s32 p1[4];
    s32 p2[4];
    if (arg2 == 6) {
        func_0027F378(buf, arg1);
        func_0022AD20(p1, args);
        func_00255110(p2, (char *)args + 4);
        {
            s32 *q1 = p1;
            func_0028EA10((S_0028EA10 *)buf[0], q1[0]);
        }
        {
            s32 *q2 = p2;
            func_0028EA70((s8 *)buf[0], q2[0]);
        }
        {
            Obj *o = args[2];
            Dst *h = (Dst *)buf[0];
            VE58 *e = (VE58 *)(o->vtbl + 0x58);
            h->a20 = e->fn((char *)o + e->delta);
        }
        {
            Obj *o = args[3];
            Dst *h = (Dst *)buf[0];
            VE58 *e = (VE58 *)(o->vtbl + 0x58);
            h->b24 = e->fn((char *)o + e->delta);
        }
        {
            Obj *o = args[4];
            Dst *h = (Dst *)buf[0];
            VE60 *e = (VE60 *)(o->vtbl + 0x60);
            h->c28 = e->fn((char *)o + e->delta);
        }
        {
            Obj *o = args[5];
            Dst *h = (Dst *)buf[0];
            VE60 *e = (VE60 *)(o->vtbl + 0x60);
            h->d2c = e->fn((char *)o + e->delta);
        }
        func_002550B8(p2, 2);
        func_0022ACC8(p1, 2);
        func_0027F320(buf, 2);
    }
}
