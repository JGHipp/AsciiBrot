main(){for(int l,p=0;p<4800;p++){float e,a=p%120*0.025-2,b=1-0.05*p/120,c=0,d=0,i=0;for(;i<50&&
c<=2;l=0.18*++i){e=c;c=c*c-d*d+a;d=e*d+e*d+b;}printf("%c%c"," .:-=+*#%$"[l],p%120==119?10:0);}}
