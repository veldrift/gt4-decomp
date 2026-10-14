/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { char data[8]; };
extern Blob D_006A2578;
extern "C" int func_00446E50(void *);
extern "C" void func_00446F70(void *, char *);
extern "C" void func_005A609C(char *, const char *);
extern "C" char *func_003B5B80(char *self, char *dst) {
    char *name = self + 0x35BC;
    if (*name) {
        func_005A609C(dst, name);
    } else if (func_00446E50(self + 0x20)) {
        *(Blob *)dst = D_006A2578;
    } else {
        func_00446F70(self + 0x20, dst);
    }
    return dst;
}
