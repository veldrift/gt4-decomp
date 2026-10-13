typedef int s32;
typedef unsigned short u16;

struct E1 {
    s32 v;
};

struct E2 {
    char pad[0xC];
    s32 c;
};

struct Obj {
    char pad0[0x10];
    u16 count;
    char pad1[2];
    E1 **t14;
    E2 **t18;
};

extern char D_006AE550[];
extern char D_006AE558[];

extern "C" void func_0057DA20(int arg0, int arg1, ...);
extern "C" s32 func_005A3830(int arg0, int arg1);
extern "C" void func_005A4440(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" s32 func_005A31F0(void *arg0);

extern "C" void func_004918B0(Obj *arg0) {
    char buf[0x80];
    s32 i = 0;
    u16 cnt = arg0->count;

    if (cnt != 0) {
        do {
            s32 off = i << 2;
            E1 *a = *(E1 **)(off + (s32)arg0->t14);
            i += 1;
            if (a != 0) {
                func_0057DA20((int)buf, (int)D_006AE550, a->v);
                s32 n = (*(E2 **)(off + (s32)arg0->t18))->c;
                s32 r = func_005A3830((int)buf, (int)D_006AE558);
                func_005A4440(*(E2 **)(off + (s32)arg0->t18), 1, n, r);
                func_005A31F0((void *)r);
                cnt = arg0->count;
            }
        } while (i < (s32)cnt);
    }
}
