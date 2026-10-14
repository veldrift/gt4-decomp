typedef unsigned char u8;
typedef int s32;
typedef long long s64;

struct Packet0042F2E0 { u8 kind; u8 a; u8 b; s32 value; s64 data; };

extern "C" s64 func_00447C50(const char *arg);
extern "C" void func_0042F0E0(void *self, Packet0042F2E0 *p);

extern "C" void func_0042F2E0(void *self, const char *arg, u8 a, u8 b, s32 value) {
    Packet0042F2E0 p;
    p.kind = 4;
    p.data = func_00447C50(arg);
    p.a = a;
    p.b = b;
    p.value = value;
    func_0042F0E0(self, &p);
}
