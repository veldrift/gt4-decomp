/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" s32 func_005A6AB0(void *, void *, s32) throw();
#define W(p, o) (*(s32 *)((p) + (o)))
extern "C" void func_004FB230(char *arg0, char *arg1, s32 arg2) {
    func_005A6AB0(arg0 + 0x8A1, arg1 + 0x15, 0x40);
    func_005A6AB0(arg0 + 0x8E1, arg1 + 0x55, 0x100);
    func_005A6AB0(arg0 + 0x9E1, arg1 + 0x155, 0x20);
    s32 t = W(arg0, 0x40);
    char *s0 = arg0 + 0x88C;
    W(s0, 0x178) = t;
    W(s0, 0x17C) = W(arg1, 0x17C);
    W(s0, 0x180) = W(arg1, 0x180);
    W(s0, 0x184) = 1;
    W(s0, 0x188) = W(arg1, 0x184);
    W(s0, 0x18C) = W(arg1, 0x188);
    W(s0, 0x190) = W(arg1, 0x18C);
    W(s0, 0x194) = W(arg1, 0x190);
    W(s0, 0x198) = W(arg1, 0x194);
    W(s0, 0x19C) = W(arg1, 0x198);
    W(s0, 0x1A0) = arg2;
    W(s0, 0x1A4) = 2;
}
