/* compiler: ee-gcc2.96-no-strict-aliasing */
struct CB { void (*fn)(void *, int); void *arg; };
extern "C" void func_0038FFC8(void *, void *);
extern "C" void *exception__structor_0(int);
extern "C" char *func_005A609C(char *, const char *);
extern "C" void func_0038FEF0(void *, int);
extern "C" void func_0044CBE8(void *, CB *);
extern "C" void RaceCarModel__virtual_13(char *o, const char *name, int mode) {
    CB cb;
    if (*(int *)(o + 0x166c) == 0) {
        if (mode == 2) {
            func_0038FFC8(o, 0);
            return;
        }
        char *p = (char *)exception__structor_0(0x104);
        *(void **)(p + 0x100) = o;
        func_005A609C(p, name);
        cb.fn = func_0038FEF0;
        cb.arg = p;
        func_0044CBE8(p, &cb);
    }
}
