struct Vt { short off; short pad; int (*fn)(void *); };
struct Cls { char p[0xD0]; Vt v; };
struct Self { char p[0x4C]; Cls *vptr; };
struct Dst { char p[0x10]; char *h; };
extern char D_00694DC8[];
extern char D_00694DF8[];
extern const char D_00694DD8[] __attribute__((aligned(8)));
struct Blk { long a, b, c; int d; short e; };
extern "C" void func_004AE230(void *, char *, int);
extern "C" int func_0057F260(char *);
extern "C" void func_001D0438(char *, char *);
extern "C" long func_001CD840(void *);
extern "C" void func_0057DA20(char *, char *, ...);
extern "C" void func_001CBD18(char *, char *);
extern "C" void func_001CBED0(char *, char *);
extern "C" void func_001CBC88(char *);
extern "C" int GT4MC__FileGT4__writeIconImpl(void *, int, char *, int);
extern "C" void free(char *);

extern "C" int func_001CD088(Self *self, int a1, char *a2, int a3) {
    union {
        struct { Dst d; char pad[12]; char name[0x80] __attribute__((aligned(8))); } fields;
        char raw[0xA0];
    } storage;
    Dst &d = storage.fields.d;
    char buf[0x10];
    func_004AE230(&d, D_00694DC8, 1);
    char *name = storage.fields.name;
    __builtin_memcpy(storage.fields.name, D_00694DD8, 30);
    char *h = d.h;
    func_001D0438(name + func_0057F260(name), a2);
    Vt *v = &self->vptr->v;
    if (v->fn((char *)self + v->off) == 0) {
        func_0057DA20(buf, D_00694DF8, ((int)(func_001CD840(self) >> 32) & 0x1FFFF) + 1);
        func_001CBD18(name + func_0057F260(name), buf);
    }
    func_001CBED0(h, name);
    func_001CBC88(h + 0xC0);
    int r = GT4MC__FileGT4__writeIconImpl(self, a1, h, a3);
    free(d.h);
    return r;
}
