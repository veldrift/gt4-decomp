struct Obj { int state; float value; };
extern "C" int func_00375E48(Obj *obj, float value) { if (obj->state < 0) return 1; return obj->value <= value; }
