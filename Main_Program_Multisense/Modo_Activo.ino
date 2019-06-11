
void Modo_activo (){

 FLAG_PULSA_BOTON = 0;
 FLAG_BOTON_2SEG = 0;
  
  millis();

  if (Pulsa_Mode){
    
    FLAG_PULSA_BOTON = 1;
    
    }

  if (Pulsa_Mode_2_seg){
    
    FLAG_BOTON_2SEG = 1;
    
    }
  
  if ((millis() == 10000 && FLAG_PULSA_BOTON == 0) || (millis() == 10000 && FLAG_PULSA_BOTON == 1)){    //No hace falta la condición del flag, solo con que millis llegue a 10s bastaría
    
    Modo_Standby();1
    
    }

      else if (FLAG_BOTON_2SEG){
        
        Modo_selector();
        
        }

 }
