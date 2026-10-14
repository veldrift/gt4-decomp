struct State { unsigned start, end, cur, unknown, error, extra; };
extern "C" {
void *func_005A48D8(void *,int,unsigned);
void func_00539C68(State *,unsigned,unsigned);
void func_00539CA0(int,State *,void *,unsigned);
void func_00539EE8(int,State *,signed char *);
extern signed char D_0064AD68[];
int func_00513F68(int a,int b,int c,unsigned d) {
 State s;
 func_005A48D8(D_0064AD68,0,0x95);
 func_00539C68(&s,d,d+0x200);
 func_00539CA0(2,&s,D_0064AD68,0x15);
 func_00539EE8(2,&s,D_0064AD68+0x15);
 if(s.error) return -1;
 return s.cur-s.start;
}
}
