/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct VEnt {
    short adj;
    short pad;
    s32 (*fn)(void *);
};

struct VTab {
    char pad[0x20];
    VEnt e;
};

struct Inner {
    VTab *vt;
};

struct Blob {
    short d[0x57];
};

struct Node {
    char pad0[0x10];
    s32 v10;
    Blob b;
};

struct Src {
    char pad0[0x10];
    Inner *in;
    Blob b;
};

extern "C" void func_0029B9C8(void *, int);
extern "C" void func_0029BAF8(void *);
extern "C" void func_0029C9E8(void *, int);
extern "C" void func_0029CA40(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);

extern "C" void MGamePort__get_data(void **arg0) {
    Src *a[4];
    Node *b[4];
    func_0029CA40(a);
    Node **pb = b;
    func_0029BAF8(pb);
    Node *d = pb[0];
    Src *s = a[0];
    Inner *in = s->in;
    VEnt *e = &in->vt->e;
    d->v10 = e->fn((char *)in + e->adj);
    d->b = s->b;
    if (arg0 != (void **)pb) {
        Node *nv = pb[0];
        if (nv != 0)
            func_003285A8(nv);
        if (*arg0 != 0)
            func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_0029B9C8(pb, 2);
    func_0029C9E8(a, 2);
}
