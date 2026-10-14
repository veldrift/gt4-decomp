/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x, y, z, w; };
struct Mat { float m[16]; };
struct G { float a, b, c, d; };

struct Mid { char pad[0x18]; void *f18; };
struct Self { Mid *mid; };
struct Arg1;

extern G D_008465B0;
extern float D_008465C0;
extern char D_008465A0[];

extern "C" {
Arg1 *func_00450FE0(long) throw();
void func_00452418(Self *, float, float) throw();
void func_00452480(Self *) throw();
void ModelSet2__begin(void *, Arg1 *);
void ModelSet2__end(void *);
void ModelSet2___render(void *, int, Arg1 *);
void func_004A53F8();
void func_004A5400();
void func_004A60E0(float, float, float, float);
void func_004A6100(float, float, float, float);
void func_004A7698(void *);
void func_004A7A54();
void func_004A7AA8(void *, void *);
}

static inline void *getObj(Self *self) {
    void *obj = 0;
    if (self->mid != 0) obj = self->mid->f18;
    return obj;
}

extern "C" void func_004524B8(Self *self, int flag) {
    void *obj = getObj(self);
    Arg1 *a = func_00450FE0((long)self);
    if (obj == 0) return;
    if (a == 0) return;
    func_004A53F8();
    Vec4 v;
    func_004A7A54();
    func_004A7AA8(&v, D_008465A0);
    func_004A5400();
    Mat m;
    m.m[0] = 1.0f;
    m.m[4] = v.x;
    m.m[8] = 0;
    m.m[12] = 0;
    m.m[1] = 0;
    m.m[5] = 0;
    m.m[9] = 0;
    m.m[13] = 0;
    m.m[2] = 0;
    m.m[6] = v.z;
    m.m[10] = 1.0f;
    m.m[14] = 0;
    m.m[3] = 0;
    m.m[7] = 0;
    m.m[11] = 0;
    m.m[15] = 1.0f;
    if (flag != 0) {
        func_00452418(self, 0.005f, 0.02f);
    } else {
        func_004A53F8();
    }
    func_004A7698(&m);
    ModelSet2__begin(obj, a);
    func_004A6100(D_008465B0.a, D_008465B0.b, D_008465B0.c, 0.0f);
    func_004A60E0(1.0f, 1.0f, 1.0f, D_008465C0 * D_008465B0.d);
    ModelSet2___render(obj, 1, a);
    ModelSet2__end(obj);
    if (flag != 0) {
        func_00452480(self);
    } else {
        func_004A5400();
    }
}
