/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int MboolReader__structor_8(int) throw();
extern "C" void func_00265DA8(void *, int);
extern "C" int func_00267698(void *);
extern "C" void func_002676A8(void *, int);
extern "C" void func_002624E0(void *self, int arg) {
    int v = MboolReader__structor_8(arg);
    func_00265DA8(self, v);
    if (func_00267698(self)) func_002676A8(self, v != 0 ? 1 : 2);
}
