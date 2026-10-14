/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x5a8]; char *buffer; };
struct Data { char pad[0x18]; int mode; char rest[0xa0]; };
extern char D_00645570[];
extern char D_006C0E98[];
extern "C" int func_004F0C38(Obj *,const char *);
extern "C" int func_004F0B08(Obj *,Data *);
extern "C" void func_004F87E8(Obj *,int) throw();
struct Guard { Obj *obj; Data *data; Guard(Obj *o,Data *d): obj(o),data(d) {} ~Guard() { func_004F0B08(obj,data); } };
extern "C" void func_00500B20(Data *data, Obj *obj) {
 if (!obj) obj = (Obj *)D_00645570;
 Guard guard(obj,data);
 if (func_004F0C38(obj,D_006C0E98)) return;
 int handled=0;
 if (data->mode<0 || data->mode==1) { func_004F87E8(obj,data->mode); handled=1; }
 if (handled) return;
 *(Data *)(obj->buffer+0x1d8) = *data;
 func_004F87E8(obj,data->mode);
}
