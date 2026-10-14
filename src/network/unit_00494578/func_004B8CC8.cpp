/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
extern u16 D_006B0500[], D_006B0508[];
extern "C" int func_004B8B10(int) throw();
extern "C" int func_004B8B78(int) throw();
extern "C" int func_004B8BF0(int,int) throw();
extern "C" int func_004B8C90(unsigned,unsigned) throw();
extern "C" int func_004B9300(short*,int);
static inline void lower(int *c) { if ((unsigned)(*c-'A')<26) *c += 32; }
static inline void copy(u16 *d, const u16 *s) { while ((*d++ = *s++) != 0) ; }
static inline void copylast(const u16 *s, u16 *d) { while ((*d++ = *s++) != 0) ; }
extern "C" int func_004B8CC8(u16 *dst, int a, int b, int c) {
 lower(&a); lower(&b); lower(&c);
 if ((unsigned)(a-'a')>=26 && (unsigned)(b-'a')>=26 && (unsigned)(c-'a')>=26) return 0;
 int x,y;
 if(c) { y=func_004B8BF0(a,b); x=func_004B8B10(c); }
 else if(b) {
  if(a==b) {
   if(a=='n') { copy(dst,D_006B0500); return 1; }
   if(func_004B8B78(a)<0) { *dst=0; return 0; }
   copy(dst,D_006B0508); func_004B9300((short*)(dst+1),b); return 1;
  }
  if(a=='n') {
   int vowel=0;
   if(b=='a'||b=='i'||b=='u'||b=='e'||b=='o'||b==a||b=='y') vowel=1;
   if(!vowel) { copy(dst,D_006B0500); func_004B9300((short*)(dst+1),b); return 1; }
  }
  x=func_004B8B10(b); y=func_004B8B78(a);
 } else { y=0; x=func_004B8B10(a); }
 if(x<0||y<0) { *dst=0; return 0; }
 int r=func_004B8C90(y,x);
 if(r) { copylast((u16*)r,dst); return 1; }
 *dst=0; return r;
}
