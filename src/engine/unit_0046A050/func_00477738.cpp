/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct N { int mode; N *f4; };
extern char D_006AD678[];
extern "C" void *func_00476790(void *, void *) throw();
extern "C" int func_0047A890(void *);
extern "C" int func_0047B640(void *, void *, void *, int);
extern "C" int func_0047C970(void *, void *, void *, int);
extern "C" void *func_00481230(void *, void *);
extern "C" void *func_004812C8(void *, void *);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005FBDD0(void *, const char *, u32, u32);

extern "C" int func_00477738(N *n, void *a1, void *a2, int flag) {
    switch (n->mode) {
    case 7: {
        void *v;
        if (flag) {
            v = func_004812C8((char *)n->f4 + 4, a1);
            func_00476790(v, a2);
            return 1;
        } else {
            v = func_00481230((char *)n->f4 + 4, a1);
            if (!v) return 0;
        }
        func_00476790(v, a2);
        return 1;
    }
    case 13: {
        if (func_005FBDD0(a1, D_006AD678, 0, func_0057F260(D_006AD678)) != 0) return 0;
        void *v = (void *)func_0047A890(n->f4);
        func_00476790(v, a2);
        return 1;
    }
    case 10:
        return func_0047B640((char *)n + 4, a1, a2, flag);
    case 11:
        return func_0047C970((char *)n + 4, a1, a2, flag);
    default:
        return 0;
    }
}
