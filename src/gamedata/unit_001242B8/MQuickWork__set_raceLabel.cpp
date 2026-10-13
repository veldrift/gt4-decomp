struct Rep{int len,cap,ref,sel;};struct Str{char*p;};
extern char D_0068DEA8[];
extern "C" void func_00124130(void*,void*);
extern "C" void func_001240D8(void*,int);
extern "C" void func_00312370(void*,void*);
extern "C" void func_00312318(void*,int);
extern "C" Str*func_00314920(int);
extern "C" void func_001279E8(void*,const char*);
extern "C" void func_00127A90(void*,const char*);
static inline const char*c_str(Str*s){int len=((Rep*)s->p)[-1].len;if(len==0)return D_0068DEA8;s->p[len]=0;return s->p;}
extern "C" void MQuickWork__set_raceLabel(void*,void*arg1,int,void*args){
  int buf0[4],buf1[4];int*ps;int self;
  func_00124130(buf0,arg1);
  ps=buf1;
  func_00312370(ps,args);
  self=buf0[0];
  func_00127A90((void*)self,c_str(func_00314920(*ps)));
  func_00312318(ps,2);
  func_001240D8(buf0,2);
}
