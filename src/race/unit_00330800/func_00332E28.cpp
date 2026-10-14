/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_0069F120[];
extern "C" void func_00332740(int, int, unsigned int) throw();
extern "C" void func_0057DA20(void *, const char *, ...);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005B2DF0(const char *, int);
extern "C" int func_005B3080(int);
extern "C" int func_005B36A8(int, void *, int);
extern "C" int func_00332E28(const char *arg0, int arg1, int arg2, int arg3, int arg4) {
    char sp[0x20];
    int fd = func_005B2DF0(arg0, 0x602);
    int result = 0;
    if (fd >= 0) {
        func_0057DA20(sp, D_0069F120, arg2, arg3);
        func_005B36A8(fd, sp, func_0057F260(sp));
        func_00332740(fd, arg1, arg2 * arg3 * arg4);
        func_005B3080(fd);
        result = 1;
    }
    return result;
}
