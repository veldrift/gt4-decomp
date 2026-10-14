typedef int s32;
typedef unsigned char u8;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0xC];
};

struct Rec {
    char pad[0x10];
    u8 kind;
    char rest[0xF];
};

extern Rep D_00659FA8;
extern char D_00693278[];
extern char D_00693280[];
extern char D_00693288[];
extern char D_00693290[];
extern char D_00693298[];

extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" char *func_00314AD8(void *arg0);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);
extern "C" s32 func_00447C78(s32 arg0);
extern "C" bool func_00447F48(s32 id, Rec *out);
extern "C" s32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MCourseData__GetType(void **arg0, s32 arg1, void *arg2) {
    if (arg1 > 0) {
        Handle h0;
        Rec rec;
        s32 spare[4];
        Str s;
        Str *ps;
        const char *w;
        s32 id;

        func_00312370(&h0, arg2);
        id = func_00447C78((s32)func_00314AD8(h0.p));
        func_00312318(&h0, 2);
        {
            s32 found = func_00447F48(id, &rec);
            w = D_00693278;
            if (found) {
                switch (rec.kind) {
                case 0:
                    w = D_00693280;
                    break;
                case 1:
                    w = D_00693288;
                    break;
                case 2:
                    w = D_00693290;
                    break;
                case 3:
                    w = D_00693298;
                    break;
                default:
                    break;
                }
            }
        }
        ps = &s;
        {
            Rep *r = &D_00659FA8;
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            ps->p = d;
        }
        func_005C2630(ps, 0, -1, w, func_0057F260(w));
        func_00314B20(&h0, ps);
        if ((void *)arg0 != (void *)&h0) {
            void *p = h0.p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_00312318(&h0, 2);
        str_release(ps);
    }
}
