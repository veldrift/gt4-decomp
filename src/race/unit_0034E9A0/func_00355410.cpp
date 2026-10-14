/* compiler: ee-gcc2.96-nogcse */
struct D134 { char p[0xCC]; unsigned short mCC; };
struct E {
    char p0[0x4E8]; float m4E8, m4EC; char p1[0x4FA - 0x4F0]; short m4FA; float m4FC;
    char p4[0x521 - 0x500]; unsigned char m521;
};
struct Self { char p[0x10]; char *m10; char q[0x104 - 0x14]; E e; };
extern "C" float func_0034EA68(D134 *, float, float);

extern "C" float func_00355410(Self *self, float x) {
    E *e = &self->e;
    float v = 0.0f;
    D134 *d = (D134 *)(self->m10 + 0x134);
    if (e->m521 == 0) {
        if (e->m4FA >= (int)d->mCC) e->m521 = 1;
    } else if (e->m4FA < (int)d->mCC - 0x1F4) {
        e->m521 = 0;
    }
    float f1 = e->m4EC;
    if (e->m521 == 0) v = x * (e->m4E8 + f1);
    return func_0034EA68(d, v - f1, e->m4FC);
}
