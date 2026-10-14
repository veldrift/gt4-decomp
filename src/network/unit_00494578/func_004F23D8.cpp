/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00576788(int);
extern "C" void func_005767C0(int);
extern "C" void func_0060EC38(void *, int);
extern "C" int func_004F23D8(int arg0) {
    int p = arg0 + 0x198;
    int lock = arg0 + 8;
    if (*(int *)(p + 8) == 0) return 0;
    func_00576788(lock);
    int *entry = (int *)p + *(int *)(p + 4);
    int r = entry[3];
    func_0060EC38((void *)p, 1);
    func_005767C0(lock);
    return r;
}
