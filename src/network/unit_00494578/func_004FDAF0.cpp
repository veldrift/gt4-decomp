/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { int words[0x1dc/4]; int kind; int mode; char name[4]; };
struct Block { int words[0x1fc/4]; };
struct Obj { char pad[0x5a8]; char *buffer; };
extern char D_00645570[],D_006C0D20[];
extern "C" int func_004F0C38(Obj *,const char *);
extern "C" int func_004F0B08(Obj *,char *);
extern "C" void func_004F87E8(Obj *,int) throw();
extern "C" int func_004FDAF0(Data *data,Obj *obj) {
 if(!obj) obj=(Obj *)D_00645570;
 if(func_004F0C38(obj,D_006C0D20)) return func_004F0B08(obj,data->name);
 int handled=0;
 if(data->mode<0 || data->mode==1) { func_004F87E8(obj,data->mode); handled=1; }
 if(handled) return func_004F0B08(obj,data->name);
 *(Block *)(obj->buffer+0x1d8)=*(Block *)data;
 func_004F87E8(obj,data->mode);
 switch(data->kind) {
 case 0: func_004F87E8(obj,-965); func_004F0B08(obj,data->name); break;
 case 1: break;
 case 2: break;
 case 3: func_004F0B08(obj,data->name); break;
 }
}
