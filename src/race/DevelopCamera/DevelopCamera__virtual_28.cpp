struct VEntry0 {
    short delta;
    short index;
    void *(*fn)(void *, int);
};
struct VEntry1 {
    short delta;
    short index;
    float (*fn)(void *, float);
};
struct Inner { VEntry1 *vtbl; };
struct Obj { VEntry0 *vtbl; char pad4[0x9B8]; int unk9BC; };
extern "C" float DevelopCamera__virtual_28(Obj *self, int arg)
{
    VEntry0 *e = self->vtbl + 27;
    Inner *v = (Inner *)(e->fn((char *)self + e->delta, self->unk9BC));
    float r = 0.0f;
    if (v) {
        VEntry1 *e2 = &v->vtbl[5];
        r = e2->fn((char *)v + e2->delta, (float)arg);
    }
    return r;
}
