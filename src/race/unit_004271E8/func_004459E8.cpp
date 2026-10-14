extern "C" void *D_0062378C;
extern "C" int func_004458D0(void *arg0, int arg1, char *arg2);
extern "C" void func_00449CD8(void *arg0, int arg1);

extern "C" void func_004459E8(void *arg0, int arg1) {
    char buf[0x40];
    int *p;

    func_004458D0(arg0, arg1, buf);
    p = *(int **)(&D_0062378C);
    func_00449CD8(p, *(int *)(buf + 0x8));
}
