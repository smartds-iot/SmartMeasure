
void Modo_config(){
   int contador = 0;
   int limite = 4
  //printf ("%c, /n Conector /n Comunicación /n Frecuencia /n Volver", modulos[n]);
   FLAG_PULSA_BOTON = 0;
   millis();
   if (millis()==10000 && FLAG_PULSA_BOTON == 0){
        
        Modo_Standby();
     }

     else if (Pulsa_Boton_2seg){

       FLAG_BOTON_2SEG = 1;
       Conector();
       
  
     } 

     else if (Pulsa boton){

           FLAG_PULSA_BOTON = 1;
           
        while (!FLAG_BOTON_2SEG){
         switch (contador){
            
            case 0: 
            //printf ("Barra blanca sobre Conector | Pantalla nueva igual pero con fondo de Conector en blanco");
            
            if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
              }
             
             else if (pulsa_2seg){
              
              Conector();
              
              }

              else if (pulsa boton){
                
                contador = contador + 1;
                
                }
                break;

            case 1:
            //printf ("Barra blanca sobre Comunicacion | Pantalla nueva igual pero con fondo de Comunicacion en blanco");
            
            if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
              }
             
             else if (pulsa_2seg){
              
              Comunicacion();
              comunicacion_listo = 1;
              
              }

              else if (pulsa boton){
                
                contador = contador + 1;
                
                }
                break;
            
            case 2:
             //printf ("Barra blanca sobre Frecuencia | Pantalla nueva igual pero con fondo de Frecuencia en blanco");
            
            if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
              }
             
             else if (pulsa_2seg){
              
              Frecuencia();
              frecuencia_lista = 1;
              
              }

              else if (pulsa boton){
                
                contador = contador + 1;
                
                }
                break; 

             case 3:
              //printf ("Barra blanca sobre Volver | Pantalla nueva igual pero con fondo de Volver en blanco");
            
            if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
              }
             
             else if (pulsa_2seg){
              
              Modo_selector();
              
              }

              else if (pulsa boton){
                
                contador = 0;
                
                }
                break;
            
                

              
            
            
            }
    
        }
     }
  }


  void modulo_configurado_completo(){
    
    printf("Calidad del Aire:     %c /nRuido Ambiental:     %c /nTemperatura       %c /n        START        ", &calidad_del_aire, &ruido_ambiental, &temperatura);
    FLAG_ACTIVADO = 1;
    millis();
    if (millis() == 10000){
      
      Modo_Standby();
      
      }
      else if (Boton_pulsa_2seg){
        
        
        Modo_Activo();
        
        }
    
    
    }
