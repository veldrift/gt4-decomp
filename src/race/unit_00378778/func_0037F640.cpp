/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Inner { char pad[0x18]; void *unk18; };
struct Obj { char pad[0x10]; Inner *unk10; };

extern "C" f32 func_003F3708(void *);
extern "C" f32 func_003F3720(void *);
extern "C" float func_003F3738(void *);
extern "C" f32 func_003F3748(void *);
extern "C" void func_003FCE70(char *);
extern "C" void func_003FD0A0(f32 *, f32 *, void *, f32);
extern "C" void func_005F5040(float *, float *);
extern "C" void func_005F5230(f32 *, s32);

extern "C" s32 func_0037F640(Obj *arg0, s32 arg1, f32 *m, f32 *v, f32 t) {
    f32 p[3];
    char buf[0x20];
    f32 *px = &p[0];
    f32 *py = &p[1];
    f32 *pz = &p[2];
    s32 ok = 1;
    void *o = arg0->unk10->unk18;
    *px = -m[2];
    *py = -m[6];
    *pz = -m[10];
    *px *= t;
    *py *= t;
    *pz *= t;
    func_005F5230(p, arg1);
    func_003FCE70(buf);
    func_003FD0A0((f32 *)buf, p, o, 0.0f);
    func_005F5040(p, v);
    f32 a = func_003F3708(o) * 1.05f;
    f32 b = func_003F3720(o) * 1.05f;
    f32 c = func_003F3738(o) * 1.05f * 0.5f;
    f32 d = func_003F3748(o) * 1.05f;
    if (*pz < -a)
        ok = 0;
    if (b < *pz)
        ok = 0;
    if (*px < -c)
        ok = 0;
    if (c < *px)
        ok = 0;
    if (*py < -0x1.333332p-2f)
        ok = 0;
    if (d < *py)
        ok = 0;
    return ok;
}
