typedef int s32;

struct Obj00500EB0;

extern "C" void func_00501808(void *arg0, void **arg1);
extern "C" void func_00501120(s32 arg0);
extern "C" void func_00500EB0(Obj00500EB0 *arg0);

extern "C" void func_005017A8(char *arg0) {
    char *s1;
    func_00501808(arg0, (void **)(arg0 + 0x1D8));
    func_00501808(arg0, (void **)(arg0 + 0x1E4));
    func_00501808(arg0, (void **)(arg0 + 0x1F0));
    s1 = arg0 + 0xB8;
    func_00501120((s32)s1);
    func_00500EB0((Obj00500EB0 *)s1);
}
