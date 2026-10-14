/* compiler: ee-gcc2.96-no-strict-aliasing */
union Record { struct { unsigned char kind,flag; unsigned short id; short first,last; } m; int words[2]; };
extern char D_006B04A8[];
extern "C" int func_004B4628(int,int,int,int,char*) throw();
extern "C" int func_004B5C58(void *,Record *);
extern "C" void func_004B5D48(void *,int,Record *);
#define I(p,o) (*(int *)((char *)(p)+(o)))
static inline Record *record(char *bank,int i) {
 unsigned int address=i*8;
 address+=(unsigned int)bank;
 return (Record *)(address+0x218);
}
extern "C" void func_004B5B38(char *self,Record *item) {
 char *base=self+(1-I(self,0x858))*0x41c;
 char *bank=base+0x20;
 int *count=(int *)(base+0x234);
 int end=func_004B4628(I(bank,8),I(self,4),item->m.first,item->m.last-item->m.first,D_006B04A8);
 func_004B5D48(self,end,item);
 int i=func_004B5C58(self,item);
 for(; i<*count-1; ++i) {
  char *p=(char *)((unsigned int)(i*8)+(unsigned int)bank);
  p[0x218]=p[0x220];
  p[0x219]=p[0x221];
  *(unsigned short *)(p+0x21a)=*(unsigned short *)(p+0x222);
  *(unsigned short *)(p+0x21c)=*(unsigned short *)(p+0x224);
  *(unsigned short *)(p+0x21e)=*(unsigned short *)(p+0x226);
 }
 char *last=bank+*count*8;
 last[0x210]=0;
 --*count;
}
