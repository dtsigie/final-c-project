
/*
 render by typing:
  povray +Iqa315-02oct2013.pov Width=512 Height=512 Display=true +P
 This will produce a file named qa315-02oct2013.png.
*/

#include "colors.inc"  
#include "textures.inc"

light_source { <64, 64, 128> color White }

camera {
  location <16, 6, 8>
  look_at <0,0,0>
  }


sphere {
  <0, 0, 0> 4
  texture { pigment {color rgb<0.8,1.0,0.9>  }  }
  }   
  

sphere {
  <8,3,-4> 0.6
  texture { pigment {color rgb<1.0,0.9,0.4> } }
}
  
  
sphere {
  <8,3,-2> 0.2
  texture { pigment {color rgb<0.9,1.0,0.6> }  }
}
     
difference {   
cylinder {
  <0,-0.04,0> <0,0.04,0> 8
  texture {pigment { color rgb<0.4,0.9,0.9> } }
}
  
cylinder {
  <0,-0.2,0> <0,0.2,0> 5
  texture {pigment { color rgb<0.4,0.9,0.9> } }
} 
          
}
