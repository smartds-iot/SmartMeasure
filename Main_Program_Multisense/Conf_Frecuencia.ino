void Frecuencia(){
  
  
  int frecuencias = 0;
  int limite = 3;
  printf("     Indicar Frecuencia    /n     10m     /n     30m     /n     1h     /n          Volver");
  FLAG_PULSA_BOTON = 0;
  millis();
   if (millis()==10000 && FLAG_PULSA_BOTON == 0){
        
        Modo_Standby();
     }

     else if (Pulsa_Boton_2seg){

       FLAG_BOTON_2SEG = 1;
       ->Llamada a función que asigne las frecuencias;
       frecuencia_lista = 1;
  
     } 
  
     else if (Pulsa Boton){
      
      frecuencias = frecuencias + 1;
      FLAG_PULSA_BOTON = 1;

      while (!FLAG_BOTON_2SEG){
      switch (fecuencias){
        
        case 0: 
        printf("     Indicar Frecuencia    /n     10m(resaltado)     /n     30m     /n     1h     /n          Volver");
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             //Llamada a función que asigne los valores de frecuencia
             frecuencia_lista = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            conectores = conectores + 1;
            
            }
            break;

            case 1: 
        printf("     Indicar Frecuencia    /n     10m     /n     30m(resaltado)     /n     1h     /n          Volver");
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             //Llamada a función que asigne el valor de frecuencia
             frecuencia_lista = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            frecuencias = frecuencias + 1;
            
            }
            break;

            case 2: 
        printf("     Indicar Frecuencia    /n     10m     /n     30m     /n     1h     /n          Volver");
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             //Llamada a función que asigne los valores de frecuencia
             frecuencia_lista = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            frecuencias = frecuencias + 1;
            
            }
            break;

            case 3:
           printf("     Indicar Frecuencia    /n     10m     /n     30m     /n     1h     /n          Volver");

             
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             Modo_config();
  
            } 
           
           else if (Pulsa Boton){
            
            frecuencias = 0;
            
            }
            break;

            
  
        
        
        
        }
      
      
      }

     }
     if(comunicacion_listo + conector_listo + frecuencia_lista == 3){
        
        modulo_configurado_completo();
        
        }

           else Modo_config();
  
  
  }
  
  
  
  
