/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_001237B0(void *, int *);
extern "C" int func_00228450(void *, int *);
extern "C" int mWidget__structor_0(void *);
extern char mLoggerFace__vtable[];
extern "C" void mLoggerFace__structor_0(char *arg0) {
    int sp0;
    int sp4;
    mWidget__structor_0(arg0);
    *(int *)(arg0 + 0xA0) = 0;
    *(char **)(arg0 + 4) = mLoggerFace__vtable;
    sp0 = 0;
    func_001237B0(arg0 + 0xA4, &sp0);
    sp4 = 0;
    func_00228450(arg0 + 0xA8, &sp4);
    *(int *)(arg0 + 0xAC) = 0;
}
