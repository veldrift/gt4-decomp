/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" char D_006A23B0[];
extern "C" void func_003B0FD0(int *, int) throw();
extern "C" int func_004AE268(void *, char *, u32, int, int);
extern "C" void func_004AE6B0(void *, char *);
extern "C" u32 func_003B18F8(int *arg0, u32 arg1, int arg2, char *arg3) {
    int sp[8];
    char *name = arg3;
    if (*arg0 != 0) return 0;
    {
        if (name == 0) name = D_006A23B0;
        u32 pos = (arg1 + 63) & ~63;
        u32 end = arg1 + arg2;
        if (pos >= end) return arg1;
        {
            func_004AE6B0(sp, name);
            u32 next = (pos + sp[2] + 63) & ~63;
            if (end >= next) {
                func_004AE268(sp, name, pos, sp[2], 1);
                if (sp[4] != 0) {
                    pos = next;
                    func_003B0FD0(arg0, sp[4]);
                } else {
                    func_003B0FD0(arg0, 0);
                }
            } else {
                func_003B0FD0(arg0, 0);
            }
            return pos;
        }
    }
}
