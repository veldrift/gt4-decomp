struct Vec {float x,y,z;};
struct Entry {Vec a,b;int words[7];};
struct Obj {Vec base[5];Entry entries[4];int a,b,flag,c,d,e,f;float zero;int values[4];Vec extra[4];};
struct Stream {int a,b,c;};
struct Temp {int a,b,c;Temp()asm("func_0045B620");};
extern "C" {
unsigned char GT4Model__BinStreamReader__read8u(Stream*);
int func_0045B1E0(Stream*);
void GT4Model__BinStreamReader__readArray(Stream*,void*,int);
void func_0045B740(Temp*,Stream*);
void func_0045A4A0(Obj* self,Stream* stream) {
 char*cursor=(char*)self;int n=3;int&flag=self->flag;Temp temp;
 int version=GT4Model__BinStreamReader__read8u(stream);
 GT4Model__BinStreamReader__readArray(stream,&self->base[0],12);
 GT4Model__BinStreamReader__readArray(stream,&self->base[1],12);
 GT4Model__BinStreamReader__readArray(stream,&self->base[2],12);
 GT4Model__BinStreamReader__readArray(stream,&self->base[3],12);
 GT4Model__BinStreamReader__readArray(stream,&self->base[4],12);
 GT4Model__BinStreamReader__readArray(stream,&self->a,4);GT4Model__BinStreamReader__readArray(stream,&self->b,4);
 flag=func_0045B1E0(stream);
 GT4Model__BinStreamReader__readArray(stream,&self->c,4);GT4Model__BinStreamReader__readArray(stream,&self->d,4);
 GT4Model__BinStreamReader__readArray(stream,&self->e,4);GT4Model__BinStreamReader__readArray(stream,&self->f,4);
 do {
 Entry*entry=(Entry*)(cursor+60);
 --n;GT4Model__BinStreamReader__readArray(stream,&entry->a,12);
 GT4Model__BinStreamReader__readArray(stream,&entry->b,12);
 GT4Model__BinStreamReader__readArray(stream,&entry->words[0],4);GT4Model__BinStreamReader__readArray(stream,&entry->words[1],4);
 GT4Model__BinStreamReader__readArray(stream,&entry->words[2],4);GT4Model__BinStreamReader__readArray(stream,&entry->words[3],4);
 GT4Model__BinStreamReader__readArray(stream,&entry->words[4],4);GT4Model__BinStreamReader__readArray(stream,&entry->words[5],4);
 GT4Model__BinStreamReader__readArray(stream,&entry->words[6],4);cursor+=sizeof(Entry);
 }while(n>=0);
 int*p=self->values;int left=3;
 do {GT4Model__BinStreamReader__readArray(stream,p++,4);--left;}while(left>=0);
 if(version>0) {
 GT4Model__BinStreamReader__readArray(stream,&self->zero,4);
 Vec*v=self->extra;
 for(int i=0;i<4;++i)GT4Model__BinStreamReader__readArray(stream,v++,12);
 }else {
 self->zero=0;Vec*v=self->extra;int left=3;float zero=self->zero;
 do{--left;v->x=zero;v->y=zero;v->z=zero;++v;}while(left>=0);
 }
 func_0045B740(&temp,stream);
}
}
