struct Obj { char pad[0x170]; int first; int second; };
extern "C" int func_003EF330(Obj *obj) { if (obj->first < obj->second) return 0; return 1; }
