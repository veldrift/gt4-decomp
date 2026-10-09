struct Obj { char pad[8]; int count; };
extern "C" void func_004A5400();
extern "C" void func_0042C848(Obj *obj) { obj->count--; func_004A5400(); }
