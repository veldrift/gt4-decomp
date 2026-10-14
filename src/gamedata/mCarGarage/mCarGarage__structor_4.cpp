struct Obj { int base; void *table; int f8; int fC; int owned; void * car; char storage[4]; };
extern "C" char mCarGarage__vtable[];
extern "C" int hObject__structor_0(Obj *);
extern "C" void func_00449D58(void *);
extern "C" int func_00146628(Obj *);
extern "C" int func_00145AD8(Obj *, int);
extern "C" void *exception__structor_0(int);
extern "C" void func_0043DC98(void *, int);
extern "C" void func_0043DC20(void *);
extern "C" int mCarGarage__structor_4(Obj *self, int value) {
hObject__structor_0(self); self->table=mCarGarage__vtable; self->owned=1; void *car=exception__structor_0(0x4C0); func_0043DC98(car,value); self->car=(void *)car; func_00449D58((char *)self+0x18); return func_00146628(self);
}
