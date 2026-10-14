union Record{struct {unsigned char kind;char pad[3];short first,last;};int words[2];};
extern int func_004B5C58(void*,Record*);
#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))
inline Record* record(char* base,int i){unsigned int address=i*8;address+=(unsigned int)base;return (Record*)(address+0x218);}
extern "C" void func_004B5D48(void* self,int end,Record* item){
 int delta=end-item->last;
 item->last=end;
 int index=func_004B5C58(self,item)+1;
 char* bank=(char*)self+(1-FIELD(int,self,0x858))*0x41c+0x20;
 for(;index<FIELD(int,bank,0x214);++index){
  Record* next=record(bank,index);
  next->first+=delta;next->last+=delta;
 }
}
