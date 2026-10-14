/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_004B8FE0(int, int, int) throw();
extern "C" int func_004B9098(int, int, int) throw();
extern "C" int func_004B91A8(int self, int ch, int flag, int mode) {
    if (mode != 0) {
        if (flag != 0) return 0;
        if (ch == 0x40 || ch == 0x5B)
            return func_004B8FE0(self, mode, ch) != 0;
        return 0;
    } else {
        return func_004B9098(self, ch, flag) != 0;
    }
}
