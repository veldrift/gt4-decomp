struct Obj1 {
    char pad[0x2DC];
    int bufIndex;
};

extern "C" void func_00459470(void *out, void *a, void *b, int t);

extern "C" void *func_0045AB58(void *arg0, Obj1 *arg1, int arg2) {
    char *v1 = (char *)arg1;
    int v0 = arg2 * 0x34;
    int b = arg1->bufIndex;
    int a1 = 1 - b;
    char *p0 = (b * 0x16C) + v1;
    p0 = p0 + v0;
    char *p1 = (a1 * 0x16C) + v1;
    p0 = p0 + 0x4C;
    p1 = p1 + v0;
    p1 = p1 + 0x4C;
    func_00459470(arg0, p1, p0, 0x16C);
    return arg0;
}
