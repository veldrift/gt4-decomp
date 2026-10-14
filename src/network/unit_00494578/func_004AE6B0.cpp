struct Result { int words[5]; };
struct Entry { short adjustment; short unused; void (*call)(void*); };
struct Obj { char unknown[116]; int mode; char gap[12]; Result result; char tail[16]; Entry* table; };
struct Temp { char bytes[172]; ~Temp(); };
extern "C" void func_004AF6B8(Result*);
extern "C" void func_004AEFF0(Temp*);
extern "C" Obj* func_004AE1F8(Temp*,int);
extern "C" void func_004AF568(Obj*);
extern "C" void func_004AF0A0(Temp*,int);
inline Temp::~Temp() { func_004AF0A0(this,2); }
inline void call_entry(Obj* obj,int index) { Entry* e=obj->table+index; e->call((char*)obj+e->adjustment); }
extern "C" Result func_004AE6B0(int input) {
 Result result;
 func_004AF6B8(&result);
 Temp temp;
 func_004AEFF0(&temp);
 Obj* obj=func_004AE1F8(&temp,input);
 if(obj) {
  obj->mode=2;
  call_entry(obj,2);
  call_entry(obj,4);
  result=obj->result;
  func_004AF568(obj);
 }
 return result;
}
