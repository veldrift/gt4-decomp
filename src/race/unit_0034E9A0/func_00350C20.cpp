/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Loc { float x, y, z; int w; float out; char pad[0x30 - 0x14]; unsigned char flag; };
struct Ctx { char p[0xCBD8]; void *mCBD8; };
struct S104 { char p0[8]; float m8; char p1[0x624 - 0xC]; float m624; int m628; };
struct Self {
    char p0[4]; Ctx *m4; char p1[0x104 - 8]; S104 s;
};
struct V3 { float x, y, z; };
extern "C" void func_00395760(void *, Loc *);

extern "C" void func_00350C20(Self *self) {
    S104 *s = &self->s;
    V3 *v = (V3 *)((char *)self + 0x720);
    Ctx *c = self->m4;
    Loc l;
    s->m624 = s->m8;
    l.w = s->m628;
    l.x = v->x;
    l.y = v->z;
    l.z = -v->y;
    func_00395760(c->mCBD8, &l);
    unsigned char f1 = l.flag;
    if (f1) {
        l.w = *(int *)((char *)self + 0x5AC);
        func_00395760(c->mCBD8, &l);
    }
    if (!l.flag) {
        s->m624 = l.out;
        s->m628 = l.w;
    } else {
        s->m628 = -s->m628;
    }
}
