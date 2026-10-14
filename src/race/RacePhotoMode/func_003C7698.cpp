struct VEntry { short delta; short index; void *(*fn)(void *, float *, float *); };
struct VEntryV { short delta; short index; void (*fn)(void *, float); };
struct VEntryW { short delta; short index; void (*fn)(void *, float *, float *); };
struct VEntry1 { short delta; short index; void *(*fn)(void *); };
struct VObj { char pad[8]; char *vt; };
struct VObj0 { char pad[0x64]; char *vt; };
struct Inner { char pad[0x18]; void *m18; char pad2[0x2880 - 0x1C]; VObj *m2880; };
struct M60 { char pad[8]; Inner **m8; };
struct M6C { char pad[0x60]; M60 *m60; };
struct Obj { char pad[0x64]; char *vt; char pad2[4]; M6C *m6C; };
struct Ret { char *vt; };
extern "C" float func_00344798(void *, float);
extern "C" float func_003447F8(void *, float);
extern "C" float func_00344828(void *, float);
extern "C" float func_00344858(void *, float);
extern "C" float func_00344888(void *, float);
extern "C" float func_003448B8(void *, float);
extern "C" float func_004575F8(void *, float *, float *);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A7988(float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A79D8(float);

extern "C" float func_003C7698(Obj *o)
{
    float v[4];
    float w[4];
    Inner *s = *o->m6C->m60->m8;
    void *c = s->m18;
    float r;
    func_004A53F8();
    func_004A7454();
    VEntry1 *e0 = (VEntry1 *)(o->vt + 0x4B0);
    Ret *q = (Ret *)e0->fn((char *)o + e0->delta);
    VEntryV *e = (VEntryV *)(q->vt + 0x18);
    e->fn((char *)q + e->delta, 0.0f);
    float x = func_00344798(c, 0.0f);
    float y = func_003447F8(c, 0.0f);
    func_004A7844(x, y, func_00344828(c, 0.0f));
    func_004A79B0(func_003448B8(c, 0.0f) * 0x1.ca5dc0p+5f);
    func_004A7988(func_00344858(c, 0.0f) * 0x1.ca5dc0p+5f);
    func_004A79D8(-(func_00344888(c, 0.0f) * 0x1.ca5dc0p+5f));
    VEntry1 *e1 = (VEntry1 *)(s->m2880->vt + 0x58);
    void *t = e1->fn((char *)s->m2880 + e1->delta);
    if (t) {
        r = func_004575F8(t, v, w);
    } else {
        VEntryW *e2 = (VEntryW *)(s->m2880->vt + 0x138);
        e2->fn((char *)s->m2880 + e2->delta, v, w);
        r = -w[2];
    }
    func_004A5400();
    return r;
}
