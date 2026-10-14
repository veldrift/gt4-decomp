/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x, y, z; };

struct VEv { short d; short pad; Vec3 (*f)(void *, float); };
struct VT {
    char p0[0x38];
    VEv e38;
    VEv e40;
};
struct Obj { VT *vt; };
struct Self;

extern "C" {
void func_004524B8(Self *, int);
void func_004A53F8();
void func_004A5400();
void func_004A7844(float, float, float);
void func_004A7988(float);
void func_004A79B0(float);
void func_004A79D8(float);
}

static inline Vec3 vcallv(Obj *o, int off, float t) {
    VEv *e = (VEv *)((char *)o->vt + off);
    return e->f((char *)o + e->d, t);
}

extern "C" void func_00451EE0(Self *self, Obj *obj, int flag, float t) {
    if (flag != 0) {
        func_004A53F8();
        Vec3 v;
        v = vcallv(obj, 0x40, t);
        float *py = &v.y;
        float *pz = &v.z;
        func_004A7844(v.x, *py, *pz);
        v = vcallv(obj, 0x38, t);
        func_004A79B0(*py);
        func_004A7988(v.x);
        func_004A79D8(*pz);
    }
    func_004524B8(self, 1);
    if (flag != 0) {
        func_004A5400();
    }
}
