/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct VT1 { s16 off; s16 pad; void (*fn)(void *, void *); };
struct VT2 { s16 off; s16 pad; void (*fn)(void *, s32, void *, s32, s32); };
struct Obj { char pad[4]; char *vt; };
struct W { char pad[0xC0]; s32 c0; };
struct Point { float x, y; inline void set(float a, float b) { x=a; y=b; }
inline void set(int a, int b) { *(int *)&x=a; *(int *)&y=b; }
inline void set(float a, int b) { x=a; *(int *)&y=b; }
inline void set(int a, float b) { *(int *)&x=a; y=b; } };
struct R { Point p[4]; };

extern "C" int func_00202C48(void *, s32);
extern "C" void func_00203118(void *, int);
extern "C" void mWidget__getWindowSize(void *, void *, void *);

extern "C" void func_00158CC8(W *arg0, Obj *arg1) {
    f32 sz[4];
    R r;
    s32 b[4];
    mWidget__getWindowSize(arg0, &sz[0], &sz[1]);
    R *q = &r;
    q->p[0].set(0,0);
    q->p[1].set(sz[0],0);
    q->p[2].set(0,sz[1]);
    q->p[3].set(sz[0],sz[1]);
    func_00202C48(b, arg0->c0);
    VT1 *v1 = (VT1 *)(arg1->vt + 0x198);
    v1->fn((char *)arg1 + v1->off, b);
    VT2 *v2 = (VT2 *)(arg1->vt + 0x1B0);
    v2->fn((char *)arg1 + v2->off, 4, q, 0, 0);
    func_00203118(b, 2);
}
