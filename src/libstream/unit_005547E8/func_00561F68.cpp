extern "C" char D_00654D40[];

extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_00577F80(void *arg);
extern "C" int func_0058E228(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5);
extern "C" void func_00562618(void *a0, int *a1);

extern "C" int func_00561F68(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    int local;
    int sp4;

    func_00576788(D_00654D40);
    while (func_0058E228(arg0, arg1, arg2, arg3, arg4, arg5) != 0) {
        func_00577F80(&local);
    }
    func_00562618(&local, &sp4);
    func_005767C0(D_00654D40);
    return sp4;
}
