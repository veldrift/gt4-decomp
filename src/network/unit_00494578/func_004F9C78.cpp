/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
extern "C" int func_004F8BC8(void *, int *, int) throw();
extern "C" void func_004F9C08(Obj *, int) throw();

extern "C" void func_004F9C78(Obj *o, int n) {
    int buf[32];
    int cnt = func_004F8BC8((char *)o + 0xCD8, buf, n);
    int i;
    for (i = 0; i < cnt; i++) {
        func_004F9C08(o, buf[i]);
    }
}
