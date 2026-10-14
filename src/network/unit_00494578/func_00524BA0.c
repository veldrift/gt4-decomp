struct Obj { char p[0xB0]; int value; };
struct Entry { void *p; int size; };
struct Buf { struct Entry entries[8]; int size,count; char pad[8]; };
struct Payload { short code; char value,pad; };
static inline void init(struct Buf *b) { b->count=0; b->size=0; }
static inline void append(struct Buf *b,void *p,int size) { int n=b->count; b->entries[n].p=p; b->entries[n].size=size; b->size+=size; b->count++; }
extern int func_00525648(int,int);
extern int func_00527510(struct Obj *,int,int,int,struct Buf *);
extern int func_00524BA0(struct Obj *o,int value) {
 struct Buf buf; struct Payload payload; int r;
 payload.code=func_00525648(2,4); payload.value=value;
 if(!o) return 2;
 init(&buf); o->value=value; append(&buf,&payload,4);
 r=func_00527510(o,0,0,0xf000,&buf);
 if(r==0 || r==0xd2f3) return 0;
 return r;
}
