struct Obj { int base; void *table; int f8; int fC; int owned; void * car; char storage[4]; };
extern "C" char D_0065B408[];
extern "C" int func_0030A678(Obj *);
extern "C" void func_00449D58(void *);
extern "C" int func_00146628(Obj *);
extern "C" int func_00145AD8(Obj *, int);
extern "C" void *func_005C1498(int);
extern "C" void func_0043DC98(void *, int);
extern "C" void func_0043DC20(void *);
extern "C" int func_00147F10(Obj *self, int value) {
func_0030A678(self); self->table=D_0065B408; self->owned=1; void *car=func_005C1498(0x4C0); func_0043DC98(car,value); self->car=(void *)car; func_00449D58((char *)self+0x18); return func_00146628(self);
}
