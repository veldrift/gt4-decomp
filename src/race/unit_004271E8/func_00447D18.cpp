/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;
struct Db { char p[0x1E0]; int f1E0; int f1E4; };
extern Db D_006235A8;
extern "C" int func_00443DC0(void *, int);
extern "C" void func_00449CD8(int, int);

extern "C" void func_00447D18(int arg0) {
    if (func_00443DC0(&D_006235A8, 0x2A) != 0) {
        func_00449CD8(D_006235A8.f1E4, arg0);
        return;
    }
    func_00449CD8(D_006235A8.f1E0, arg0);
    return;
}
