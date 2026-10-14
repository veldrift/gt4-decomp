/* compiler: ee-gcc2.96-nogcse */
typedef unsigned int u32;
extern char D_006C3880[];
extern "C" u32 func_00539528(void) throw();
extern "C" void func_005395E0(char *dst, u32 n) {
    u32 i = 0;
    if (n != 0) {
        u32 m = n - 1;
        char *end = dst + n;
        if (m != 0) {
            do {
                dst[i] = D_006C3880[func_00539528() & 0x3F];
                i++;
            } while (i < m);
            end = dst + n;
        }
        end[-1] = 0;
    }
}
