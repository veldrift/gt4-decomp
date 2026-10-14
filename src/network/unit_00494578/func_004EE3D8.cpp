/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004EE330(char *, int) throw();
extern "C" void func_004EE368(char *, int) throw();
extern "C" void func_004EE3A0(char *, int) throw();
extern "C" int func_004EE3D8(char *obj, int kind, int arg) {
    switch (kind) {
    case 0: func_004EE330(obj, arg); break;
    case 1: func_004EE368(obj, arg); break;
    case 2: func_004EE3A0(obj, arg); break;
    default: return 0;
    }
}
