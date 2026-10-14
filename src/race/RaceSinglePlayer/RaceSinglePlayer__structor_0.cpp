struct Entry{short delta,pad;int(*fn)(void*,int);};struct Virt{Entry*table;};struct Input{int device;char pad[400];int id;};struct S{char pad[88];int menu;char pad5c[8];void*table;};extern char RaceSinglePlayer__vtable[];extern char*D_00622F4C;
extern "C" S*RaceBasicWithRaceDisplay__structor_0(S*);
extern "C" void SimplePause__structor_0(void*),func_0055F9F8(void*),RaceInput__structor_0(Input*),func_00109A28(S*,Input*),func_00346808(void*,int),func_0038B850(S*,void*) throw();
extern "C" int func_0033D958(int),func_0055F420(int);
inline char*offset(void*p,int n){return (char*)(n+(unsigned)p);}
extern "C" void RaceSinglePlayer__structor_0(S*s){Input*in=(Input*)offset(s,0x123cc);void*menu=offset(s,0x1238c);void*pause=offset(s,0x12380);RaceBasicWithRaceDisplay__structor_0(s);s->table=RaceSinglePlayer__vtable;SimplePause__structor_0(pause);func_0055F9F8(menu);RaceInput__structor_0(in);in->device=func_0055F420(func_0033D958(0));Virt*v=(Virt*)(D_00622F4C+0x39e80);Entry*e=v->table+8;in->id=e->fn((char*)v+e->delta,0);s->menu=(int)menu;func_00109A28(s,in);char*p=offset(s,0x124a0);*(int*)(p+4)=0;func_00346808(p,0);return func_0038B850(s,pause);}
