struct Obj { char pad[0x168]; unsigned char value; };
extern "C" int func_004468E0(Obj *obj) { if (obj->value != 0) return obj->value; return -1; }
