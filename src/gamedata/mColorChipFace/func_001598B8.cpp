/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct VEntry {
    short delta;
    short index;
    void *fn;
};
#define VCALL0(R, o, off) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *))e_->fn)((char *)(o) + e_->delta); })
#define VCALL1(R, o, off, a) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *, ...))e_->fn)((char *)(o) + e_->delta, a); })
#define VCALL4(o, off, a, b, c, d) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((void (*)(void *, s32, void *, void *, s32))e_->fn)((char *)(o) + e_->delta, a, b, c, d); })

struct Pt {
    f32 x, y;
    inline void set(float a,float b) { x=a; y=b; }
    inline void set(int a,int b) { *(int *)&x=a; *(int *)&y=b; }
    inline void set(float a,int b) { x=a; *(int *)&y=b; }
    inline void set(int a,float b) { *(int *)&x=a; y=b; }
};
struct Quad {
    Pt p[4];
};
extern "C" void *func_002030A0(void *);
extern "C" void func_00203118(void *, int);
extern "C" void mWidget__getWindowSize(void *, f32 *, f32 *);

extern "C" void func_001598B8(void *self, void *arg1, void *arg2) {
    f32 sx, sy;
    if (arg2 != 0) {
        if (VCALL0(s32, arg2, 0x58) != 0) {
            mWidget__getWindowSize(self, &sx, &sy);
            Quad a;
            Pt *pa = a.p;
            pa[0].set(0,0);
            pa[1].set(sx,0);
            pa[2].set(0,sy);
            pa[3].set(sx,sy);
            f32 w = VCALL0(f32, arg2, 0x70);
            f32 h = VCALL0(f32, arg2, 0x78);
            Quad b;
            Pt *pb = b.p;
            pb[0].x = 0;
            pb[0].y = 0;
            pb[1].x = w;
            pb[1].y = 0;
            pb[2].x = 0;
            pb[2].y = h;
            pb[3].x = w;
            pb[3].y = h;
            char v[16];
            func_002030A0(v);
            VCALL1(void, arg1, 0x198, v);
            func_00203118(v, 2);
            VCALL0(void, arg1, 0x1D0);
            VCALL1(void, arg1, 0x1C0, 1);
            VCALL0(void, arg2, 0x68);
            VCALL4(arg1, 0x1B0, 4, pa, pb, 0);
            VCALL0(void, arg1, 0x1C8);
            VCALL0(void, arg1, 0x1D8);
        }
    }
}
