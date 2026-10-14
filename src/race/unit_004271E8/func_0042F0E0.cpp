typedef long s64;
struct Ent { s64 a; s64 b; };
struct Ring { int head; int p4; int count; int pC; Ent e[0xB6A]; };
struct Obj { int p0; int p4; Ring r; int pad[2]; int cnt; int flag; };
extern "C" void func_006009F0(Ring *, int);
extern "C" void func_00600A18(Ring *, int);

static inline int remaining(Ring *r) { return 0xB6A - r->count; }

extern "C" void func_0042F0E0(Obj *o, Ent *src) {
    Ring *r2 = &o->r;
    if (remaining(r2) == 0) func_006009F0(r2, 1);
    int one = 1;
    int off = r2->head * 16;
    Ent *d = (Ent *)((char *)r2 + off);
    d += 1;
    *d = *src;
    func_00600A18(r2, 1);
    o->cnt++;
    o->flag = one;
}
