struct VEntry { short delta; short index; void *(*fn)(void *, float *, float *); };
struct VEntryV { short delta; short index; void (*fn)(void *, float *, float *); };
struct VEntry1 { short delta; short index; void *(*fn)(void *); };
struct VObj { char pad[8]; char *vt; };
struct Obj { char pad[0x18]; void *m18; char pad2[0x2880 - 0x1C]; VObj *m2880; };
extern "C" float func_00344798(void *, float);
extern "C" float func_003447F8(void *, float);
extern "C" float func_00344828(void *, float);
extern "C" float func_00344858(void *, float);
extern "C" float func_00344888(void *, float);
extern "C" float func_003448B8(void *, float);
extern "C" float func_004575F8(void *, float *, float *);
extern "C" void func_004A0690(void);
extern "C" void func_004A06F0(void);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7698(void *);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A7988(float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A79D8(float);

static inline void vc2(VObj *o, float *a, float *b) { VEntryV *e = (VEntryV *)(o->vt + 0x138); e->fn((char *)o + e->delta, a, b); }
extern "C" float func_003FD260(Obj *o, void *a)
{
    float v[4];
    float w[4];
    void *s = o->m18;
    float r;
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    func_004A7698(a);
    float x = func_00344798(s, 0.0f);
    float y = func_003447F8(s, 0.0f);
    func_004A7844(x, y, func_00344828(s, 0.0f));
    func_004A79B0(func_003448B8(s, 0.0f) * 0x1.ca5dc0p+5f);
    func_004A7988(func_00344858(s, 0.0f) * 0x1.ca5dc0p+5f);
    func_004A79D8(-(func_00344888(s, 0.0f) * 0x1.ca5dc0p+5f));
    VEntry1 *e = (VEntry1 *)(o->m2880->vt + 0x58);
    void *t = e->fn((char *)o->m2880 + e->delta);
    if (t) {
        r = func_004575F8(t, v, w);
    } else {
        vc2(o->m2880, v, w);
        r = -w[2];
    }
    func_004A5400();
    func_004A06F0();
    return r;
}
