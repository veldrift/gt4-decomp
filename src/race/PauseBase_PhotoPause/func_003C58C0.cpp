/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; float (*fn)(void *); };
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual float a(); virtual float b(); };
struct Self { char pad[0x1a8]; int mode; };
struct Global { char pad[0x39dd0]; int value; };
struct Value { float x[8]; };
struct Vec6 { float x[6]; Vec6() { x[0]=1.0f; x[1]=1.0f; x[2]=1.0f; x[3]=0.0f; x[4]=1.0f; x[5]=1.0f; } };
extern Global *D_00622F4C;
extern "C" Obj *func_003C3FA0() throw();
extern "C" void *func_003C3F98(Self *) throw();
extern "C" void func_0033DE30(void *, Value *);
extern "C" void func_003EFC10(Value *, float, float, float, float, float);
extern "C" void func_003EFCE8(Vec6 *, float, float, float, float, float, float);
extern "C" void func_003EFD80(Value *, Vec6 *);
extern "C" void func_003C58C0(Self *self) {
    Value value;
    Obj *o = func_003C3FA0();
    float a = o->a();
    float b = (float)D_00622F4C->value / 10.0f;
    b += 1.0f;
    float zero = 0.0f;
    float c = o->b();
    func_003EFC10(&value, a, zero, b, c, 5500.0f);
    switch(self->mode) {
    case 2: value.x[5] = 0.0f; break;
    case 1: {
        Vec6 v;
        func_003EFCE8(&v, 1.0f,1.0f,1.0f,0.0f,1.0f,0.6f);
        func_003EFD80(&value, &v);
        break;
    }
    case 4: {
        Vec6 v;
        func_003EFCE8(&v,1.5f,0.95f,0.6f,0.0f,1.0f,0.3f);
        func_003EFD80(&value,&v);
        break;
    }
    }
    func_0033DE30(func_003C3F98(self),&value);
}
