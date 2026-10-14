/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d; short i; int (*fn)(void *); };
struct Ctx { char p[0xCBE0]; unsigned char mCBE0; char q[0x10140 - 0xCBE1]; char *vt; };
struct Obj84 { char p[0x64]; char *vt; };
struct G0 { char p[0x84]; Obj84 *m84; };
struct Ent { char p[0x32]; unsigned char m32; };
struct Self {
    G0 *m0; Ctx *m4; char p[8]; Ent *m10; char p2[0x104 - 0x14];
    char b[0x62E]; unsigned char m62E;
};
extern "C" int func_00343C20(Self *, int);
extern "C" int func_00354E38(Self *) throw();
extern "C" void *func_00359510(Ent *) throw();

static inline int call120(Obj84 *o) {
    VE *w = (VE *)(o->vt + 0x120);
    return w->fn((char *)o + w->d);
}
extern "C" int func_0035AF18(Self *self) {
    unsigned char c = self->m4->mCBE0;
    if (c != 1) return 0;
    char *b = (char *)self + 0x104;
    if (*(unsigned char *)(b + 0x62E) != 0) return 0;
    if (func_00343C20(self, 1) == c) return 0;
    Ent *e = self->m10;
    if (e->m32 == 4) return 0;
    func_00359510(e);
    unsigned short s0 = 4;
    if (func_00354E38(self)) s0 = 0xC;
    Ctx *cx = self->m4;
    VE *v = (VE *)(cx->vt + 0x198);
    if (v->fn((char *)cx + v->d) != 0) s0 |= 2;
    if (s0 == 0) s0 = 2;
    if (*(signed char *)(b + 0x466) != 2 && call120(self->m0->m84)) {
        if (s0 & 0xC) s0 |= 1;
    } else {
        if (s0 & 4) { s0 |= 0xC0; s0 &= ~4; }
        if (s0 & 8) { s0 |= 0x100; s0 &= ~8; }
    }
    return s0;
}
