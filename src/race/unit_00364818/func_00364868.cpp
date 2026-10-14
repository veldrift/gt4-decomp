/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char *p; unsigned char flag; };
extern "C" void func_00343490(void *);
extern "C" void GtbSetupTireTwistParameters(int) throw();
extern "C" void func_00361908(void *, void *, int, int, void *, void *) throw();
extern "C" void func_00364818(void *, void *) throw();
extern "C" void func_003F3B68(void *, int, int, int, int, void *);
extern char D_0069F780[];
extern char D_006203C8[];
extern "C" void func_00364868(Obj *arg0, int arg1, void *arg2) {
    char buf[0x20];
    func_00343490(buf);
    void *p = arg2 ? arg2 : buf;
    GtbSetupTireTwistParameters(0);
    func_003F3B68(arg0->p, arg1, 0, 0, 0, D_0069F780);
    char *q = arg0->p;
    func_00361908(q + 0x600, q, 0, 0, D_006203C8, p);
    func_00364818(arg0, p);
    arg0->flag = 0;
}
