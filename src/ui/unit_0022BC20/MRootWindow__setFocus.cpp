/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00232C20(void *, int) throw();
extern "C" void func_00232C78(void *, void *) throw();
extern "C" void func_00235C80(char *, void *);
extern "C" void *func_00255088(void *, void *);
extern "C" void func_002550B8(void *, int);
struct Value { void *p; int pad[3]; };
extern "C" void MRootWindow__setFocus(void *arg0, void *arg1, int count, void **args) {
    char *a[4];
    Value b;
    Value temp;
    if (count > 0) {
        func_00232C78(a, arg1);
        Value *pt = &temp;
        pt->p = args[0];
        Value *pb = &b;
        func_00255088(pb, pt);
        func_00235C80(a[0], pb->p);
        func_002550B8(pb, 2);
        func_00232C20(a, 2);
    }
}
