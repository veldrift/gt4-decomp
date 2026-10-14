/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Vec4 { f32 x, y, z, w; };
struct VE { short delta; short index; void (*fn)(void *, Vec4 *, Vec4 *); };
struct Obj { int x; char *vt; };

extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" f32 func_002313E0(void *);
extern "C" f32 func_00231400(void *);
extern "C" void mWidget__getWindowSize(void *, f32 *, f32 *);
extern "C" void pglPushAttrib(s32);
extern "C" void func_004A2CB0(f32, f32, f32, f32);
extern "C" void func_001BE458(void *, void *);
extern "C" void func_004A5688(void);

extern "C" void mEyetoyFacePS2__virtual_70(void *self, Obj *arg1) {
    Vec4 r;
    Vec4 t;
    Vec4 *pt;
    f32 zero = 0.0f;
    mWidget__virtual_70(self, arg1, 0);
    r.x = zero;
    r.y = zero;
    r.z = zero;
    r.w = zero;
    r.x = func_002313E0(arg1);
    r.y = func_00231400(arg1);
    mWidget__getWindowSize(self, &r.z, &r.w);
    pglPushAttrib(0x80);
    pt = &t;
    pt->x = zero;
    t.y = zero;
    t.z = zero;
    t.w = zero;
    VE *e = (VE *)(arg1->vt + 0x1F8);
    e->fn((char *)arg1 + e->delta, pt, &r);
    func_004A2CB0((f32)(s32)r.x, (f32)(s32)r.y, (f32)(s32)r.z, (f32)(s32)r.w);
    func_001BE458(self, arg1);
    func_004A5688();
}
