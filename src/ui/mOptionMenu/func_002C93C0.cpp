/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; void (*fn)(void *, void *, s32, void *); };
struct VObj { char pad[4]; char *vt; };
struct S {
    char pad0[0xD0]; VObj *h; char padd4[0x8]; s32 dc; char pade0[0x1C]; s32 fc; s32 f100; s32 f104;
};
struct Cur { void *p; char pad[0xC]; };
extern char D_0069C7B8[];
extern "C" s32 func_00231F60(s32, s32);
extern "C" void func_00235C80(void *, void *);
extern "C" void func_0023DDF0(void *, int);
extern "C" void func_0023F8C8(void *, char *);
extern "C" void func_0023FB80(void *);
extern "C" void *mWidget__getRootWindow(void *);
extern "C" s32 func_00265D00(void *);
extern "C" void func_002C8198(void *, s32) throw();
extern "C" void func_002C8E30(void *, s32) throw();
extern "C" void func_00309348(void *, void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030BB18(void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0057CE40(void *, s32);
extern "C" void func_002C93C0(S *self, s32 arg1, s32 arg2) {
    {
        Cur c;
        func_0023FB80(&c);
        func_0023F8C8(c.p, D_0069C7B8);
        func_0023DDF0(&c, 2);
    }
    if (arg2 == 0)
        func_002C8198(self, arg1);
    else
        func_0057CE40((char *)self + 0xD8, self->f100);
    func_00235C80(mWidget__getRootWindow(self), self);
    func_00231F60(arg1, 0);
    self->fc = 0;
    self->f104 = 0;
    if (arg2 == 0)
        func_002C8E30(self, arg1);
    if (func_00265D00(self) != 0) {
      VObj **hp = &self->h;
      if (*hp != 0) {
        char h0[0x10];
        s32 rbuf[4];
        s32 tbuf[4];
        s32 v;
        func_0030BB18(h0);
        s32 *r = rbuf;
        func_0030BB18(r);
        s32 *t = tbuf;
        v = arg1;
        func_00309348(t, &v);
        if (r != t) {
            s32 nv = t[0];
            if (nv != 0) func_003285A8(nv);
            if (r[0] != 0) func_003285F8(r[0]);
            r[0] = nv;
        }
        func_00309378(t, 2);
        VObj *o = *hp;
        E *e = (E *)(o->vt + 0xA8);
        e->fn((char *)o + e->d, h0, 1, r);
        s32 *p = rbuf + 1;
        while (r != p) {
            p--;
            func_00309378(p, 2);
        }
        func_00309378(h0, 2);
      }
    }
}
