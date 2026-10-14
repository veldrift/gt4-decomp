extern "C" int func_0053B5E0(const char *, const char *, int) throw();
extern "C" int func_0053BB70(char *, int, void *) throw();
extern "C" unsigned func_0057F260(const char *) throw();
extern "C" void func_005A6AB0(void *, const void *, int);
extern "C" void func_005A6900(void *, const void *, int);
extern char D_006C3C48[];
extern "C" int func_0053BC28(char *self, int kind, char *out) {
    char *path = self + 0x1104;
    if (kind != 0x1000) {
        path = self + 0xD04;
        if (kind != 0x800) return 2;
    }
    if (func_0053B5E0(path, D_006C3C48, 4) == 0) {
        func_005A6AB0(out, path, 0x800);
        return 0;
    }
    char *base = self + 4;
    if (func_0053B5E0(base, D_006C3C48, 4) == 0) {
        func_005A6AB0(out, base, 0x800);
        func_005A6900(out, path, 0x800);
        return 0;
    }
    int count = 0;
    unsigned i = 0;
    func_0053BB70(self, kind, out);
    for (; i < func_0057F260(out); i++) {
        if (out[i] == '/') {
            count++;
            if (count == 3) {
                func_005A6AB0(out + i, path, 0x800 - i);
                break;
            }
        }
    }
    return 0;
}
