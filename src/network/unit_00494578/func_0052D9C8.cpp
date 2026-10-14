typedef unsigned int u32;
struct Block { u32 size; Block *next; char data[1]; };
struct Range { int unk0; u32 pos, cap, used; char *base; u32 total; };
struct Part { void *data; u32 size; };
struct Parts { Part entries[8]; u32 size; int count; };
extern "C" int func_0052E188(Range *, u32 *);
extern "C" int func_0052E230(Range *, Block **, u32);
extern "C" void func_0052D8B0(Range *, Block *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_0052D9C8(Range *r, Block **p, Parts *parts, u32 oldsize) {
 u32 available=0;
 int result=2;
 if (!r || !r->base || !r->total || !r->cap) return 2;
 if (!*p) return 2;
 if (!parts) return result;
 if (!parts->size) return result;
 if (!(*p)->size) {
  result=func_0052E188(r,&available);
  if (result) return result;
  u32 size=parts->size;
  if (available >= size) {
  (*p)->size=size;
  (*p)->next=0;
  char *dst=(*p)->data;
  for(int i=parts->count-1;i>=0;i--) {
   if(parts->entries[i].data && parts->entries[i].size) {
    func_005A4724(dst,parts->entries[i].data,parts->entries[i].size);
    dst+=parts->entries[i].size;
   }
  }
  r->pos+=(parts->size+3)&~3;
  r->used+=(parts->size+3)&~3;
  } else return 301;
 } else {
  if(r->pos == (u32)((char *)*p+(((*p)->size+3)&~3)-r->base+8)) {
   available=0;
   result=func_0052E188(r,&available);
   if(result) return result;
   u32 size=parts->size;
   if(available >= size) {
    char *dst= *p ? (*p)->data+oldsize : (char *)oldsize;
    for(int i=parts->count-1;i>=0;i--) {
     func_005A4724(dst,parts->entries[i].data,parts->entries[i].size);
     dst+=parts->entries[i].size;
    }
    (*p)->size+=parts->size;
    r->pos+=(parts->size+3)&~3;
    r->used+=(parts->size+3)&~3;
    if(r->pos==r->cap) r->pos=0;
    return 0;
   }
  }
  result=func_0052E230(r,p,parts->size+(*p)->size+8);
  if(result) return result;
  Block *b=(Block *)(r->base+r->pos);
  b->next=(*p)->next;
  char *dst=0;
  if (b) dst=b->data;
  b->size=parts->size+(*p)->size;
  func_005A4724(dst,(*p)->data,oldsize);
  dst+=oldsize;
  for(int i=parts->count-1;i>=0;i--) {
   if(parts->entries[i].data && parts->entries[i].size) {
    func_005A4724(dst,parts->entries[i].data,parts->entries[i].size);
    dst+=parts->entries[i].size;
   }
  }
  (*p)->next=b;
  r->pos+=((b->size+3)&~3)+8;
  r->used+=((b->size+3)&~3)+8;
  func_0052D8B0(r,*p);
  *p=b;
 }
 if(r->pos==r->cap) r->pos=0;
 return 0;
}
