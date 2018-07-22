char getNthByte(int binary, int n){
  // Retourne le N-ième octet d'un nombre entier binaire
  // Return N-th byte of a binary integer

  // 0 --> First byte
  // 1 --> Second byte
  return (unsigned char)(binary>>n*8);
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
