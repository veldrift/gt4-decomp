struct Arg { long x; };
struct Data { int x[3]; };
struct Obj { int x,used,handle; Data data; int value,result; };
extern "C" void func_00520D58(Data*) throw();
extern "C" Obj *func_00522098();
extern "C" void func_005220D8(Obj*);
extern "C" int func_00522718(int*,Arg,int*,Data*,int*);
extern "C" int func_00520D88(Obj **out,long arg,int value,Data *input) {
 *out=0;
 Arg saved;
 saved.x=arg;
 Obj *o=func_00522098();
 if(!o) return 3;
 Data *d=&o->data;
 if(input) *d=*input;
 else func_00520D58(d);
 o->value=value;
 int r=func_00522718(&o->handle,saved,&o->value,d,&o->result);
 if(r) {func_005220D8(o); return r;}
 *out=o;
 o->used=1;
 return r;
}
