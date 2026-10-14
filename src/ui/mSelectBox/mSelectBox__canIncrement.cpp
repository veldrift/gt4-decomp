typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct C {
    char pad[1];
};

struct Obj {
    char pad[1];
};

struct mSelectBox {
    char pad0[0xB0];
    s32 unkB0;      /* 0xB0 */
    char padB4[0x20];
    f32 unkD4;      /* 0xD4 */
    char padD8[0xC];
    f32 unkE4;      /* 0xE4 */
    f32 unkE8;      /* 0xE8 */
    f32 unkEC;      /* 0xEC */
};

extern "C" f32 mWidget__getWindowW(struct C *arg0);
extern "C" f32 mWidget__getWindowH(struct C *arg0);
extern "C" f32 func_002D4980(Obj *arg0);
extern "C" s32 func_0057CE60(Obj *arg0);
extern "C" bool func_0057CEC8(Obj *o);

extern "C" s32 mSelectBox__canIncrement(struct mSelectBox *arg0) {
    Obj *sub = (Obj *)((char *)arg0 + 0xBC);
    f32 f21;
    f32 f22;
    f32 f20;
    s32 t;
    s32 n;

    if (func_0057CEC8(sub)) {
        return 0;
    }
    t = arg0->unkB0;
    if (t == 0) {
        f21 = arg0->unkE4;
    } else {
        f21 = arg0->unkE8;
    }
    if (t == 0) {
        f22 = mWidget__getWindowW((struct C *)arg0);
    } else {
        f22 = mWidget__getWindowH((struct C *)arg0);
    }
    f20 = f21 + func_002D4980((Obj *)arg0);
    n = func_0057CE60(sub) - 1;
    return f22 < (arg0->unkEC + ((f20 * (f32)n) + (f21 * arg0->unkD4)));
}
