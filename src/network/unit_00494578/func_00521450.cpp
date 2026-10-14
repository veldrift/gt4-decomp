typedef int s32;
struct Obj { char pad[8]; s32 fd; s32 state; };
extern "C" s32 func_005220F8(Obj *);
extern "C" s32 func_005221B0(s32, s32, s32);
extern "C" s32 func_00522FF0(s32, s32 *, s32 *, s32 *);
extern "C" s32 func_00521450(Obj *o, s32 *ready, s32 *addr, s32 *port) {
    *ready = 0;
    if (func_005220F8(o) == 0) return 2;
    if (o->state != 3) return 0xC355;
    s32 r = func_00522FF0(o->fd, ready, addr, port);
    if (r != 0) return r;
    if (*ready != 0) func_005221B0(0, 0x1C, 0);
    return 0;
}
