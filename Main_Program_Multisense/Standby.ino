

void Modo_Standby(){

FLAG_PULSA_BOTON = 0;
  
  while(!FLAG_PULSA_BOTON){

  FLAG_PULSA_BOTON = 0;

 if (Pulsa Mode){
  
  FLAG_PULSA_BOTON = 1;
    
    }
    
  }

     if(FLAG_ACTIVADO){
      
      Modo_activo();
      
      }
      
      else Modo_selector();
     
     }
     
     
     
