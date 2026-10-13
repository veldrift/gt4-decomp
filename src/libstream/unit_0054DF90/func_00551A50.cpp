typedef struct { int w[15]; } Copy60;

extern "C" {
extern char D_0086F940[];
extern char D_0086FC80[];
void func_00576788(int a0);
void func_005767C0(int a0);
}

extern "C" void func_00551A50(int arg0, Copy60 *arg1) {
    char *s0 = D_0086FC80 + arg0 * 0x6C;
    func_00576788((int)D_0086F940);
    *arg1 = *(Copy60 *)(s0 + 4);
    func_005767C0((int)D_0086F940);
}
