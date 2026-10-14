struct W { char pad[0xF8]; unsigned cnt; char pad2[0xA474]; void *a[16]; void *b[16]; void *c[16]; };
struct M { char pad[8]; W w; };
extern M *D_0064B4B4;
extern "C" int func_0051B7B8(unsigned *out, void *a1, void *a2, void *a3) {
    if (!(D_0064B4B4->w.cnt < 0x10)) return 0x16;
    if (out == 0) return 0x17;
    *out = -1;
    M *m = D_0064B4B4;
    unsigned c = m->w.cnt;
    *out = c;
    M *m2 = D_0064B4B4;
    m->w.a[c] = a1;
    m->w.b[c] = a2;
    m->w.c[c] = a3;
    m2->w.cnt++;
    return 0;
}
