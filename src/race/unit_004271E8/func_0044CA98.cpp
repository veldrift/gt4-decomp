extern int D_00623810;

extern "C" void func_00346610(int w, int h);
extern "C" void func_00394B10(int size);
extern "C" void func_00394C10(void);
void func_003B1CB8(void);
extern "C" void func_003ED948(int slot);
extern "C" void func_00462E10(void);

extern "C" void func_0044CA98(int arg0, int arg1, int arg2, int arg3) {
    D_00623810 = arg3;
    func_00394B10(arg3);
    func_003ED948(arg2);
    func_003B1CB8();
    func_00346610(arg0, arg1);
    func_00394C10();
    func_00462E10();
}
