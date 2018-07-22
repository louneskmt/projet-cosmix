long configBinary = 0b111100001111000000001111;
int config_START = 0b00001111;
int configpad_GPS = 1;

void setup(){
  Serial.begin(9600);
  
}

void loop(){
 // Serial.println((uint8_t)getNthByte(configBinary, 0));

  if(getNthByte(configBinary, 0)==15){

     // GPS : 2 bytes
     int GPS = getNthByte(configBinary, configpad_GPS)|(getNthByte(configBinary, configpad_GPS+1)<<8); // Concatenate binary values
     Serial.print("GPS: ");
     Serial.println((uint8_t)GPS);
  }
}



int getNthByte(int binary, int n){
  // Retourne le N-ième octet d'un nombre entier binaire
  // Return N-th byte of a binary integer

  // 0 --> First byte
  // 1 --> Second byte
  return (int)((binary>>n*8)&0xFF);
}



char writeIntToSerial(int message){
  // En travaillant en binaire, il faut écrire dans la console octet par octet
  // When working with binary, you must write in the serial byte by byte

  char arr[2] = {};
  
  for(int i = 0; i < sizeof(message); i++){
      arr[i] = (message>>i*8);
      Serial.println((uint8_t)arr[i]);
  }
  
  return Serial.write(arr); // Return number of written bytes
}
