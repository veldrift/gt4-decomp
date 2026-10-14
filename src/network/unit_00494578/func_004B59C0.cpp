#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))
struct Record{unsigned char kind;char pad[3];short first,last;};
extern "C" Record* func_004B59C0(void* self,int kind){
 char* base=(char*)self+(1-FIELD(int,self,0x858))*0x41c;
 int* count=(int*)(base+0x234);
 char* records=base+0x20;
 if(*count==0){Record* item=(Record*)(base+0x238);item->kind=kind;item->last=0;item->first=0;}
 else{
  char* position=records+*count*8;
  short previous=FIELD(short,position,0x216);
  Record* current=(Record*)(position+0x218);
  current->kind=kind;current->first=previous;current->last=previous;
 }
 ++*count;
 return (Record*)(records+*count*8+0x210);
}
