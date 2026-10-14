struct Owner {int unknown0;unsigned flags;float x,y;};
struct Display;
extern Display* PDISTD__global_font_manager;
extern "C" void func_0044E1E0(Owner*,unsigned);
extern "C" void func_00491418(Display*,const char*,__builtin_va_list,int,int);
extern "C" void func_0044E348(Owner*);
extern "C" void func_0044E088(Owner* self,const char* format,...) {
 func_0044E1E0(self,self->flags);
 __builtin_va_list args;__builtin_stdarg_start(args,format);
 func_00491418(PDISTD__global_font_manager,format,args,1,0);
 __builtin_va_end(args);
 func_0044E348(self);
}
