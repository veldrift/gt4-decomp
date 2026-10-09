struct Obj { char pad0[0x10360]; int first; char pad10364[0x14B7C]; int second; int third; };
extern "C" void func_003BC5A8(Obj *obj, int value) { obj->second = value; obj->third = 0; obj->first = value; }
