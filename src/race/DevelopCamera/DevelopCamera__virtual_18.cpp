typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj;

struct Obj00373630 {
    VEntry *vtbl;
    char pad[0x9BC - 4];
    void *arg;
    char pad9C0[0xA04 - 0x9C0];
    float result;
};

struct Result {
    VEntry *vtbl;
    char pad[0x90 - 4];
    float (*fn)(void *, void *);
};

extern "C" float DevelopCamera__virtual_18(struct Obj00373630 *self) {
    VEntry *e = &self->vtbl[27];
    struct Result *r = (struct Result *)(((s32 (*)(void *, void *))e->fn)((char *)self + e->delta, self->arg));
    if (r == 0) return self->result;
    VEntry *e2 = &r->vtbl[18];
    return ((float (*)(void *, void *))e2->fn)((char *)r + e2->delta, (char *)self + 0x9C0);
}
