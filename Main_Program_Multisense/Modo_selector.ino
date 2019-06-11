

void Modo_selector(){

  //printf ("SmartMeasure /n  Calidad del Aire")

 i = 0;                  //selecciona los diferentes sensores dentro del menu de seleccion
 FLAG_PULSA_BOTON = 0;
 FLAG_BOTON_2SEG = 0;
  
 millis();
  
 if (millis() == 10000 && FLAG_PULSA_BOTON == 0){
        
        Modo_Standby();
     }

 else if (Pulsa_Boton_2seg){

  FLAG_BOTON_2SEG = 1;
  Modo_config();
  
     } 

 
 else if (Pulsa_Mode){

      FLAG_PULSA_BOTON = 1;
      i=i+1;
      //modulos[i] = modulos[i+1];

     while(!FLAG_BOTON_2SEG){       
      
      switch (i) {

              case 0:
                 modulos[i] = "Calidad del aire";
               //printf("SmartMeasure /n %c", modulos[n] );
                 millis();
                 if (millis()==10000 && FLAG_PULSA_BOTON){
        
                      Modo_Standby();
                  }
                 
                 else if (pulsa boton) {

                  i = i + 1;
                  
                  }

                 else if (Pulsa boton 2seg){

                    FLAG_BOTON_2SEG = 1;
                   
                    Modo_config();
                    calidad_del_aire = "Re Conf";
                  }
      
              break;

              case 1:
              modulos[i] = "ruido ambiental";
               //printf("SmartMeasure /n %c", modulos[n] );
               millis();
                 if (millis()==10000 && FLAG_PULSA_BOTON){
        
                      Modo_Standby();
                  }
                 
                 else if (pulsa boton) {

                  i = i + 1;
                  
                  }

                 else if (Pulsa boton 2seg){

                    FLAG_BOTON_2SEG = 1;
                    Modo_config();
                    ruido_ambiental = "Re Conf";
                  }
      
              break;

              case 2:
              modulos[i] = "Temperatura";
               //printf("SmartMeasure /n %c", modulos[n] );
               millis();
                 if (millis()==10000 && FLAG_PULSA_BOTON){
        
                      Modo_Standby();
                  }
                 
                 else if (pulsa boton) {

                  i = i + 1;
                  
                  }

                 else if (Pulsa boton 2seg){

                    FLAG_BOTON_2SEG = 1;
                    Modo_config();
                    temperatura = "Re Conf";
                    
                  }
      
              break;

              case 3: 
              modulos[i] = "Riego";
               //printf("SmartMeasure /n %c", modulos[n] );
               millis();
                 if (millis()==10000 && FLAG_PULSA_BOTON){
        
                      Modo_Standby();
                  }
                 
                 else if (pulsa boton) {

                  i = 0;
                  
                  }

                 else if (Pulsa boton 2seg){

                    FLAG_BOTON_2SEG = 1;
                    Modo_config();
                    
                  }
      
              break;
              
              }
      }
 }
            

 
