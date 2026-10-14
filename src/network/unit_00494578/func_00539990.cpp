struct S{unsigned char state;char pad[3];int count,id;};
extern int func_00539BE0(int*);
extern int func_00539BA8(void*);
extern "C" int func_00539990(S* self,int* remaining){
 if(!self)return 2;
 if(self->state!=1)return 2;
 int id;
 int result=func_00539BE0(&id);
 if(result)return result;
 if(id!=self->id)return 0x385;
 if(!self->count)return 0x386;
 --self->count;
 if(remaining)*remaining=self->count;
 if(!self->count){
  self->id=0;
  result=func_00539BA8(self);
  if(result)return result;
 }
 return 0;
}
