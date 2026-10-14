struct Entry { char pad0[8]; unsigned short lim; unsigned short sub; char pad[0x24 - 0xC + 4]; };
struct Ctx;
extern "C" void func_00474698(Ctx *) throw();
extern "C" void func_00474750(Ctx *);
extern "C" void func_004747B8(Ctx *);
extern "C" void func_00474B50(Entry *, Ctx *, int, float);

extern "C" short *func_00474828(Entry **tab, Ctx *c, int lim, short *cur, short *end, int x, float t) {
    while (cur != end) {
        Entry *e = *tab + *cur;
        if (lim < e->lim) return cur;
        if (e->sub != 0) func_00474698(c);
        func_00474B50(e, c, x, t);
        if (e->sub != 0) {
            func_00474750(c);
            cur = func_00474828(tab, c, e->sub, cur + 1, end, x, t) - 1;
            func_004747B8(c);
        }
        cur++;
    }
    return end;
}
