/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00462450();
extern "C" int func_004AE268(void *, const char *, void *, int, int);
extern "C" int func_0057DA20(int, int, ...);
extern char D_006AB400[], D_006AB408[], D_006AB418[], D_00846880[];
extern "C" void func_00460580() {
    char buf[0x70];
    char out[0x20];
    func_0057DA20((int)buf, (int)D_006AB400, D_006AB408, func_00462450(), D_006AB418);
    func_004AE268(out, buf, D_00846880, 0x10, 1);
}
