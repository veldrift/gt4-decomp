/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[43]; };
struct Data { Block block; int mode; int rest[6]; };
struct Obj { char pad[0x5a8]; char *buffer; char pad2[0xa44-0x5ac]; Block block; };
extern char D_00645570[];
extern char D_006C0D08[];
extern "C" int func_004F0C38(Obj *,const char *);
extern "C" int func_004F0B08(Obj *,char *);
extern "C" void func_004F87E8(Obj *,int) throw();
struct Guard { Obj *obj; char *data; Guard(Obj *o,char *d): obj(o),data(d) {} ~Guard() { func_004F0B08(obj,data); } };
extern "C" void func_004FD778(Data *data, Obj *obj) {
 if (!obj) obj = (Obj *)D_00645570;
 Guard guard(obj,(char *)data+0xb0);
 if (func_004F0C38(obj,D_006C0D08)) return;
 int handled=0;
 if (data->mode<0 || data->mode==1) { func_004F87E8(obj,data->mode); handled=1; }
 if (handled) return;
 *(Data *)(obj->buffer+0x1d8) = *data;
 func_004F87E8(obj,data->mode);
 obj->block=data->block;
}
