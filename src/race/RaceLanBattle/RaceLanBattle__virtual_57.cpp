struct Obj { char pad[0x1AA0]; int state; };
extern "C" void func_00346DA0(void *, void *, int);
extern "C" void RaceLanBattle__virtual_57(void *obj, Obj *other) { other->state = 1; func_00346DA0((char *)obj + 0xF258, other, 1); }
