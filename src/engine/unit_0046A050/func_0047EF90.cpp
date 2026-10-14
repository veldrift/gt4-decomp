struct Seg { char pad[0x70]; char *tbl; };
struct Item { short idx; unsigned short flag; };
struct Pt { int a, b; };
struct Ent { float v; unsigned char buf[4]; };
struct Ctx {
    char pad[0x6E14];
    void *canvas;
    char sub[8];
    Seg *seg;
    int pad2;
    float f28;
    float f2c;
};
extern "C" void func_00472E88(void *, void *, void *);
extern "C" void func_00473070(void *, void *, int, int, float);
extern "C" void func_00473380(void *, unsigned);
extern "C" unsigned func_0047E658(const unsigned char *, const unsigned char *);
extern "C" int func_0047F088(float, Item *, Ctx *, int);

extern "C" void func_0047EF90(Item *it, Ctx *c) {
    int i;
    if (it->idx >= 0) {
        int n = func_0047F088(c->f28, it, c, 0x400);
        Ent *e = (Ent *)(c->seg->tbl + it->idx * 8);
        func_00473380(c->canvas, func_0047E658((unsigned char *)c->sub, e->buf));
        if (e->v * c->f2c < 1.1f) {
            Pt *p = (Pt *)c;
            i = 0;
            int m = n - 1;
            if (m > 0) {
                do {
                    Pt *q = p + 1;
                    func_00472E88(c->canvas, p, q);
                    i++;
                    p = q;
                } while (i < m);
            }
        } else {
            func_00473070(c->canvas, c, n, it->flag != 0, *(volatile float *)e);
        }
    }
}
