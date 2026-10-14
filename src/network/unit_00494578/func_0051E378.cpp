/* compiler: ee-gcc2.96-nogcse */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { int id; int pad; int generation; };
struct Packet { char pad[8]; int id; char more[0x48]; char stream[1]; };
extern int D_0064AE18;
extern "C" int func_00538710(void *,int *);
extern "C" int func_00538460(void *,int,int);
extern "C" int func_00538558(void *,u32 *);
extern "C" int func_00538630(void *,u8 **);
extern "C" int func_00538F98(u8 *,u16 *);
extern "C" int func_0051E4F0(State *,Packet *,int,u8 *,int);
extern "C" int func_005380D8(void *,u32);
extern "C" int func_0051E378(State *s,Packet *p) {
 struct {u8 type; u16 count;} h;
 int pending;
 u32 available;
 u8 *cursor=0;
 available=0;
 if(s->id!=p->id) return 2;
 void *stream=p->stream;
 func_00538710(stream,&pending);
 if(pending) {
  int r=func_00538460(stream,1,D_0064AE18);
  if(r) return r;
 }
 func_00538558(stream,&available);
 if(available<3) return 0;
 int generation=s->generation;
 int r;
 u32 size;
 goto header;
 do {
 cursor+=3;
 r=func_0051E4F0(s,p,h.type,cursor,h.count);
 if(r) return r;
 r=func_005380D8(stream,size);
 if(r) return r;
 func_00538558(stream,&available);
 if(available<3) return 0;
 if(generation!=s->generation) return 0;
 header:
 r=func_00538630(stream,&cursor);
 if(r) return r;
 h.type=*cursor;
 func_00538F98(cursor+1,&h.count);
 size=h.count+3;
 if(h.count && (h.type&0x80)) size=h.count+7;
 } while(available>=size);
 return 0;
}
