typedef int s32;
struct Rep { int len, cap, ref, sel; };
struct Slot { char *p; char pad[12]; };
struct Info { const char *name; };
struct Entry { short delta, index; void (*fn)(Slot *, char *); };
extern Rep D_00659FA8;
extern char D_006984E0[], D_006984E8[], D_00698508[];
extern "C" char *func_00229D40(char *, char *, char *);
extern "C" void func_00232C20(Slot *, int);
extern "C" void func_00232C78(Slot *, void *);
extern "C" void func_002550B8(Slot *, int);
extern "C" void func_00255110(Slot *, void *);
extern "C" char *func_0025C110(char *);
extern "C" char *hModule__getName(char *);
extern "C" void func_00312318(Slot *, int);
extern "C" void func_00312370(Slot *, void *);
extern "C" char *func_00314920(char *);
extern "C" char *func_00314AD8(char *);
extern "C" void func_00314B20(Slot *, Slot *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_003285A8(char *);
extern "C" void func_003285F8(char *);
extern "C" char *func_00486028(char *, const char *, const char *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Info *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" Slot *func_005C2630(Slot *, unsigned, unsigned, const char *, unsigned);
extern "C" void func_005DB110(const char *, ...);

static inline void strinit(Slot *s, const char *text) {
    Rep *r = &D_00659FA8;
    char *p;
    if (r->sel) p = func_005C2560(r);
    else { p = (char *)(r+1); r->ref = r->ref + 1; }
    s->p = p;
    func_005C2630(s, 0, -1, text, func_0057F260(text));
}
static inline void strfree(Slot *s) {
    Rep *r = (Rep *)(s->p - 16);
    if (--r->ref == 0) {
        int size = r->cap + 16;
        Info *info = func_005C11A8();
        func_00326798(r, size, 4, info->name);
    }
}
static inline char *c_str(Slot *s) {
    int len = ((Rep *)(s->p - 16))->len;
    if (len == 0) return D_006984E0;
    s->p[len] = 0;
    return s->p;
}
static inline void assign(char **out, char **in) {
    if (out != in) {
        char *p = *in;
        if (p) func_003285A8(p);
        if (*out) func_003285F8(*out);
        *out = p;
    }
}
static inline void vstr(Slot *out, char *o) {
    Entry *e = (Entry *)(*(char **)(o+4) + 0x18);
    e->fn(out, o+e->delta);
}
extern "C" void MRenderContext__translate(char **out, int arg1, int count, char *args) {
    Slot tmp, h10, h20, s30, spare40, s50, spare60, s70;
    if (count == 2) {
        func_00232C78(&tmp, args);
        Slot *ph = &h10;
        func_00312370(ph, args+4);
        args = func_0025C110(tmp.p);
        char *name = hModule__getName(tmp.p);
        char *result = func_00229D40(args, name, func_00314920(ph->p));
        if (result) {
            Slot *ps = &s30;
            strinit(ps, result);
            Slot *pr = &h20;
            func_00314B20(pr, ps);
            assign(out, &pr->p);
            func_00312318(pr, 2);
            strfree(ps);
        } else {
            func_005DB110(D_006984E8, D_00698508, 0x235, func_00314AD8(ph->p));
            assign(out, &ph->p);
        }
        func_00312318(ph, 2);
        func_00232C20(&tmp, 2);
    } else if (count >= 3) {
        func_00255110(&tmp, args);
        char *mod = func_0025C110(tmp.p);
        func_002550B8(&tmp, 2);
        mod += 0xB0;
        vstr(&tmp, *(char **)(args+4));
        char *key = c_str(&tmp);
        char **value = (char **)(args+8);
        args = (char *)&s50;
        vstr((Slot *)args, *value);
        char *result = func_00486028(mod, key, c_str((Slot *)args));
        strfree((Slot *)args);
        strfree(&tmp);
        if (result) {
            Slot *ps = &s70;
            strinit(ps, result);
            func_00314B20(&tmp, ps);
            assign(out, &tmp.p);
            func_00312318(&tmp, 2);
            strfree(ps);
        } else {
            vstr(&tmp, *value);
            func_005DB110(D_006984E8, D_00698508, 0x243, c_str(&tmp));
            strfree(&tmp);
            assign(out, value);
        }
    }
}
