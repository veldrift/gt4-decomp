struct Obj { char pad[0x10]; int first; int second; };
extern "C" void func_003B70E0(Obj *obj, int first, int second) { obj->first = first; obj->second = second; }
