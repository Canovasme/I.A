#include <SD.h>				                      

File AlmacenamientoArduino;

void setup(){
  
  Serial.begin(9600);

  Serial.print("Leyendo tarjeta SD");				
  
  pinMode(10, OUTPUT);								
  
												 
  if (!SD.begin(10)){
    sdsd
    Serial.println("Se ha producido un error al leer la tarjeta SD");
    return;
  }
  Serial.println("Tarjeta SD OK");
  
  
 
  AlmacenamientoArduino = SD.open("pruebasd.txt", FILE_WRITE);			  
  

  if (AlmacenamientoArduino){													  
  
    
    AlmacenamientoArduino.println("Esta modificando el AlmacenamientoArduino");
    
    
    AlmacenamientoArduino.close();
    
    
    Serial.println("Todos los datos salvados correctamente");
  }
  
  
  else{

    Serial.println("El AlmacenamientoArduino datos.txt no se abrió correctamente");
  }
  
  
  
 
  AlmacenamientoArduino = SD.open("datos.txt");
  

  if (AlmacenamientoArduino){
    
    Serial.println("Información contenida en pruebasd.txt:");
    
    //(AlmacenamientoArduino.available()==FALSE).
    while (AlmacenamientoArduino.available()){
      
     Serial.write(AlmacenamientoArduino.read());
    }
    

    AlmacenamientoArduino.close();
  }
  
  else{

    Serial.println("El Archivo "Serial.wirte(File.Name)" no se abrió correctamente");
  }
  
}

void loop()
{
  //Loop no es necesario en este caso ya que toda la informacion ha sido tratada en el setup
}