#define F(p,t,o) (*(t *)((char *)(p)+(o)))
struct GetEntry { short delta,index; char *(*fn)(char *,int); };
struct IntEntry { short delta,index; int (*fn)(char *); };
static inline int query(char *p) {
 IntEntry *e=(IntEntry *)(F(p,char *,0)+0xa0);
 return e->fn(p+e->delta);
}
extern "C" int func_003744F0(char *self,char *arg1,int idx,unsigned mode,int active) {
 char *region=idx*0x19c+self;
 char *src=region+0x10;
 if((F(region,int,0x144)^9)!=0) return F(src,int,0x134);
 GetEntry *entry=(GetEntry *)(F(self,char *,0)+0xd8);
 char *p=entry->fn(self+entry->delta,idx);
 int result;
 if(mode!=0) {
 if(mode<5) {
  int state=F(src,int,0x128);
  result=1;
  if(state==2) result=2;
  if(F(src,int,0x138)==2) result=8;
  if(active) {
   if(p==F(src,char *,0x154)) {
    result=4;
    if(query(p)==3) result=1;
    state=F(src,int,0x128);
   }
   int change=p!=F(src,char *,0x158);
   if(p==F(src,char *,0x15c)) change=0;
   if(change && F(region,unsigned char,0x100)) {
    switch(state) {
    default: break;
    case 1: result=2; break;
    case 2: result=1; break;
    case 4: result=2; break;
    }
   }
   if(F(src,unsigned char,0xf4)) {
    switch(F(src,int,0x138)) {
    case 0: F(src,int,0x138)=1; break;
    case 1: F(src,int,0x138)=2; break;
    case 2:
    default: F(src,int,0x138)=0; break;
    }
   }
   switch(mode) {
   case 1: F(src,int,0x138)=3; break;
   case 4:
    if(F(src,int,0x138)==0) F(src,int,0x138)=1;
    break;
   }
   if(F(arg1,int,0xf0) && F(src,int,0x138)==0) F(src,int,0x138)=1;
   switch(state) {
   case 1:
    if(F(src,int,0x190)==2) result=2;
    break;
   case 2:
    if(F(src,int,0x190)==1) result=1;
    break;
   default: return result;
   }
  } else {
   if(F(arg1,int,0xbc)>0) { result=4; goto done; }
   goto done;
  }
  return result;
 }
 }
 {
  result=0;
  if(active) {
   if(p==F(src,char *,0x154)) {
    result=3;
    if(query(p)==3) result=0;
   }
  } else {
   result=F(arg1,int,0xbc)>0 ? 3 : 0;
  }
 }
 done:
 return result;
}
