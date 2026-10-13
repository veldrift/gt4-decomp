extern "C" int func_00427778(int t, int name);
extern "C" void func_00428568(void *self, int idx, float a, int arg, float b);

extern "C" void func_00428600(void *self, int name, float a, int arg, float b) {
    int p = *(int *)((char *)self + 4);
    if (p != 0) {
        func_00428568(self, func_00427778(p, name), a, arg, b);
    }
}
