/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

struct State {
    char a;
    u8 combined;
    u8 value;
    s8 time;
    u8 idx;
    s8 level;
    u8 mode;
};
struct Sub {
    char pad0[0x440];
    u8 u440;
    char pad441[0x4B1 - 0x441];
    u8 u4B1;
    u8 u4B2;
    char pad4B3[0x5A0 - 0x4B3];
    float f5A0;
};
struct S {
    char pad0[4];
    s32 unk4;
    char pad8[0x5B3 - 8];
    s8 s5B3;
    char pad5B4[0x6FE - 0x5B4];
    u8 u6FE;
    char pad6FF[0x788 - 0x6FF];
    State st;
};

extern u8 D_006208A0[];

extern "C" s32 func_0035C7C8(S *) throw();
extern "C" s32 func_0035C828(S *) throw();
extern "C" void func_0035C848(S *, s32, s32) throw();
extern "C" s32 func_0035C938(S *) throw();
extern "C" s32 func_0035C980(S *) throw();
extern "C" s32 func_0035C9B0(s32) throw() __attribute__((const));
extern "C" s32 func_0035C9E0(S *) throw();
extern "C" s32 func_004149D8(s32, s32, void *);

extern "C" void func_0035CA60(S *arg0) {
    if (func_0035C7C8(arg0) != 0) {
        State *st = &arg0->st;
        Sub *b = (Sub *)((char *)arg0 + 0x104);
        s32 sp[4];
        st->mode = 0;
        s32 r = func_004149D8(arg0->unk4 + 0xCD7C, b->u440, sp);
        if (b->u4B2 != 0) {
            if (arg0->s5B3 == 1)
                func_0035C848(arg0, 2, 0);
            else
                func_0035C848(arg0, 7, 0);
        } else if (arg0->u6FE == 1) {
            func_0035C848(arg0, 6, 0);
        } else if (b->u4B1 & 0x10) {
            func_0035C848(arg0, 3, 0);
        } else if (r == 5) {
            func_0035C848(arg0, 1, 0x78);
        } else if (b->f5A0 == 1.0f) {
            func_0035C848(arg0, 2, 0x78);
        } else if (func_0035C9E0(arg0) != 0) {
            func_0035C848(arg0, 0xA, 0);
        } else if (st->value == 0) {
            func_0035C848(arg0, 0, -1);
        }
        if (st->value != 0) {
            if (st->value != 0xFF) {
                --st->value;
                if (st->value == 0) func_0035C848(arg0, 0, -1);
            }
        }
        if (st->time > 0) {
            st->time = st->time - 1;
            if (D_006208A0[func_0035C828(arg0)] == 0 && st->time < 0x19) st->time = 0;
        }
        s32 t = func_0035C938(arg0);
        if (t != 0) {
            if (func_0035C9B0(st->idx) == 0) {
                if (t == 1) {
                    st->level++;
                    if (st->level > 30) st->level = 30;
                } else {
                    st->level--;
                    if (st->level < -30) st->level = -30;
                }
            }
        } else if (func_0035C9B0(st->idx) == 0) {
            if (st->level > 0) st->level--;
            else if (st->level < 0) st->level++;
        }
        if (st->level == 0) {
            if (func_0035C980(arg0) != 0 || func_0035C9B0(st->idx) != 0) {
                st->idx++;
                if (st->idx >= 0x30) st->idx = 0;
            }
        }
    }
}
