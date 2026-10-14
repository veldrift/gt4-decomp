extern "C" void func_0022ACC8(void *, int) throw();
extern "C" void func_0022AD20(void *, void *) throw();
extern "C" void func_00230F28(void *, void *);
extern "C" void func_00232C20(void *, int);
extern "C" void func_00232C78(void *, void *);
extern "C" void MRenderContext__setMousePositionOnFocus(void *unused, void *source, int n, void *name) {
    void *buf[4];
    void *v = 0;
    if (n > 0) {
        func_00232C78(buf, name);
        v = buf[0];
        func_00232C20(buf, 2);
    }
    func_0022AD20(buf, source);
    func_00230F28(buf[0], v);
    func_0022ACC8(buf, 2);
}
