/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct V4;
struct Tgt { char pad[0x54]; s32 f54; void set(const V4 &, float); };
struct H { Tgt *o; char pad[0xC]; };
struct W { void *v; char pad[0xC]; };
struct V4 { float a, b, c, d; V4(float x, float y, float z, float w) : a(x), b(y), c(z), d(w) {} };

extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_0025B500(void *, int, int, void *, void *);
extern "C" void func_002C0388(void *, int) throw();
extern "C" void func_002C03E0(void *, void *) throw();
extern "C" void func_002C16E0(void *, void *);
extern "C" void func_002C1718(void *, void *, float);
extern "C" void func_002C1750(void *);
extern "C" void func_002F7B68(void *, int);
extern "C" void func_002F7BC0(void *, void *);
extern "C" float func_002F9158(void *);

inline void Tgt::set(const V4 &v, float f) { func_002C1718(this, (void *)&v, f); }

extern "C" void MMoveActor__global_008390E8(void *self, void *arg1, s32 n, char *args) {
    if (n >= 3) {
        H h;
        W w1;
        W w2;
        W w3;
        float out[2];
        W w4;
        float f21 = 1.0f;
        func_002C03E0(&h, arg1);
        W *p1 = &w1;
        func_00255110(p1, args);
        W *p2 = &w2;
        func_002F7BC0(p2, args + 4);
        W *p3 = &w3;
        func_002F7BC0(p3, args + 8);
        func_0025B500(p1->v, 0, 0, &out[0], &out[1]);
        W *p4 = &w4;
        if (n >= 4) {
            func_002F7BC0(p4, args + 0xC);
            f21 = func_002F9158(p4->v);
            func_002F7B68(p4, 2);
        }
        func_002C16E0(h.o, p1->v);
        h.o->set(V4(func_002F9158(p2->v), func_002F9158(p3->v), out[0], out[1]), f21);
        func_002C1750(h.o);
        h.o->f54 = 0;
        func_002F7B68(p3, 2);
        func_002F7B68(p2, 2);
        func_002550B8(p1, 2);
        func_002C0388(&h, 2);
    }
}
