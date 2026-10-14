/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int words[0x9c/4]; };
struct Data { int prefix[6]; Block block; };
struct Obj { char pad[0x5a8]; char *buffer; };
extern Obj D_00645570;
extern char D_006C0E18[];
extern Block D_006493F4;
extern "C" int func_004F0C38(Obj *,const char *);
extern "C" int func_004F0B08(Obj *,Data *);
struct Guard { Obj *obj; Data *data; Guard(Obj *o,Data *d): obj(o),data(d) {} ~Guard() { func_004F0B08(obj,data); } };
extern "C" void func_00500198(Data *data,Obj *obj) {
 if(!obj) obj=&D_00645570;
 Guard guard(obj,data);
 if(func_004F0C38(obj,D_006C0E18)) return;
 *(Data *)(obj->buffer+0x1d8)=*data;
 D_006493F4=data->block;
}
