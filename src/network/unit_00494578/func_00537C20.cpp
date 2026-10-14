struct Input { unsigned char c0,c1; char pad2[2]; unsigned short size; char pad6[2]; unsigned char c8; char pad9[3]; unsigned len; };
struct Key { int owner, id; int kind; unsigned char c0,c1; char padE[2]; };
struct Entry { unsigned state; int size; unsigned len; int fC; Key key; int f20; char *buf24, *buf28; };
extern Entry D_0086A8D8[64];
extern "C" char *func_005316F8(unsigned) throw();
extern "C" void func_00531738(char **);
extern "C" Entry *func_00537C20(int owner,int id,Input *in) {
 unsigned freeIndex=-1;
 Entry *result=0;
 if (!((unsigned)(id+1)<65 || id==65535)) {
     return result;
 }
 for(unsigned i=0;i<64;i++) {
  Entry *e=&D_0086A8D8[i];
  switch(e->state) {
   case 2: {
    if(owner==D_0086A8D8[i].key.owner && id==D_0086A8D8[i].key.id && in->size==D_0086A8D8[i].size && in->len==D_0086A8D8[i].len && in->c8==(unsigned char)D_0086A8D8[i].key.kind && in->c0==D_0086A8D8[i].key.c0 && in->c1==D_0086A8D8[i].key.c1) result=e;
   } break;
   case 0:
    if(freeIndex==-1U) freeIndex=i;
    break;
   default: {
    func_00531738(&D_0086A8D8[i].buf28);
    func_00531738(&D_0086A8D8[i].buf24);
    e->state=0;
    freeIndex=(freeIndex==-1U) ? i : freeIndex;
   }
  }
 }
 if(!result && freeIndex!=-1U) {
  unsigned short size=in->size;
  result=&D_0086A8D8[freeIndex];
  result->state=2;
  result->key.owner=owner;
  result->size=size;
  unsigned len=in->len;
  result->key.id=id;
  result->fC=0;
  result->len=len;
  result->key.kind=in->c8;
  result->key.c0=in->c0;
  result->key.c1=in->c1;
  result->buf28=func_005316F8(in->len);
  result->buf24=func_005316F8(in->size);
  if(!result->buf28 || !result->buf24) {
   func_00531738(&result->buf28);
   func_00531738(&result->buf24);
   result->state=0;
   result=0;
  }
 }
 return result;
}
