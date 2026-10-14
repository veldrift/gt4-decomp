typedef unsigned char u8;
struct Item { char pad[0x14]; };
struct Vec { Item *begin; int size; };
struct A { short f0; u8 f2; u8 pad3; Vec v; };
struct Ent { char pad[0x68]; char *f68; };
struct Pt { char pad[8]; };
struct Big {
    char pad0[0x2000];
    char s2000[0x6E14 - 0x2000];
    int f6E14;
    char pad6E18[8];
    Ent *f6E20;
    char pad6E24[4];
    float f6E28;
};
extern "C" void func_00478BE0(void *, Big *);
extern "C" int func_0047F088(Item *, Pt *, int, float);
extern "C" void func_004854B0(void *, int, int);
extern "C" void func_00485558(void *);
extern "C" void func_00607640(void *);
extern "C" void func_00607758(void *, void *, void *);
extern "C" int func_00607850(void *, void *, int);

static inline Item *vbeg(Vec *v) { return v->begin; }
static inline Item *vend(Vec *v) { return v->begin + v->size; }

extern "C" void func_0047EC98(A *a, Big *b) {
    char sp[0x10];
    char *s7 = b->s2000;
    func_00607640(s7);
    int fp = 0x400;
    Vec *vv = &a->v;
    Item *end = vend(vv);
    Item *it = vbeg(vv);
    Pt *p = (Pt *)b;
    while (it != end) {
        int n = func_0047F088(it, p, fp, b->f6E28);
        for (int k = 0; k < n - 1; k++)
            func_00607758(s7, &p[k], &p[k + 1]);
        it++;
        p += n;
        fp -= n;
    }
    Ent *e = b->f6E20;
    func_00478BE0(e->f68 + a->f0 * 8, b);
    func_004854B0(sp, b->f6E14, *(int *)(s7 + 0x3000) + a->f2 * 2 - 2);
    func_00607850(s7, sp, 0x4000);
    func_00485558(sp);
}
