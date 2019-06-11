void Comunicacion(){

int comunicaciones;
char estados[3] = "OFF, OFF, OFF";
printf("   Indicar Comunicación /nSigFox   %c /nLoRa   %c /nGPS   %c", estados[0], estados[1], estados[2] );


//  if (FLAG_SIGFOX == 1 && FLAG_LORA == 0 && FLAG_GPS == 0){
//    
//    printf("   Indicar Comunicación /nSigFox   ON /nLoRa   OFF /nGPS   OFF"  );
//    
//    }
//    else if (FLAG_SIGFOX == 0 && FLAG_LORA == 1 && FLAG_GPS == 0){
//      
//      printf("   Indicar Comunicación /nSigFox   OFF /nLoRa   ON /nGPS   OFF"  );
//      
//      }
//      else if (FLAG_SIGFOX == 0 && FLAG_LORA == 0 && FLAG_GPS == 1){
//
//        printf("   Indicar Comunicación /nSigFox   OFF /nLoRa   OFF /nGPS   ON"  );
//        
//        }
//        else printf("   Indicar Comunicación /nSigFox   OFF /nLoRa   OFF /nGPS   OFF"  );


  millis();
   if (millis()==10000 && FLAG_PULSA_BOTON == 0){
        
        Modo_Standby();
     }

     else if (Pulsa_Boton_2seg){

       FLAG_BOTON_2SEG = 1;
       estados[0] = "ON";
       ->Llamada a la rutina de ejecucion de SigFox;
       comunicacion_listo = 1;
       
  
     } 

     else if (Pulsa Boton){
      
      comunicaciones = comunicaciones + 1;
      FLAG_PULSA_BOTON = 1;
      
      
     while (!FLAG_BOTON_2SEG){
      
      switch (comunicaciones){
        
        case 0: 
        printf("   Indicar Comunicación /nSigFox(resaltado)   %c /nLoRa   %c /nGPS   %c", estados[0], estados[1], estados[2] );
        if (millis()== 10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

             estados[0] = "ON";
             ->Llamada a la funcion de ejecucion de Sigfox
             comunicacion_listo = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            comunicaciones = comunicaciones + 1;
            
            }
            break;

            case 1:
            printf("   Indicar Comunicación /nSigFox  %c /nLoRa(resaltado)    %c /nGPS   %c", estados[0], estados[1], estados[2] );
        if (millis()== 10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

             estados[1] = "ON";
             ->Llamada a la funcion de ejecucion de Sigfox
             comunicacion_listo = 1;
  
            } 
           
           else if (Pulsa Boton){
            
            comunicaciones = comunicaciones + 1;
            
            }
            break;

            case 2:
            printf("   Indicar Comunicación /nSigFox  %c /nLoRa   %c /nGPS(resaltado)    %c", estados[0], estados[1], estados[2] );
        if (millis()== 10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

             estados[2] = "ON";
             ->Llamada a la funcion de ejecucion de Sigfox
             comunicacion_listo = 1;
             
  
            } 
           
           else if (Pulsa Boton){
            
            comunicaciones = comunicaciones + 1;
            
            }
            break;

            case 3:

            printf("   Indicar Comunicación /nSigFox  %c /nLoRa   %c /nGPS    %c /n       Volver(resaltado)", estados[0], estados[1], estados[2] );

       if (millis()==10000 && FLAG_PULSA_BOTON == 1){
        
              Modo_Standby();
              
            }

           else if (Pulsa_Boton_2seg){

       
             Modo_config();
  
            } 
           
           else if (Pulsa Boton){
            
            comunicaciones = 0;
            
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
