typedef int s32;
struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
union Temp { Str s; s32 h[4]; };
extern char D_006959D8[];
extern "C" void func_001D6ED8(void *, void *);
extern "C" void func_001D6E80(void *, s32);
extern "C" void func_004E83B8(void *, void *);
extern "C" void *func_001DC650(void *, void *) throw();
extern "C" void func_001DC5F8(void *, s32) throw();
extern "C" void func_001F15D8(s32, const char *);
extern "C" void free(void *) throw();
static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) return D_006959D8;
    s->p[len] = 0;
    return s->p;
}
extern "C" void MNetwork__setSvoCookie(void *arg0, void *arg1, s32 arg2, void *arg3) {
    Temp t;
    s32 buf[4];
    func_001D6ED8(t.h, arg3);
    char *obj = (char *)t.h[0];
    obj += 0x10;
    func_001D6E80(t.h, 2);
    func_004E83B8(&t.s, obj);
    s32 *p = buf;
    func_001DC650(p, arg1);
    char *text = t.s.p;
    s32 length = ((Rep *)text)[-1].len;
    const char *result = D_006959D8;
    s32 selected = *p;
    if (length != 0) {
        text[length] = 0;
        result = t.s.p;
    }
    func_001F15D8(selected, result);
    func_001DC5F8(p, 2);
    Rep *q = (Rep *)t.s.p - 1;
    if (--q->ref == 0) free(q);
}
