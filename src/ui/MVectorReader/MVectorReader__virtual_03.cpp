/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

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

struct Holder {
    char pad[4];
    f32 *out;
};

extern Rep D_00659FA8;
extern char D_00699880[];
extern char D_00699888[];

extern "C" s32 func_0020EEA0(void *arg1, Str *s);
extern "C" void func_0020FC58(void *r, int depth);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" double func_005A2F70(const char *s);
extern "C" void func_005A48D8(void *p, s32 v, u32 n);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_005CD320(void *self, const char *s, u32 pos, u32 n);

extern "C" void MVectorReader__virtual_03(Holder *arg0, void *arg1, void *arg2) {
    Str s;
    f32 v[2];
    if (func_005CD320(arg2, D_00699880, 0, func_0057F260(D_00699880)) == 0) {
        Rep *r = &D_00659FA8;
        char *d;
        s32 i;
        s32 t;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        s.p = d;
        func_0020EEA0(arg1, &s);
        i = 0;
        func_005A48D8(v, 0, 8);
        while ((t = func_0020EEA0(arg1, &s)) != -1 && t != 0x7D) {
            const char *c = D_00699888;
            if (*(s32 *)(s.p - 0x10) != 0) {
                s.p[*(s32 *)(s.p - 0x10)] = 0;
                c = s.p;
            }
            v[i++] = (f32)func_005A2F70(c);
            if (i >= 2) {
                break;
            }
        }
        if (t != 0x7D) {
            func_0020FC58(arg1, 1);
        }
        arg0->out[0] = v[0];
        arg0->out[1] = v[1];
        {
            Rep *q = (Rep *)(s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
