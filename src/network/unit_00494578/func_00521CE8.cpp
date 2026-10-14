typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj { char pad[0x218]; u16 tag; };
extern "C" int func_00539188(u8 *,u16 *);
extern "C" int func_00521E58(Obj *,u8 *,u32,u32 *);
extern "C" int func_00521CE8(Obj *obj,u8 *data,u32 size,u32 *pos,u32 *out) {
 u16 value=0;
 u16 aux=0;
 func_00539188(data+*pos,&value);
 *pos+=2;
 if(value!=obj->tag) return 0xc359;
 func_00539188(data+*pos,&value);
 *pos+=2;
 int type=value&15;
 if(type!=0) return type==3?0xc35c:0xc35b;
 if(!(value&0x8000)) return 0xc35b;
 func_00539188(data+*pos,&value);
 *pos+=2;
 func_00539188(data+*pos,&aux);
 *pos+=2;
 *out=aux;
 *pos+=4;
 if(*pos>size) return 0xc359;
 for(u32 i=0;i<value;i++) {
  int result=func_00521E58(obj,data,size,pos);
  if(result!=0) return result;
 }
 return *pos>size?0xc359:0;
}
