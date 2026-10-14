/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    int f0;
    int f4;
    void *f8;
    int fC;
    int f10;
    int f14;
    char f18[1];
};
extern "C" void func_00107B58(Obj *, int) throw();
extern "C" void func_00107B98(Obj *) throw();
extern "C" void pgluTexReset(void *);
extern "C" void pgluTexImage(void *, int, unsigned int, unsigned int, int);
extern "C" void func_0049AF00(void *, int, int);
extern "C" void func_0049AFD0(void *, unsigned int, int);
extern "C" void func_0049B148(void *, int, int, int);
extern "C" int func_0049B220(unsigned int, int, int, int *);
extern "C" unsigned char func_004A07F8(void);
extern "C" void func_004A2038(int);
extern "C" void func_004A4910(void);
extern "C" void func_004A4F48(int, int, int, int, int, int, int, int);
extern "C" void func_004A50C0(int, int, int, int, int, int, int, int);

extern "C" void func_00107C80(Obj *obj, unsigned int psm, int w, int h, int extra) {
    int outw;
    int r = func_0049B220(psm, w, h, &outw);
    func_00107B98(obj);
    func_00107B58(obj, r);
    if (func_004A07F8()) {
        func_004A4F48(obj->f0, psm, outw, 0, 0, w, h, extra);
        func_004A2038(1);
        func_004A4910();
    } else {
        func_004A50C0(obj->f0, psm, outw, 0, 0, w, h, extra);
    }
    void *sub = obj->f18;
    obj->fC = 1;
    obj->f8 = sub;
    pgluTexReset(sub);
    pgluTexImage(obj->f8, 0, obj->f0, psm, outw);
    func_0049AF00(obj->f8, w, h);
    func_0049B148(obj->f8, 0, 0, w - 1);
    func_0049B148(obj->f8, 1, 0, h - 1);
    func_0049AFD0(obj->f8, 4, 1);
    func_0049AFD0(obj->f8, 5, 1);
}
