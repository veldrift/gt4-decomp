/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
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

extern s8 D_006B0C80[];
extern char D_0069C110[];

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

struct Str {
    char *p;
    Rep *rep() { return (Rep *)p - 1; }
    s32 length() { return rep()->len; }
    char *data() { return (char *)(rep() + 1); }
    void terminate() { data()[length()] = 0; }
    char *c_str() {
        if (length() == 0) return D_0069C110;
        terminate();
        return data();
    }
    ~Str() {
        Rep *r = rep();
        if (--r->ref == 0) {
            s32 cap = r->cap + 0x10;
            func_00326798(r, cap, 4, func_005C11A8()->name);
        }
    }
};

extern "C" void func_002B74B0(Str *dst, Str *src) throw();

extern "C" void func_002B75E8(Str *src, char *out, s32 maxlen, s32 start, s32 end) {
    Str tmp;
    char *p;
    char *q;
    s32 i;
    s32 a;
    s32 b;
    s32 len;
    *out = 0;
    func_002B74B0(&tmp, src);
    Str *ps = &tmp;
    p = tmp.c_str();
    q = p;
    s32 j = 0;
    a = 0;
    len = ps->length();
    if (start > 0) {
        do {
            s32 d = D_006B0C80[(u8)*q];
            a += d;
            q += d;
            if (a >= len) return;
            j++;
        } while (j < start);
    }
    {
        s32 n = end - start;
        b = a;
        i = 0;
        if (n > 0) {
            do {
                s32 d = D_006B0C80[(u8)*q];
                b += d;
                q += d;
                if (b >= len) return;
                i++;
            } while (i < n);
        }
    }
    {
        s32 cnt = b - a;
        if (maxlen < cnt) return;
        p = ps->c_str();
        for (i = 0; i < cnt; i++) {
            out[i] = p[a + i];
        }
        return;
    }
}
