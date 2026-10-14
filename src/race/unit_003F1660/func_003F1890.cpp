/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Inner { char p[0x6C]; u8 b6c, b6d, b6e, b6f; float f70, f74; };
struct Car { char p0[0x14]; Inner s; char p1[0x56A - 0x14 - sizeof(Inner)]; u8 b56a; };
struct Entry { short adj; char pad[2]; int (*fn)(void *); };
struct Self { char p[0x10140]; char *tbl; };
extern u8 D_00622080, D_00622081;
extern float D_006220C8[], D_006220B0[];
extern u8 D_006220A8[];
extern "C" Car *func_0034C190(Self *);
extern "C" int func_00354E38(Car *);

static inline void setup(Inner *s, const u8 &v, int enabled) {
    s->b6d=v;
    s->f74=D_006220C8[v];
    s->f70=D_006220B0[v];
    s->b6f=D_006220A8[v];
    s->b6e=enabled;
}
extern "C" void func_003F1890(Self *self)
{
    Car *c = func_0034C190(self);
    Inner *s = &c->s;
    if (c->b56a < 2) setup(s,D_00622080,0);
    else setup(s,D_00622081,1);
    Entry *e = (Entry *)(self->tbl + 0x30);
    if (e->fn((char *)self + e->adj) != 0)
        s->b6e = 0;
    if (func_00354E38(c) == 0)
        s->b6f = -0x80;
    s->b6c = 0;
}
