struct Obj { int header; int values[8]; };
extern "C" void func_0043B5D8(Obj *obj) { for (int i = 7; i >= 0; i--) obj->values[i] = 0; }
