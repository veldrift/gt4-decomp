struct Obj { char pad0[4]; int enabled; char pad8[0x58]; int value; };
extern "C" int func_00346A28(Obj *obj) { if (obj->enabled) return obj->value; return 0; }
