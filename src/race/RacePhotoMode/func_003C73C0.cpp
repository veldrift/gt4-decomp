struct VEntryW { short delta; short index; void (*fn)(void *, float *, float *); };
struct VObj { char pad[8]; char *vt; };
struct Inner { char pad[0x18]; void *m18; char pad2[0x2880 - 0x1C]; VObj *m2880; };
struct M60 { char pad[8]; Inner **m8; };
struct M6C { char pad[0x60]; M60 *m60; };
struct Obj { char pad[0x6C]; M6C *m6C; };
extern "C" float func_00344798(void *, float);
extern "C" float func_003447F8(void *, float);
extern "C" float func_00344828(void *, float);
extern "C" float func_003448B8(void *, float);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A70E8(void *, void *);
static inline float *at(float *p, int offset) { return (float *)((char *)p + offset); }
extern "C" void func_003C73C0(Obj *o)
{
    float bounds[8];
    float a[4], b[4];
    Inner *s = *o->m6C->m60->m8;
    void *c = s->m18;
    func_004A53F8();
    func_004A7454();
    VEntryW *e = (VEntryW *)(s->m2880->vt + 0x138);
    e->fn((char *)s->m2880 + e->delta, bounds, bounds + 4);
    func_004A5400();
    func_004A53F8();
    float x = func_00344798(c, 0.0f);
    float y = func_003447F8(c, 0.0f);
    func_004A7844(x, y, func_00344828(c, 0.0f));
    func_004A79B0(func_003448B8(c, 0.0f) * 0x1.ca5dc0p+5f);
    for (int i = 0; i < 8; ++i) {
        float *px = at(bounds, (i & 1) * 16);
        float *py = at(bounds, (i & 2) ? 20 : 4);
        float *pz = at(bounds, (i & 4) ? 24 : 8);
        for (int j = 0; j < 3; ++j) {
            int n = i ^ (1 << j);
            if (n >= i) {
                a[0] = *px;
                a[1] = *py;
                a[2] = *pz;
                b[0] = *at(bounds, (n & 1) * 16);
                b[1] = *at(bounds, (n & 2) ? 20 : 4);
                b[2] = *at(bounds, (n & 4) ? 24 : 8);
                func_004A70E8(a, b);
            }
        }
    }
    func_004A5400();
}
