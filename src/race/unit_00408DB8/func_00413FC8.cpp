/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj {
    s32 p0;
    char pad4[4];
    s32 p8;
    s32 pC;
    char pad10[8];
    s32 p18;
    char pad1c[0x110 - 0x1c];
    f32 dt;
};

struct Spring {
    f32 acc;
    f32 *vel;
    f32 *pos;
    Spring(f32 *v, f32 *p, f32 a) { acc = a; vel = v; pos = p; }
    void run(f32 target, f32 dt) {
        f32 *vl = vel;
        f32 *ps = pos;
        acc += (target - *ps) * 100.0f;
        acc -= *vl * 20.0f;
        f32 v = *vl + acc * dt;
        *vl = v;
        f32 lim = 0x1.921fb4p+0f;
        if (v * v > 2.4674008f) {
            if (v > 0.0f) {
                *vl = lim;
            } else {
                *vl = -lim;
            }
        }
        *pos += *vel * dt;
        acc = 0.0f;
    }
};

extern "C" f32 *func_00385B48(s32) ;
extern "C" s32 *func_00385B58(s32);
extern "C" f32 *func_00385B68(s32);
extern "C" s32 *func_00385B98(s32);
extern "C" s32 *func_00385FB0(s32);
extern "C" f32 *func_00386248(s32);
extern "C" s32 func_0040CCD8(s32) throw();
extern "C" f32 func_00413F68(s32) throw() __attribute__((const));

extern "C" void func_00413FC8(Obj *o) {
    *func_00385B48(o->p0) = 0.5f;
    *func_00385B98(o->p0) = 0;
    *func_00385B58(o->p0) = 0;
    f32 target = func_00413F68(func_0040CCD8(o->p18));
    if (*func_00385FB0(o->pC) == 1) {
        *func_00385B68(o->p0) = target;
    }
    f32 *vel = func_00386248(o->p8);
    f32 *pos = func_00385B68(o->p0);
    Spring sp(vel, pos, 0.0f);
    sp.run(target, o->dt);
}
