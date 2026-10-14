/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_001CB850(void *) throw();
extern "C" int func_001D1950(void *, void *, const char *);
extern "C" int func_001D1598(void *, void *, int);
extern "C" char D_006952C8[], D_00660CD8[];
struct Obj {
    char *vt;
    char pad[0x4c];
    Obj(void *p) { func_001D1950(this, p, D_006952C8); }
    ~Obj() { vt = D_00660CD8; }
};
extern "C" int func_001D1528(void *arg0, int arg1) {
    char buf[0x40];
    func_001CB850(buf);
    Obj obj(buf);
    func_001D1598(&obj, arg0, arg1);
}
