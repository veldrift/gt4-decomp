/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Args { float f; int a, b; };
extern "C" void func_00460220(void *, int, int, float);
extern "C" void func_00460658(int);
extern "C" void func_00461978(void *, int, int, float);
static inline int dispatch(int mode, void *obj, int b, int a, float f) {
    switch (mode) {
    case -1: func_00461978(obj, b, a, f); return 1;
    case -2: func_00460220(obj, b, a, f); return 2;
    case -3: func_00460658((int)obj); return 3;
    default: return 0;
    }
}
extern "C" int func_004608C8(int mode, void *obj, Args *p) {
    return dispatch(mode, obj, p->b, p->a, p->f);
}
