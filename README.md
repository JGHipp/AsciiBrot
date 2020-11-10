# AsciiBrot
Renders the Mandelbrot Set in your terminal!
## Examples
<pre> ./mandel -i 9000 -s 0.75 -1.1465486666 0.27618133333 -1.114949733 0.2524821333 </pre>
<i> Renders the set from (-1.1465 + 0.2762i) to (-1.1149 + 0.2525i) with 9,000 iterations and a scale factor of 0.75 from the original 120x40 character display </i><br/> 
<br/><b>Output</b>:
<pre>
View dimensions: 120x40 chars (scale factor: 0.75)
Max. iterations: 9000
Top left corner: (-1.14655 + 0.276181i), bottom right corner: (-1.11495 + 0.252482i)
                                                                                          
          .                                                                               
                                                                                       .  
        .                                                                                 
    '   .                                                                      '          
'$....                            .                                               .       
$^.                                                                          :.           
$$.. . ''.                                                .                    .          
$$$$`               .         .  . . . .                  . .             .  .            
$$t`...               ..          ^ ..'....    '            .... .    .              .    
$$`.               .....     .  '' ^'".        .                .      ..   '.            
$$:.           ..'   .'`.   .    ;`$$$`.`"                    ..$'..'. .i$$`. . .         
$`'    . .."` .''l  .'$$$! '".  .;$$$$$^'.    ...     .     ...i$$$$$$$m$$$...            
'.     .'^`$q'"x$$$$$$$$$$$$$$$$$+>$$$$.:^.' ..'.'. ..     ..^$$$$$$$$$$$$'.             .
..^$`$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$I$$~. '^.    ..$$$$$$$$$$$$$$$l..            
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$~.:'   .$$$$$$$$$$$$$$$$$..`.         
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$~^".$$$$$$$$$$$$$$$.'...          
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'$$$$$$$$$$$$$.` . .         
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.''               
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_.. ^    ..     ..    
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$l.' ..       . .  
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$~.`^'  .  ...   
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'.. .  ,'  .  
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$`$$$^^..'  
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$)$`'  `   
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$".^'   
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$[, '  
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.. .
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
</pre>
<b>Expected</b>:<br />
![Screenshot](https://raw.githubusercontent.com/JGHipp/AsciiBrot/master/expected.png)
## Short Version
Compiling and running the following program (190 C-source code characters):
```c
main(){for(int l,p=0;p<4800;p++){float e,a=p%120*0.025-2,b=1-0.05*p/120,c=0,d=0,i=0;for(;i<50&&
c<=2;l=0.18*++i){e=c;c=c*c-d*d+a;d=e*d+e*d+b;}printf("%c%c"," .:-=+*#%$"[l],p%120==119?10:0);}}
```
Will give this output:
<pre>
                             .........                .....................--+:............                          ...
                              .........               ....................::=:.............                       ......
                              ..........               ...............:-::*$$-::.:.:.......                   ..........
                               ...........              .............:-+$$$$$$+%+-..:......               ..............
.                               ...........             .............:+$$$$$$$$#-...:......         ................    
...                             .............          ......:....:.:::$$$$$$$$*-:..............................        
.....                           ................     ..::::=:.:.:=-:::--+$$$$$=----::--:......-:............            
........                        ........................:=$$-%:::$$%$$$$$$$$$$$$$$$$$$$::::=::-::.......                
..........                      ....................:.:::+*$$$=$$$$$$$$$$$$$$$$$$$$$$$$$$-$$$$+:=....                   
  ...........                  ........................:-:=$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*....                     
    ...........               ...............:......:-$:-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:...:.                  .. 
      ..............        :....:............:...:.--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:..=...      ........    
        ......................-.....:.:-.:.........-#-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*:::..............      
         ..............:......=:::+:.::::..:.:.:..-:-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*:...............       
           ...................::-=++-=-+$=---::::::$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$::.............         
            .................:.:+*$$$$$$$$$$$$-:::-=$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#..........            
..          .............:..:#:==#$$$$$$$$$$$$$$+--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$+:........               
....        ........:...:...:::+$$$$$$$$$$$$$$$$$+=$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$-...:..                  
......     ............::+----$$$$$$$$$$$$$$$$$$$$#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*....                     
.........:......:.:...:-:+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:......                     
$..::::::$$::=:=:-::----+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:.:..                     
................:.:.....:-$$$=$$$$$$$$$$$$$$$$$$$$%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$%.....                   
......     .:...........:::+:-%$$$$$$$$$$$$$$$$$$$+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$........               
....        ...........-....-:-$#$$$$$$$$$$$$$$$$-=$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$-..........             
..          ..................:::=$$$$$$$$$$$$+:::-+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$=:.............         
           ....................::=$$--+$$+-===:::::-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$::..............        
          ....................:=+:+::::--::-.:....::-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$-...............      
         .....................:..:....:-..:....:...:=-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*::.-.................    
        ..................:..::...............:....::-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$-=.:...                 .. 
      ............           .......................+-=--%$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:....                     
    ...........               ...:.....................:::-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$=$$$$::..:.                    
  ..........                   ........................::$$$$$=$$$$$$$$$$$$$$$$$$$$$$$$*::$$-$=-.......                 
..........                      .......................:-=$$-$::-$$$$$$$$$$$$$$$$$$-=$=-......-............             
.......                         ................:   ...--::=:.:.:--.::--%$$$$$$-::.:.:........:................         
.....                           ..............         ......:.....::-+*$$$$$$$$:::.........    ....................    
...                             ............           ...............-%$$$$$$$$::.........              ...............
.                              ...........              ............::-+=$$$$$=-*..........                   ..........
                               ..........              ..............::.::-$$*=:...........                      .......
                              ..........              ................:...::-::............                          ...
                             ..........               ..................:::-::--...........                             

</pre>
