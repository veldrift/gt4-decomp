struct Entry { char pad[0xA]; short w; };
struct Table { char pad[0x50]; char *items; };
struct Ctx { char pad[0x6E20]; Table *t; };
struct S { char pad[0x14]; short idx; };
extern "C" Entry *func_004797D0(void *, unsigned short) throw();
extern "C" void func_0047EB20(Entry *, Ctx *);
extern "C" void func_004A7844(float, float, float);

extern "C" float func_0047A138(S *s, Ctx *c, char **pp) {
    float sum = 0.0f;
    char *tab = c->t->items + s->idx * 0x18;
    for (;;) {
        char *p = *pp;
        char ch = *p;
        if (ch == 0 || ch == 13) { *pp = p - 1; return sum; }
        *pp = p + 1;
        Entry *e = func_004797D0(tab, ch);
        if (e) {
            func_0047EB20(e, c);
            float f = (float)e->w * 0.05f;
            sum += f;
            func_004A7844(f, 0.0f, 0.0f);
        }
    }
}
