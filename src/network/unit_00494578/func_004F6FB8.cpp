/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buffer { int off,x,used; char data[1]; };
struct Obj { char pad[0x190]; int count; Buffer *buf; };
struct Input { char pad[0x10]; unsigned char kind; char pad11; unsigned short length; const char *data; };
extern "C" int func_0060EAF0(Buffer *,const char *,unsigned);
extern "C" void func_0060EBA0(Buffer *,int);
extern "C" void func_004F6FB8(Obj *p,Input *q) {
 Buffer *b=p->buf;
 if (b) {
 unsigned room=0x1000-b->used;
 if (room) {
 unsigned n=q->length;
 const char *data=q->data;
 const char *end=data+n-1;
 if (*end==0) { const char *cursor=end; do { --cursor; --n; } while (*cursor==0); }
 func_0060EAF0(b,data,n<room?n:room-1);
 if (q->kind==1) { b->data[b->off]=0; func_0060EBA0(b,1); p->count++; }
 }
 }
}
