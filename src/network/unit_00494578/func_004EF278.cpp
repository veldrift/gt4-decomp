/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    int m0;
    char pad[0x90];
    int m94;
};
extern "C" int func_004ED008(void) throw();
extern "C" int func_004EF678(O *);
extern "C" unsigned int func_004EF2F0(O *, int);

extern "C" int func_004EF278(O *a, int b) {
    if (func_004ED008() < 0) {
        return 0;
    }
    if (a->m0 == 0 && func_004EF678(a) == 0) {
        return 0;
    }
    a->m94 = -1;
    if (b != 0) {
        func_004EF2F0(a, b);
    }
    return 1;
}
