typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Obj_0010AB78 {
    char pad0[0xAC];
    s32 state;
    f32 f;
};

struct Self {
    s32 pad0;
    void *link;
    s32 result;
};

extern "C" void func_0010AB78(struct Obj_0010AB78 *arg0);
extern "C" void func_00548850(s32 *arg0, s32 *arg1);

static inline s32 atLeast3(s32 x)
{
    if ((u32)x < 3)
        return 0;
    return 1;
}

extern "C" void func_00104150(Self *arg0, Obj_0010AB78 *arg1, f32 fparg0)
{
    s32 t[2];
    f32 d = fparg0 * 0x1.68p+9f;
    arg1->f = arg1->f + d;
    if (arg1->state == 2 && arg0->link != 0) {
        func_0010AB78(arg1);
    }
    func_00548850(t, t + 1);
    s32 v = 0;
    if (t[0] != 0) {
        v = atLeast3(t[1]);
    }
    arg0->result = v;
}
