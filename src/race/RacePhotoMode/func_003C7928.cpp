static inline float frsq(float a, float b) {
    float r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
struct VEntry1 { short delta; short index; void *(*fn)(void *); };
struct VEntryF { short delta; short index; void (*fn)(void *, float); };
struct Obj { char pad[0x64]; char *vt; };
struct Ret { char *vt; };
extern "C" float func_003C7698(void *) throw();
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7550(float *);
extern "C" float func_003C7928(Obj *o, float p0, float p1, float p2, float p3)
{
    float v[16];
    func_004A53F8();
    func_004A7454();
    VEntry1 *e0 = (VEntry1 *)(o->vt + 0x4B0);
    Ret *q = (Ret *)e0->fn((char *)o + e0->delta);
    VEntryF *e = (VEntryF *)(q->vt + 0x10);
    e->fn((char *)q + e->delta, 0.0f);
    func_004A7550(v);
    func_004A5400();
    float r = frsq(p1 * 0x1.0624dcp-10f, p2 * p2 + 1.0f);
    float t21 = p3 * (r + r);
    float t20 = r * 0.5f * v[5];
    float c = func_003C7698(o);
    float sq = t20 * t20;
    float res = (c * ((t21 * p0 * t20) - sq)) / ((c * t21 * p0) - sq);
    return res < c ? c : res;
}
