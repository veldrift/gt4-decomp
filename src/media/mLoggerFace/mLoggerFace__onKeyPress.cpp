/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; };
struct Buf { char x[16]; };
struct Obj { int x; char *vtbl; };
struct Handle { Obj *p; char pad[12]; };
struct Self { char pad[0xAC]; int enabled; };
struct Key { char pad[0x20]; unsigned key; };
struct VEntry { short delta, index; int (*fn)(void *); };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern char D_00693AA0[], D_00693AB0[];
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *, unsigned, unsigned, const char *, unsigned);
extern "C" void func_002EFBF0(Buf *);
extern "C" void func_0023A538(Handle *, int, Self *, Str *, Buf *);
extern "C" void func_00239F08(Handle *, int);
extern "C" void func_002ED5C0(Buf *, int);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" int mLoggerFace__onKeyPress(Self *self, int arg1, Key *key) {
    Handle h;
    Str s1; Buf b1; Str s2; Buf b2;
    if (self->enabled) {
        switch (key->key) {
        case 0xFF1B: case 0xFF63: {
            Str *ps = &s1;
            const char *src = D_00693AA0;
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel) d = func_005C2560(r);
            else { d = (char *)(r + 1); r->ref++; }
            ps->p = d;
            func_005C2630(ps, 0, -1, src, func_0057F260(src));
            func_002EFBF0(&b1);
            func_0023A538(&h, arg1, self, ps, &b1);
            VEntry *e = (VEntry *)(h.p->vtbl + 0x190);
            e->fn((char *)h.p + e->delta);
            func_00239F08(&h, 2);
            func_002ED5C0(&b1, 2);
            Rep *q = (Rep *)(ps->p - 16);
            if (--q->ref == 0) {
                int cap = q->cap + 16;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
            return 2;
        }
        case 0xFF0D: case 0xFF8D: {
            Str *ps = &s2;
            const char *src = D_00693AB0;
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel) d = func_005C2560(r);
            else { d = (char *)(r + 1); r->ref++; }
            ps->p = d;
            func_005C2630(ps, 0, -1, src, func_0057F260(src));
            func_002EFBF0(&b2);
            func_0023A538(&h, arg1, self, ps, &b2);
            VEntry *e = (VEntry *)(h.p->vtbl + 0x190);
            e->fn((char *)h.p + e->delta);
            func_00239F08(&h, 2);
            func_002ED5C0(&b2, 2);
            Rep *q = (Rep *)(ps->p - 16);
            if (--q->ref == 0) {
                int cap = q->cap + 16;
                func_00326798(q, cap, 4, func_005C11A8()->name);
                return 2;
            }
            return 2;
        }
        default: return 2;
        }
    }
    return 0;
}
