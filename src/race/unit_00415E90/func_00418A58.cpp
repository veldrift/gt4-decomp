struct Obj { float x; float y; float z; int fieldC; char inner[4]; };
extern "C" void func_00421D30(void *, float, float, float);
extern "C" void func_00418A58(Obj *obj) { func_00421D30(obj->inner, obj->x, obj->y, obj->z); }
