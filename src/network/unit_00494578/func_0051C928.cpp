typedef unsigned char u8;
struct M { u8 a, b; M(int type, int enabled) { a = type; b = enabled != 0; } };
struct V { char p[0x80]; int f80; };
extern "C" int func_0051BE28(void) throw();
extern "C" int func_0051BE60(void) throw();
extern "C" V *func_0051DD88(int);
extern "C" int func_0051E158(int, unsigned, int, const void *, unsigned, int);
extern "C" long func_0051C928(int a, int b) {
    long result = func_0051BE28();
    if (result == 0) {
        V *v = func_0051DD88(a);
        long status = 2;
        if (v != 0) {
            M m(2, b);
            status = func_0051E158(v->f80, 13, 65535, &m, 2, 0);
        }
        func_0051BE60();
        result = status;
    }
    return result;
}
