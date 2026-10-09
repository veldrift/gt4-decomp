extern "C" void func_00450AB0(void *, void *);
extern "C" void func_00450AD0(void *);
extern "C" void func_003EDA10(int);

extern "C" void func_0038FEB0(void *arg0, void *arg1) {
    if (arg1 != 0) return func_00450AB0((char *)arg0 + 0x18, arg1);
    func_00450AD0((char *)arg0 + 0x18);
    func_003EDA10(0);
}
