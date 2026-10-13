extern "C" void func_00546D38(void *);
extern "C" void func_00546E00(void *, int, int);
extern "C" void func_00546F98(void *, int, int);

extern "C" void func_00542DA8(int arg0, int arg1, int arg2, int arg3) {
    char buf[0x60];
    func_00546D38(buf);
    func_00546E00(buf, arg0, arg1);
    func_00546F98(buf, arg2, arg3);
}
