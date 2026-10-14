extern char D_00863BC8[];
extern "C" int func_0053A8F8(void *, void *);
extern "C" void func_00522298(void *, unsigned int);
extern "C" void func_0053A860(void *);
extern "C" void func_00522220(void) {
    unsigned int sp[4];
    char *p = D_00863BC8;
    func_0053A8F8(p, sp);
    if (sp[0] >= 1001U) {
        func_00522298(p + 8, sp[0]);
        func_00522298(p + 20, sp[0]);
        func_00522298(p + 32, sp[0]);
        func_00522298(p + 44, sp[0]);
        func_0053A860(p);
    }
}
