struct Values{float v[6];};
extern Values D_006208D0,D_006208E8,D_00620900;extern Values D_008439B8[2],D_008439E8[2];
extern "C" float func_00345198(void*),func_003451A0(void*),func_003451A8(void*),func_00344858(void*,float),func_00344888(void*,float);
extern "C" void func_0035F090(Values*,Values*,int),func_0035EE50(Values*,Values*),func_0035EEB8(Values*,Values*,Values*,Values*);
void func_0035F420(void*self){Values position,delta,aux;char*part=(char*)self+0x104;
 position.v[0]=-func_00345198(self)*D_006208D0.v[0]/9.799999237060546875f;
 position.v[1]=func_003451A0(self)*D_006208D0.v[1]/9.799999237060546875f;
 position.v[2]=-func_003451A8(self)*D_006208D0.v[2]/9.799999237060546875f;
 position.v[3]=func_00344858(self,0);position.v[4]=-func_00344888(self,0);position.v[5]=0;Values*pd=&delta;
 pd->v[0]=0;pd->v[1]=0;pd->v[2]=0;pd->v[3]=func_003451A0(self)*D_006208D0.v[4]/9.799999237060546875f;pd->v[4]=func_00345198(self)*D_006208D0.v[3]/9.799999237060546875f;pd->v[5]=*(float*)(part+0x588)*D_006208D0.v[5];
 int flag=0;if(*(unsigned char*)(part+0x4b2))flag=1;else if(*(signed char*)(part+0x466)==2)flag=*(unsigned char*)(part+0x632)!=0;
 if(flag){func_0035F090(&D_006208E8,&D_00620900,2);func_0035EE50(&D_008439B8[0],&D_008439B8[0]);func_0035EE50(&D_008439B8[1],&D_008439B8[1]);}else{func_0035EEB8(&position,pd,&aux,&aux);func_0035F090(&position,pd,1);func_0035EEB8(&D_008439B8[0],&D_008439B8[1],&D_008439E8[0],&D_008439E8[1]);}
}
