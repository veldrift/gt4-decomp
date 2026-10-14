typedef int s32;
typedef long s64;
struct Obj { s64 f0; s32 f8; s32 fC; };
struct Tmp { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; char pad[0xC]; };
extern "C" void func_0044A2A8(void *);
extern "C" s32 func_004AE230(Tmp *, char *, s32);
extern "C" s32 func_0057F260(const char *);
extern "C" int func_005A5A30(char *, unsigned, const char *, ...);
struct Ent { s64 id; char name[1]; };
extern Ent D_006235A8;
extern char D_006A7AA0[];

extern "C" s32 func_00449E10(Obj *self, s64 id) {
    if ((id >> 32) == 0x26) return 0;
    if (id == self->f0) return 1;
    Tmp t;
    const char *s = (const char *)&D_006235A8;
    s += 8;
    s32 n = func_0057F260(s);
    char *buf = (char *)__builtin_alloca(n + 0x16 + 0xF & ~0xF);
    func_005A5A30(buf, n + 0x16, D_006A7AA0, s, id);
    func_0044A2A8(self);
    func_004AE230(&t, buf, 1);
    if (t.f0 == 9) return 0;
    s32 a = t.f10;
    s32 b = t.f8;
    self->f0 = id;
    self->fC = b;
    self->f8 = a;
    return 1;
}
