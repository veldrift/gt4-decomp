/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *EngineSound__structor_0(void *) throw();
extern "C" int func_004629C8(void *);
extern "C" void func_00391FD0(char *self) {
    int i = 2;
    char *p = self + 0x408;
    EngineSound__structor_0(self + 0x30);
    EngineSound__structor_0(self + 0x154);
    func_004629C8(self + 0x278);
    func_004629C8(self + 0x298);
    EngineSound__structor_0(self + 0x2d0);
    char *q = p;
    do {
        p += 0x20;
        --i;
        func_004629C8(q);
        q = p;
    } while(i != -1);
    char *row = self + 0x474;
    for (int k = 3; k != -1; --k) {
        char *p2 = row + 0x14;
        for (int j = 10; j != -1; --j) {
            func_004629C8(p2);
            p2 += 0x20;
        }
        row += 0x1a0;
    }
    *(int *)(self + 0xb38) = 0;
}
