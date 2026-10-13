typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct Vec {
    char pad0[4];
    s32 *begin;
    s32 *end;
};

extern Rep D_00659FA8;
extern char D_0069E018[];

extern "C" s32 func_003166B8(s32 arg0);
extern "C" s32 func_003166D8(s32 arg0);
extern "C" s32 func_0057F260(const char *s);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(void *s, s32 pos, s32 n1, const char *src, s32 n2);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void func_0030F190(Vec *self) {
    Str s;
    s32 buf1[4];
    s32 n;
    s32 i;
    s32 s2;

    n = ((s32)self->end - (s32)self->begin) >> 2;
    if (n >= 2) {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        s2 = n - 1;
        s.p = d;
        i = 0;
        if (s2 > 0) {
            const char *sep = D_0069E018;
            do {
                if (i > 0) {
                    func_005C2630(&s, ((Rep *)(s.p - 0x10))->len, 0, sep, func_0057F260(sep));
                }
                s32 off = i * 4;
                const char *elem = (const char *)func_003166D8(*(s32 *)((char *)self->begin + off));
                i = i + 1;
                func_005C2630(&s, ((Rep *)(s.p - 0x10))->len, 0, elem, func_0057F260(elem));
            } while (i < s2);
        }
        s32 *p10 = buf1;
        s32 *last = self->end - 1;
        {
            s32 r3 = func_003166B8((s32)&s);
            *p10 = r3;
            if (last != p10) {
                *last = r3;
            }
        }
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
    }
}
