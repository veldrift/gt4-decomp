/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int unused; int *begin; int *end; };
struct Code { char pad[0x2c]; Vec v; };
struct Context { char pad[0x38]; int value; };
extern "C" void func_002F4848(Code *, int);
extern "C" int func_00305620(int);
extern "C" void func_00305678(int, int);
extern "C" void func_00309378(void *, int);
extern "C" void func_0030BB18(void *);
extern "C" void func_00318538(void *, int);
extern "C" void func_00319268(void *);
extern "C" int hThread__execCode(void *, int, Code **, void *, int, int);
extern "C" void *func_002EC430(void *dst, Context *ctx, Code **code, int *env) {
    int a[4];
    int b[4];
    int valid = 0;
    Code *p = *code;
    if (p) {
        Vec *v = &p->v;
        valid = (v->end - v->begin) != 0;
    }
    if (valid == 0) {
        func_0030BB18(dst);
    } else {
        if (func_00305620(*env) == 0) func_00305678(*env, ctx->value);
        func_002F4848(*code, *env);
        func_00319268(a);
        int *pb = b;
        int thread = a[0];
        func_0030BB18(pb);
        hThread__execCode(dst, thread, code, pb, 0, 0);
        func_00309378(pb, 2);
        func_00318538(a, 2);
    }
    return dst;
}
