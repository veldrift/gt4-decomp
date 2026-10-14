struct Data { int a, b; } __attribute__((aligned(8)));
struct Obj { char pad0[0x74]; int state; char pad78[0x1C]; void (*cb)(struct Obj *, int, long, int, void *); void *user; };
extern "C" void func_0052D0E8(int arg0, int arg1, int arg2, volatile long arg3, int arg4, struct Obj *arg5) {
    if (arg5 != 0) {
        arg5->state = 0;
        arg5->cb(arg5, arg1, *(long *)&arg3, arg4, arg5->user);
    }
}
