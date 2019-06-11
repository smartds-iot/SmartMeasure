 //* VARIABLES GLOBALES *//
 
 bool FLAG_START;
 bool FLAG_PULSA_BOTON = 0;
 bool FLAG_BOTON_2SEG = 0;
 bool FLAG_ACTIVADO = 0;
 bool FLAG_SIGFOX = 0;
 bool FLAG_LORA = 0;
 bool FLAG_GPS = 0;
 int conector_listo;
 int comunicacion_listo;
 int frecuencia_lista;
 int i;
 int n=3;
 char calidad_del_aire = "Iniciar Conf."
 char ruido_ambiental = "Iniciar Conf."
 char temperatura = "Iniciar Conf."
 char modulos[n]; //al final este array será un array de estructuras de los conectores
