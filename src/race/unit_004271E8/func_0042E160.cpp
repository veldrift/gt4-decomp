typedef int s32;
typedef unsigned char u8;

extern "C" void func_0042E1F0(void *p);
extern "C" void func_0042E230(void *p);
extern "C" void func_0042E3C8(void *p, s32 n);
extern "C" void func_004A1638(s32 n);
extern "C" void func_004A2808(s32 n, float f);

struct S42E160 {
    s32 m0;
    s32 m4;
    u8 m8;
    u8 m9;
    u8 mA;
};

extern "C" void func_0042E160(struct S42E160 *self) {
    s32 t;
    s32 a1;
    func_004A1638(6);
    func_004A2808(0x44, 0.0f);
    t = self->m8;
    switch (t) {
    case 1:
        func_0042E1F0(self);
        break;
    case 2:
    case 3:
    case 4:
        func_0042E230(self);
        break;
    default:
        return;
    }
    if (self->mA != 0) {
        a1 = self->m4;
    } else {
        a1 = self->m0;
    }
    func_0042E3C8(self, a1);
}
