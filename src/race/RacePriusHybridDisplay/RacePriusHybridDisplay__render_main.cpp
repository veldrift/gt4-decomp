/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int value; char pad[3]; unsigned char flag; int type; };
struct Texture { char pad[0x16]; unsigned short count; char pad2[4]; Entry *entries; };
struct Self { unsigned char z,xf,yf,pad; short x,y; int pad8; float alpha; char pad10[8]; Texture *texture; int value; char pad20[4]; unsigned char enabled; };
extern "C" char D_006A16A8[];
extern "C" Texture *func_003A1E10(const char *);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_003AEF18(Texture *,float,float,unsigned,unsigned);
extern "C" void RacePriusHybridDisplay__render_main(Self *s) {
 if(!s->enabled) return;
 if(!s->texture) {
  s->texture=func_003A1E10(D_006A16A8);
  if(!s->texture) return;
  s->value=0;
  for(int i=0;i<s->texture->count;i++) {
   Entry *e=&s->texture->entries[i];
   if(e->flag==0 && e->type==0x100010) { s->value=e->value; break; }
  }
 }
 func_004AA1D8(1.0f,1.0f,1.0f,s->alpha);
 func_003AEF18(s->texture,(float)s->x,(float)s->y,s->xf,s->yf);
}
