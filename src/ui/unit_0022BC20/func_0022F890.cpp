struct VEntry{short adjustment,pad;void(*function)(void*,void*);};
struct Object{int unused;VEntry* table;};
struct Vector{int allocator;unsigned int start,finish,capacity;};
extern "C" int func_00265F38(Object*);
extern "C" void func_00576788(void*),func_005767C0(void*),func_005DAE00(void*,Object**,Object* const*);
extern "C" void func_0022F890(unsigned char* self,Object* source){
 if(!func_00265F38(source)){
  VEntry* entry=source->table+90;entry->function((char*)source+entry->adjustment,self);
  func_00576788(self+0x48);
  Vector* vec=(Vector*)(self+0x34);
  if(vec->finish!=vec->capacity){if(vec->finish)*(unsigned int*)vec->finish=(unsigned int)source;vec->finish+=4;}
  else func_005DAE00(vec,(Object**)vec->finish,&source);
  func_005767C0(self+0x48);
 }
}
