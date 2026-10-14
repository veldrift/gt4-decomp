/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cursor { int key, x; unsigned block, pos; };
struct State { char pad[0x10]; unsigned total; Cursor cur; };
struct Buf { char pad[8]; char *data; };
struct Stream { char pad[4]; void *list; char pad8[0x48]; unsigned size; };
extern "C" int func_004CB8E8(Stream *, int) throw();
extern "C" Buf *func_004CA820(void *, unsigned) throw();
extern "C" void func_004CA938(void *, Buf *) throw();
extern "C" void func_004CA9D0(void *, Buf *) throw();
extern "C" int func_004CB9C8(Stream *, Cursor *, unsigned) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" long func_004CC260(Stream *s, State *st, void *data, unsigned count, int mode) {
 Cursor *c = &st->cur;
 int key = func_004CB8E8(s, c->key);
 key += c->block;
 unsigned size = s->size;
 unsigned n = size - c->pos;
 if (count < n) n = count;
 Buf *b = func_004CA820(s->list, key);
 if (!b) return -5;
 {
  if (mode) {
   func_005A4724(data, b->data + c->pos, n);
   func_004CA938(s->list,b);
  } else {
   func_005A4724(b->data+c->pos,data,n);
   func_004CA9D0(s->list,b);
  }
  int v = func_004CB9C8(s,c,n);
  if(v<0) return v;
  st->total += n;
 }
 return n;
}
