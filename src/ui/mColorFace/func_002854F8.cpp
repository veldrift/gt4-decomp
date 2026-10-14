/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct V4 { char pad[0x10]; };

struct VEntry2 {
    s16 delta;
    s16 index;
    void (*fn)(char *, V4 *);
};
struct VEntry5 {
    s16 delta;
    s16 index;
    void (*fn)(char *, s32, void *, s32, V4 *);
};

struct Blk {
    s32 a;
    s32 b;
    f32 w;
    s32 c;
    s32 d;
    f32 h;
    f32 w2;
    f32 h2;
    f32 &W(){ return w; }
    f32 &H(){ return h; }
    f32 &W2(){ return w2; }
    f32 &H2(){ return h2; }
};

struct Cont {
    char pad0[4];
    V4 *begin;
    V4 *end;
};

struct Vobj {
    char pad0[4];
    char *vt;
};

extern "C" void func_002030A0(V4 *p);
extern "C" V4 *func_002030E8(V4 *dst, V4 *src);
extern "C" void func_00203118(V4 *p, int n);
extern "C" void mWidget__getWindowSize(void *w, f32 *a, f32 *b);

extern "C" void func_002854F8(char *arg0, Vobj *arg1) {
    Blk blk;
    f32 wh[2];
    V4 arr[4];
    V4 *s6 = 0;
    V4 *pp;
    s32 i;
    Cont *c;
    s32 n;
    V4 *cc;
    mWidget__getWindowSize(arg0, &wh[0], &wh[1]);
    blk.W() = wh[0];
    blk.H() = wh[1];
    blk.W2() = wh[0];
    blk.H2() = wh[1];
    blk.a = 0;
    blk.b = 0;
    blk.c = 0;
    blk.d = 0;
    pp = arr;
    for (i = 3; i != -1; i--) {
        func_002030A0(pp);
        pp++;
    }
    c = (Cont *)(arg0 + 0xA0);
    n = (c->end - c->begin);
    if (n == 1) {
        s6 = 0;
        VEntry2 *e = (VEntry2 *)(arg1->vt + 0x198);
        e->fn((char *)arg1 + e->delta, c->begin);
    } else if (n == 4) {
        s6 = arr;
        func_002030E8(arr, c->begin);
        func_002030E8(arr + 1, c->begin + 1);
        func_002030E8(arr + 2, c->begin + 3);
        func_002030E8(arr + 3, c->begin + 2);
    }
    {
        VEntry5 *e = (VEntry5 *)(arg1->vt + 0x1B0);
        e->fn((char *)arg1 + e->delta, 4, &blk, 0, s6);
    }
    cc = arr + 4;
    if (arr != cc) {
        do {
            cc--;
            func_00203118(cc, 2);
        } while (arr != cc);
    }
}
