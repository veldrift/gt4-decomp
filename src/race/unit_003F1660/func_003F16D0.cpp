extern "C" unsigned char D_006224A8;
struct Obj { char pad[0x1B8]; unsigned char flags; };
extern "C" void func_003F16D0(Obj *obj) { if (D_006224A8) obj->flags &= 0xCF; else obj->flags &= 0xF; }
