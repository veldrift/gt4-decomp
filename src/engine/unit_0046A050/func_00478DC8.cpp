struct Matrix{float v[16];}; struct State{int words[15];};struct Render{int word,flag;};struct Resource;
struct Entry{short words[6];short index,offset,other,last;};struct Record{short words[4];short a,b;Resource*resource;};
struct Tables{char gap[144];Entry*entries;int unknown;Matrix*matrices;char gap2[20];Record*records;};
struct Obj{char gap[0x6e14];Render*render;unsigned char color[8];Tables*tables;};struct Input{unsigned short kind;short index,a,b;int word;};
extern "C" void func_0047DE58(unsigned*,const void*,const void*,float),func_0047E0F8(Matrix*,const Matrix*,const Matrix*,float),func_00473380(Render*,unsigned),func_00478AF0(Matrix*,int,int,float),func_00478B30(Obj*,Resource*,Matrix*),func_00105280(State*,int),func_00473B18(State*,Resource*,Resource*,float),func_00473780(Render*,State*),func_004737A0(Render*,int),func_004AB040(int);
extern "C" unsigned func_0047E658(const unsigned char*,const unsigned char*);
extern "C" State*func_004737F0(State*,Render*,int,int,int,int),*func_00105378(State*,const State*);
inline Record* record(Tables*t,int index){return &t->records[index];}
extern "C" void func_00478DC8(Input*in,Obj*self,State*out,float t){unsigned color;Matrix m;State temp;
 if(in->kind==0){func_0047DE58(&color,&in->a,&in->word,t);func_00473380(self->render,func_0047E658(self->color,(unsigned char*)&color));}
 else if((unsigned short)(in->kind-1)<2){Entry*entry=&self->tables->entries[in->index];Record*r=&self->tables->records[entry->index];func_0047E0F8(&m,&self->tables->matrices[in->a],&self->tables->matrices[in->b],t);if(in->kind==1){func_00478AF0(&m,entry->offset,r->b,t);func_00478B30(self,r->resource,&m);}else{func_004737F0(&temp,self->render,r->a,r->b,0,0);func_00105378(out,&temp);func_00105280(&temp,2);Resource*other=record(self->tables,entry->other)->resource;func_00473B18(out,r->resource,other,t);func_00473780(self->render,out);func_00478B30(self,0,&m);}func_004737A0(self->render,1);return;}
 else if((unsigned short)(in->kind-3)<2){func_0047E0F8(&m,&self->tables->matrices[in->a],&self->tables->matrices[in->b],t);Resource*selected=record(self->tables,in->index)->resource;func_00478B30(self,selected,&m);if(in->kind==3){func_004737A0(self->render,2);return;}func_004737A0(self->render,1);return;}
 Render*r=self->render;func_004AB040(2);r->flag=0;
}
