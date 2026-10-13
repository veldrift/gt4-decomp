struct S;
struct Val;

extern "C" float func_00477460(S *arg0);
extern "C" void func_00476BC0(void *arg0, int arg1);
extern "C" void func_00478930(Val *self);

extern "C" void func_00478378(Val *arg0, int arg1) {
    int a = (int)func_00477460((S *)arg0);
    int b = (int)func_00477460((S *)arg1);
    if (b != 0) {
        return func_00476BC0(arg0, a % b);
    }
    func_00478930(arg0);
}
