extern int D_00617D80;
extern volatile int D_00617D84;
extern "C" void func_00578908(int);
extern "C" void func_00101900() {
    D_00617D84 = 1;
    func_00578908(D_00617D80);
}
extern "C" void func_00548500(void);
extern "C" void func_00101930() {
    func_00548500();
}
