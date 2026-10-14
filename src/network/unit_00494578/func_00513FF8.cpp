struct B21 { char b[21]; };
struct W4 { char b[4]; };
struct B8 { char b[8]; };
struct B128 { char b[128]; };
struct B256 { char b[256]; };
struct Packet {
 B21 header; char pad[3]; W4 status, flags, w20;
 B128 b24, ba4; W4 w124; B256 b128;
 W4 w228,w22c,w230; B8 b234; B128 b23c,b2bc,b33c;
 signed char last; char tail[3];
};
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_0057F188(const char *,const char *,unsigned);
extern "C" void func_005A6AB0(void *,void *,int) throw();
extern char D_0064AD68[];
extern int D_0064A330, D_006D6228;
extern int (*D_008A04A8)(void *,int);
extern int D_008A0280;
extern "C" int func_00513FF8(int a,int b,int c,char *start) {
 Packet q;
 char *p=start+29;
 func_005A48D8(&q,0,0x3c0);
 q.header=*(B21 *)start;
 q.status=*(W4 *)(start+21);
 q.flags=*(W4 *)(start+25);
 if (*(int *)&q.flags & 4) { q.w20=*(W4 *)p; p+=4; }
 if (*(int *)&q.flags & 8) { q.b24=*(B128 *)p; p+=128; }
 if (*(int *)&q.flags & 16) { q.ba4=*(B128 *)p; p+=128; q.w124=*(W4 *)p; p+=4; }
 if (*(int *)&q.flags & 32) { q.b128=*(B256 *)p; p+=256; }
 if (*(int *)&q.flags & 64) { q.w228=*(W4 *)p; p+=4; q.w22c=*(W4 *)p; p+=4; q.w230=*(W4 *)p; p+=4; }
 if (*(int *)&q.flags & 128) { q.b234=*(B8 *)p; p+=8; q.b23c=*(B128 *)p; p+=128; }
 if (*(int *)&q.flags & 256) { q.b2bc=*(B128 *)p; p+=128; }
 if (*(int *)&q.flags & 512) {
  if (func_0057F188((char *)&q,D_0064AD68,21)==0) func_005A6AB0(&q.b33c,D_0064AD68+21,128);
  else *(int *)&q.status=-966;
 }
 q.last=*p++;
 if (q.last==1) {
  if (*(unsigned *)&q.status<2) D_0064A330 |= *(int *)&q.flags;
  else D_0064A330=D_006D6228;
 }
 if (D_008A04A8) D_008A04A8(&q,D_008A0280);
 return p-start;
}
