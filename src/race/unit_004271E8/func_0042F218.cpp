typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef long long s64;

struct Cmd0042F218 { u8 type; u8 x; s16 n; s32 pad; s64 handle; };

extern "C" s64 func_00447BB8(const char *s);
extern "C" void func_0042F0E0(void *self, Cmd0042F218 *c);

extern "C" void func_0042F218(void *self, const char *input, u8 x, s32 n) {
    Cmd0042F218 c;
    if (n > 0xFFFF) {
        n = 0xFFFF;
    }
    c.type = 2;
    c.x = x;
    c.n = (s16)n;
    c.handle = func_00447BB8(input);
    func_0042F0E0(self, &c);
}
