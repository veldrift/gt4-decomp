extern "C" void *func_0043A3F8(void *self);
extern "C" void func_0043A1A0(void *self);
extern "C" void func_00430750(void *self);
extern "C" void func_0043ACC0(void *self);
extern "C" void func_00436278(void *self);
extern "C" void func_0042FA80(void *self);
extern "C" void func_00434590(void *self);
extern "C" char D_00687E50[];

extern "C" void func_0043A528(void *arg0) {
    func_0043A3F8(arg0);
    *(void **)arg0 = D_00687E50;
    func_0043A1A0((char *)arg0 + 4);
    char *p = (char *)arg0 + 0xD8;
    for (int i = 5; i != -1; i--) {
        func_00430750(p);
        p += 0x68;
    }
    func_0043ACC0((char *)arg0 + 0x348);
    func_00436278((char *)arg0 + 0x38CB0);
    func_0042FA80((char *)arg0 + 0x3A368);
    return func_00434590((char *)arg0 + 0x3B018);
}
