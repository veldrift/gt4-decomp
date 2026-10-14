/* compiler: ee-gcc2.96-no-strict-aliasing */
#define FIELD(T,p,o) (*(T*)((char*)(p)+(o)))
struct Record { unsigned char kind, flag; unsigned short id; short first,last; };
extern "C" Record *func_004B59C0(void *,int) throw();
extern "C" Record *func_004B5A48(void *self,int index,int kind) {
 char *base=(char*)self+(1-FIELD(int,self,0x858))*0x41c;
 int *count=(int*)(base+0x234);
 char *records=base+0x20;
 if(index>=*count) return func_004B59C0(self,kind);
 for(int i=0;i<*count-index;i++) {
  char *position=records+(*count-i)*8;
  Record *src=(Record*)(position+0x210);
  Record *dst=(Record*)(position+0x218);
  dst->kind=src->kind;
  dst->flag=src->flag;
  dst->id=src->id;
  dst->first=src->first;
  dst->last=src->last;
 }
 ++*count;
 char *position=records+index*8;
 Record *dst=(Record*)(position+0x218);
 short prev=FIELD(short,position,0x224);
 dst->kind=kind;
 dst->first=prev;
 dst->last=prev;
 return dst;
}
