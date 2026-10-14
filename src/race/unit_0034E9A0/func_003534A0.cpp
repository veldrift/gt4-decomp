/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[1]; unsigned char m1; };
struct Slot {
    char p0[0x48]; float m48;
    char p1[0x89 - 0x4C]; unsigned char m89;
    char p2[0xEC - 0x8A];
};
struct S104 {
    char p0[0x53C]; float m53C;
    char p1[0x550 - 0x540]; int m550;
    char p2[0x564 - 0x554]; float m564;
    char p3[0x5B0 - 0x568]; float m5B0;
};
struct Self { char p[0x10]; void *m10; char q[0x104 - 0x14]; S104 s; };
struct Sub { char p[0x40]; float tab[8]; };
struct Glob { char p[0xC]; Sub sub; };
extern Glob D_00620938;
extern "C" Obj *func_00359510(void *);
extern "C" float func_00359830(Glob *, float);

extern "C" void func_003534A0(Self *self) {
    S104 *s = &self->s;
    Obj *o = func_00359510(self->m10);
    s->m564 = 0.0f;
    s->m550 = 0;
    s->m5B0 = 0.0f;
    int n = o->m1;
    float total = s->m564;
    if (n != 0) {
        Slot *p = (Slot *)((char *)self + 0x164);
        do {
            total += p->m48 * D_00620938.sub.tab[p->m89];
            p++;
            n--;
        } while (n != 0);
    }
    float x = s->m53C;
    if (x > 0.0f) {
        float r = -func_00359830(&D_00620938, x);
        s->m5B0 = r * total;
    } else {
        float r = func_00359830(&D_00620938, -x);
        s->m5B0 = r * total;
    }
}
