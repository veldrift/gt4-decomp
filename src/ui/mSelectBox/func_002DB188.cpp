/* compiler: ee-gcc2.96-nogcse */
struct Reader { int pos, v4, limit; };
struct S { char pad[0xBC]; Reader reader; char pad2[0x28]; char *flags; };
extern "C" int func_0057CF10(Reader *);
extern "C" void func_0057CE40(Reader *,int);
extern "C" int func_002DB148(S *) throw();
extern "C" int func_002DB188(S *self) {
 Reader *r = &self->reader;
 int old = r->pos;
 int result = func_0057CF10(r);
 char *flags = self->flags;
 if (flags) {
  int i = r->pos;
  while (flags[i]) {
   ++i;
   if (i >= r->limit) { func_0057CE40(r, old); return 0; }
  }
  func_0057CE40(r, i);
 }
 func_002DB148(self);
 return result;
}
