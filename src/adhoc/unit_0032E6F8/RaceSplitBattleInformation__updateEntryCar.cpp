struct func_003B4F18_arg1;

struct Obj {
    char pad0[0x14];
    unsigned int unk14;
};

extern "C" void func_003B4F18(Obj *arg0, struct func_003B4F18_arg1 *arg1);
extern "C" void func_005F29E8(Obj *arg0, int arg1);

extern "C" void func_0032EFA0(char *arg0, Obj *arg1) {
    unsigned int n = arg1->unk14;
    if (n < 2) {
        return func_003B4F18(arg1, (struct func_003B4F18_arg1 *)(arg0 + n * 0x190 + 0x130));
    }
    func_005F29E8((Obj *)arg0, (int)n);
}
