

void conector(){

  int conectores = 0;
  int limite = 3;
  printf("Indicar Conector /n CON1 /n CON2 /n CON3 /n Volver");
  FLAG_PULSA_BOTON = 0;
  millis();
   if (millis()==10000 && FLAG_PULSA_BOTON == 0){
        
        Modo_Standby();
     }

     else if (Pulsa_Boton_2seg){

       FLAG_BOTON_2SEG = 1;
       ->Llamada a función que asigne los parametros de la estructura de CON1;
       conector_listo = 1;
  
     } 
  
     else if (Pulsa Boton){
      
      conectores = conectores + 1;
      FLAG_PULSA_BOTON = 1;
       
      
      while(!FLAG_BOTON_2SEG){
       switch (conectores){
        
        case 0: 
        printf("Indicar Conector /n CON1(resaltado) /n CON2 /n CON3 /n Volver");
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             //Llamada a función que asigne los parametros de la estructura de CON1
             conector_listo = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            conectores = conectores + 1;
            
            }
            break;

            case 1: 
        printf("Indicar Conector /n CON1 /n CON2 (resaltado) /n CON3 /n Volver");
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             //Llamada a función que asigne los parametros de la estructura de CON2
             conector_listo = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            conectores = conectores + 1;
            
            }
            break;

            case 2: 
        printf("Indicar Conector /n CON1 /n CON2 (resaltado) /n CON3 /n Volver");
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             //Llamada a función que asigne los parametros de la estructura de CON3
             conector_listo = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            conectores = conectores + 1;
            
            }
            break;

            case 3:
            printf("Indicar Conector /n CON1 /n CON2  /n CON3 /n Volver(resaltado)");

             
        if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             Modo_config();
  
            } 
           
           else if (Pulsa Boton){
            
            conectores = 0;
            
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
