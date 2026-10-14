/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Info { char pad[12]; int count; };
struct Holder { char pad[16]; Info *info; };
struct Heap { const char *name; };
extern Rep D_00659FA8;
extern "C" void func_001BFEA8(void *) throw();
extern "C" void func_001BFE50(void *, int) throw();
extern "C" void func_002EFC48(void *, int);
extern "C" void **HArray__operator_index(void *, int);
extern "C" int func_00430528(void *, int);
extern "C" int func_00447CA0(int, char *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(void *, unsigned int, unsigned int, const char *, unsigned int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00312318(void *, int);
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_002ED5C0(void *, int);
static inline void release(Str *s) {
    Rep *r = (Rep *)(s->p - 16);
    if (--r->ref == 0) {
        int size = r->cap + 16;
        func_00326798(r, size, 4, func_005C11A8()->name);
    }
}
extern "C" void MFavorite__buildLabelList(void **arg0) {
    void *arr[4];
    char text[0x40];
    void *value[4];
    Str str;
    int i = 0;
    func_001BFEA8(arr);
    Info *info = ((Holder *)arr[0])->info;
    func_001BFE50(arr, 2);
    int count = info->count;
    func_002EFC48(arr, count);
    for (; i < count; i++) {
        func_00447CA0(func_00430528(info, i), text);
        void **dest = HArray__operator_index(arr, i);
        char *pt = text;
        void **pv = value;
        Str *s = &str;
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel) d = func_005C2560(r);
        else { d = (char *)(r + 1); r->ref++; }
        s->p = d;
        func_005C2630(s, 0, -1, pt, func_0057F260(pt));
        func_00314B20(value, s);
        if (dest != value) {
            void *n = *pv;
            if (n) func_003285A8(n);
            void *old = *dest;
            if (old) func_003285F8(old);
            *dest = n;
        }
        func_00312318(pv, 2);
        release(s);
    }
    if (arg0 != arr) {
        void *n = arr[0];
        if (n) func_003285A8(n);
        void *old = *arg0;
        if (old) func_003285F8(old);
        *arg0 = n;
    }
    func_002ED5C0(arr, 2);
}
