struct E { char pad[0x68]; int value; char p[0x54]; };
struct T { int flag; char p[0xbc]; };
union S { E entries[2]; struct { char pad[0x11c]; T entries[2]; } tail; };
void ResultArcade__setCarIconNumber(S *s,int n,int v) { s->entries[n].value=v; s->tail.entries[n].flag=1; }
