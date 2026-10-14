/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00251998(void *a, int b);
extern "C" void func_00576788(int a);
extern "C" void func_005767C0(int a);
extern "C" void func_005DD168(void *a);

extern "C" void mUpdateContext__virtual_66(char *arg0) {
    char *s1 = arg0 + 0xE8;
    func_00251998(arg0, 0);
    func_00576788((int)s1);
    func_005DD168(arg0 + 0x10);
    func_005767C0((int)s1);
}
