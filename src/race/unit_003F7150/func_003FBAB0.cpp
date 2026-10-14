/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x, y, z; };
struct Elem { Vec3 a, b; int f18, f1c, f20, f24, f28; };
struct Tail { float c; int pad; unsigned d; };
struct Ent { float a, b, c; int pad; unsigned d; };
struct List { int n; int p4; int *items; };
struct Src { char p[0x60]; int l; };
struct Obj {
    Src *src; int v4; int v8; short vC; int v10;
    Elem e[2];
    int v6c; int v70; float v74; Ent t[3];
    char curve[1];
};
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_0036F710(void *, float, float, float, float);
extern "C" void func_003FC108(Obj *);

extern "C" void func_003FBAB0(Obj *o, Src *s, int a2, int idx)
{
    o->v4 = a2;
    o->src = s;
    o->v8 = 0;
    o->vC = idx;
    o->v10 = 0;
    if (s) {
        int n = ((int *)s->l)[0];
        if (idx < 0) idx = 0;
        o->v8 = 1;
        if (idx >= n) idx = n - 1;
        int it = ((int *)((int *)s->l)[2])[idx];
        o->vC = idx;
        o->v10 = it;
    }
    char *w8;
    for (int k = 0; k < 2; k++) {
        func_005A48D8(&o->e[k].a, 0, 12);
        func_005A48D8(&o->e[k].b, 0, 12);
        o->e[k].f18 = 0;
        o->e[k].f1c = 0;
        o->e[k].f20 = 0;
        w8 = (char *)&o->v8;
        o->e[k].f24 = 0;
        o->e[k].f28 = 0;
    }
    o->v6c = 0;
    o->v70 = 0;
    o->v74 = 1.0f;
    func_0036F710(o->curve, 1.0f, 0.04f, 0.01f, 0x1.16872ap-5f);
    unsigned mask = ~0xFFu;
    float *pa = (float *)(w8 + 0x70);
    Tail *q = (Tail *)((char *)o + 0x80);
    int c = 2;
    do {
        *pa = 0;
        pa += 5;
        c--;
        q->d &= mask;
        q = (Tail *)((char *)q + 0x14);
    } while (c >= 0);
    func_003FC108(o);
}
