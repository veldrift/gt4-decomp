typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Blk8 {
    s32 a;
    s32 b;
};

typedef void (*F2)(s32, s32);

extern "C" void *func_004AE1F8(s32, s32);
extern "C" void func_004AED20(void *, void *);
extern "C" void *func_005C0FC8(s32, s32, s32, s32, s32, s32);

extern char D_0060B030[];
extern char D_0060AD40[];
extern char D_0044D540[];
extern char D_008463B0[];

extern "C" void func_0044CD10(s32 arg0, void *arg1) {
    char *v;
    char *r;
    char *t;
    Blk8 p;
    F2 f;

    v = (char *)func_004AE1F8(0, arg0);
    if (v != 0) {
        t = *(char **)(v + 0xA8);
        r = (char *)func_005C0FC8(*(s32 *)(t + 4), (s32)D_0060B030, 0,
                                  (s32)(v + *(s16 *)t), (s32)D_0060AD40, (s32)v);
        p.b = *(s32 *)((char *)arg1 + 4);
        p.a = (s32)D_0044D540;
        *(Blk8 *)(r + 0xC8) = p;
        *(s32 *)(r + 0x60) = 1;
        *(s32 *)(r + 0x74) = 0;
        p.a = 0;
        p.b = 0;
        *(Blk8 *)(r + 0x64) = p;
        *(Blk8 *)(r + 0x6C) = *(Blk8 *)arg1;
        func_004AED20((void *)D_008463B0, r);
    } else {
        f = *(F2 *)arg1;
        if (f != 0) {
            f(*(s32 *)((char *)arg1 + 4), 0);
        }
    }
}
