/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline float fsqrt(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

struct Self { int flags; float angle, x, y, z; };
struct Vec3 { float x, y, z; };
struct Obj { char p0[0x5AC]; int f5AC; };

extern "C" float func_00344798(void *, float);
extern "C" float func_003447F8(void *, float);
extern "C" float func_00344828(void *, float);
extern "C" float func_003F3708(void *) throw();
extern "C" float func_003F3720(void *) throw();
extern "C" float func_003F3738(void *) throw();
extern "C" void func_003F3748(void *) throw();
extern "C" void func_003FCE70(Self *) throw();
extern "C" void func_003FCEA8(Self *, Vec3 *, void *, float) throw();
extern "C" float func_003FE358(int, float *, int *) throw();
extern "C" int func_003FE7B0(int, float *, Vec3 *, float *, int *, float) throw();
extern "C" float func_00578598(int);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();

extern "C" unsigned func_003FFA48(int arg0, Obj *obj, int arg2, float *arg3, float *out, float ang)
{
    Vec3 pos;
    float v[3];
    float *pv = v;
    int s20;
    Self self;

    float a = func_003F3708(obj);
    float b = func_003F3720(obj);
    float c = func_003F3738(obj);
    func_003F3748(obj);
    float r1 = fsqrt(a * a + c * c);
    float r2 = fsqrt(b * b + c * c);
    float m = r1;
    if (m < r2) m = r2;
    if (m < c) m = c;
    float d = func_00578598(arg2) * 8.0f + m + 0.19999999f;
    Self *ps = &self;
    float rad = ang * 0x1.921fb4p+1f / 180.0f;
    float px = d * func_0057D2B8(rad);
    float pz = d * func_0057D1F0(rad);
    func_003FCE70(ps);
    self.angle = ang;
    pos.x = px;
    pos.y = 0x1.999998p-1f;
    pos.z = pz;
    func_003FCEA8(ps, &pos, obj, 0.0f);
    float t0 = func_00344798(obj, 0.0f);
    float t1 = func_003447F8(obj, 0.0f);
    float t2 = func_00344828(obj, 0.0f);
    *pv = t0;
    v[1] = t1;
    v[2] = t2;
    s20 = obj->f5AC;
    func_003FE7B0(arg0, pv, &pos, arg3, &s20, 0.15f);
    s20 = -1;
    *out = func_003FE358(arg0, arg3, &s20);
    return (unsigned)~s20 >> 31;
}
