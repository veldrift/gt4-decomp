struct Handle {
    int w[4];
};

struct Obj {
    char pad0[0x74];
    void *f74;
};

extern "C" Handle *func_002EEEB0(Handle *ret, void *self, Handle *x);
extern "C" void func_00309378(void *arg0, int arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);

extern "C" void func_002ECE50(void *arg0, void *arg1) {
    Handle h0;
    Handle h1;
    void *s1 = ((Obj *)arg0)->f74;
    func_00314B20(&h1, arg1);
    func_002EEEB0(&h0, s1, &h1);
    func_00309378(&h0, 2);
    func_00312318(&h1, 2);
}
