/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int unused; int *begin; int *end; int *limit; };
extern char mFunctionEvent__vtable[];
extern char D_00697768[];
extern "C" void mEvent__structor_1(void *, int);
extern "C" void func_002F9B38(void *, int);
extern "C" void func_00309378(void *, int);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void *HObject__tf(void);
static inline void destroy(Vec *v) {
    int *sp[4];
    int *first = v->begin;
    int *last = v->end;
    sp[0] = first;
    for (int *p = first; p != last; ++p) func_00309378(p, 2);
    int *base = v->begin;
    int count = v->limit - base;
    if (base) func_00326798(base, count * 4, 4, *(const char **)HObject__tf());
}
extern "C" void mFunctionEvent__structor_1(char *self, int flags) {
    *(char **)(self + 4) = mFunctionEvent__vtable;
    destroy((Vec *)(self + 0x24));
    func_002F9B38(self + 0x20, 2);
    mEvent__structor_1(self, 0);
    if (flags & 1) func_00326798(self, 0x34, 4, D_00697768);
}
