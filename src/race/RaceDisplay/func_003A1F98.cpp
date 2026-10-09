struct Obj { char pad[0x5C]; unsigned int flags; };
extern "C" int func_003A1F98(Obj *obj) { if (obj->flags & 4) return 1; return 0; }
