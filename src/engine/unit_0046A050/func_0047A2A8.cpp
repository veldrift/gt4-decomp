typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Rep { int len; int cap; int ref; int sel; };
struct Str { char *p; };
struct Obj { char pad0[0xA]; u16 hA; const u8 *sC; };
struct Obj2 { char pad0[8]; int f8; };
extern char D_00659E20[];
extern "C" char *strobe__toUpper(void *);
extern "C" int func_0057F260(const char *);
extern "C" void *strobe__Any__setMember(void *, u32, u32, const char *, u32);
extern "C" void func_00480FE8(void *);
extern "C" void *func_00481410(void *, void *);
extern "C" void *func_00476790(void *, void *);
extern "C" void func_00480F78(void *);
extern "C" void free(void *);

extern "C" void func_0047A2A8(Obj *a, void *m, Obj2 *c, u32 count) {
    u32 i = 0;
    const u8 *s = a->sC;
    if (count == 0) return;
    do {
        if (i < a->hA) {
            Str tmp;
            Str *ps = &tmp;
            Rep *g = (Rep *)D_00659E20;
            char *r;
            if (g->sel != 0) {
                r = strobe__toUpper(g);
            } else {
                r = (char *)g + 0x10;
                g->ref++;
            }
            ps->p = r;
            strobe__Any__setMember(ps, 0, (u32)-1, (const char *)s, func_0057F260((const char *)s));
            func_00480FE8(&tmp);
            void *v = func_00481410(m, &tmp);
            func_00476790(v, (void *)(c->f8 - 8));
            int ch;
            do {
                ch = *s++;
            } while (ch != 0);
            Rep *q = (Rep *)(tmp.p - 0x10);
            if (--q->ref == 0) free(q);
        }
        func_00480F78(c);
        i++;
    } while (i < count);
}
