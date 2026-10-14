/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Args { float f; int a,b; };
extern "C" void func_00461A10(void *, int, int, float, float);
extern "C" void func_004602A8(void *, int, int, float, float);
extern "C" void func_00460710(void *);
static inline int dispatch(int mode, void *obj, int b, int a, float x, float y) {
    switch (mode) {
    case -1: func_00461A10(obj,b,a,x,y); return 1;
    case -2: func_004602A8(obj,b,a,x,y); return 2;
    case -3: func_00460710(obj); return 3;
    default: return 0;
    }
}

extern "C" int func_00460960(int mode, void *obj, Args *p, float x) {
    return dispatch(mode, obj, p->b, p->a, x, p->f);
}
