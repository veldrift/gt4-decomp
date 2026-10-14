extern "C" int func_0051BE28() throw();
extern "C" int func_0051BE60() throw();
extern "C" void func_0051DB90(int);
extern unsigned int D_0064AE10;
extern "C" int func_0051C240() {
    int r = func_0051BE28();
    if (r != 0) return r;
    for (unsigned int i = 0; i < D_0064AE10; i++) func_0051DB90(i);
    func_0051BE60();
    return 0;
}
