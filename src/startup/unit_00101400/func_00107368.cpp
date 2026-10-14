typedef int s32;
typedef unsigned int u32;
struct O {
    s32 f0;
    u32 f4;
    s32 f8;
    char pad0[0x24 - 0xC];
    s32 f24, f28, f2C;
    char pad1[0x34 - 0x30];
    s32 f34, f38;
};
extern "C" void func_00106258(void *, s32, s32) throw();
extern "C" void func_001063F0(void *);
extern "C" void func_00106748(void *);
extern "C" void func_00106EE8(void *, s32, s32, s32, s32);
extern "C" void func_001072A8(void *);
extern "C" void func_004A0808(s32, s32, s32);

extern "C" void func_00107368(O *o) {
    if (o->f28 > 0) o->f28 = o->f28 - 1;
    s32 s1 = o->f24;
    if (s1 != 0) {
        if (s1 != 2) {
            if (s1 < 3) {
                if (s1 != 1) {
                    o->f24 = s1 * 2;
                } else {
                    func_00106258(o, o->f34, o->f38);
                    switch (o->f4) {
                    case 2:
                    case 3:
                        if (o->f8 != s1) {
                            func_00106EE8(o, o->f2C, o->f34, o->f38, 0);
                        } else if (o->f34 == 0x200) {
                            func_00106748(o);
                        } else {
                            func_001063F0(o);
                        }
                        break;
                    case 0:
                    case 0x50:
                        func_00106EE8(o, o->f2C, o->f34, o->f38, 0);
                        break;
                    case 0x52:
                        break;
                    case 0x51:
                        func_00106EE8(o, o->f2C, o->f34, o->f38 / 2, 1);
                        break;
                    }
                    func_001072A8(o);
                    s1 = o->f24;
                    o->f24 = s1 * 2;
                }
            } else {
                o->f24 = s1 * 2;
            }
        } else {
            func_004A0808(o->f0, o->f4, o->f8);
            func_001072A8(o);
            s1 = o->f24;
            o->f24 = s1 * 2;
        }
    }
}
