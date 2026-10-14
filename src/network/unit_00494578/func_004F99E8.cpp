/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_006C09C0[];
extern char D_006C09C8[];
extern "C" int func_004F98E0(void *, const char *, int, int) throw();
extern "C" int func_004F9A58(void *, int);
extern "C" int func_004F99E8(void *self) {
    int result = func_004F98E0(self, D_006C09C0, 1, 1);
    if (result != 0) {
        if (func_004F98E0(self, D_006C09C8, 2, 2) == 0) {
            func_004F9A58(self, 1);
            return 0;
        }
        return 1;
    }
    return result;
}
