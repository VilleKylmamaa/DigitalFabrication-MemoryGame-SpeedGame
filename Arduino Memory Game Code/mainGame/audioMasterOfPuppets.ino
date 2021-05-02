
/* 
 * Master of Puppets 
 * by Metallica
 * Kirk Hammett's guitar solo
 */
void playMasterOfPuppets() {
  digitalWrite(transparent, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(orange, LOW);
  lcd.clear();
  lcd.print("Master of");
  lcd.setCursor(0, 1);
  lcd.print("Puppets");
  
  // First part
  for (int i = 0; i < 100; i++){ playNote(50 + i*15, 15, 0); }

  for (int i = 0; i < 3; i++) {
    playNote(E_5, 85, 15);
    playNote(A_5, 85, 15);
    playNote(E_5, 85, 15);
    
    playNote(D_4, 85, 15);
    playNote(C_4_sharp, 85, 15);
    playNote(D_4, 85, 15);
  }
    playNote(E_5, 85, 15);
    playNote(G_5, 85, 15);
    playNote(E_5, 85, 15);
    
    playNote(D_4, 85, 15);
    playNote(C_4_sharp, 85, 15);
    playNote(D_4, 85, 15);
    
  for (int i = 0; i < 3; i++) {
    playNote(E_5, 85, 15);
    playNote(A_5, 85, 15);
    playNote(E_5, 85, 15);
    
    playNote(D_4, 85, 15);
    playNote(C_4_sharp, 85, 15);
    playNote(D_4, 85, 15);
  }
    playNote(E_5, 85, 15);
    playNote(G_5, 85, 15);
    playNote(E_5, 85, 15);
    
    playNote(D_4, 85, 15);


  // Second part
  playNote(E_5, 85, 15);
  playNote(B_5, 85, 15);
  playNote(B_5, 85, 15);
  
  playNote(A_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(G_5, 85, 15);
  playNote(G_5, 85, 15);
  playNote(G_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);

  playNote(A_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(G_5, 85, 15);
  playNote(G_5, 85, 15);
  playNote(G_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);

  playNote(D_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(E_5, 85, 15);
  playNote(E_5, 85, 15);
  
  for (int i = 0; i < 20; i++){ playNote(E_5 + i*6.237, 15, 1.5); } 
  for (int i = 0; i < 20; i++){ playNote(E_5 + i*6.237, 15, 1.5); }
  playNote(F_5_sharp, 170, 15);
  playNote(A_5, 85, 15);
  playNote(F_5_sharp, 170, 15);
  
  playNote(E_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(C_5_sharp, 85, 15);

  playNote(A_5, 85, 15);
  playNote(B_5, 170, 15);
  
  playNote(E_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(C_5_sharp, 85, 15);
  
  playNote(B_4, 85, 15);
  playNote(A_4, 85, 15);
  
  playNote(F_6, 300, 15);
  for (int i = 0; i < 15; i++){ playNote(F_6 - i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(E_6 + i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(F_6 - i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(E_6 + i*5.227, 7.5, 0); }
  playNote(F_6, 150, 15);
  
  playNote(G_6, 300, 15);
  for (int i = 0; i < 15; i++){ playNote(G_6 - i*5.867, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(F_6_sharp + i*5.867, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(G_6 - i*5.867, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(F_6_sharp + i*5.867, 7.5, 0); }
  playNote(G_6, 100, 15);


  // Third part
  playNote(A_5, 150, 15);
  playNote(B_5, 150, 15);
  
  playNote(B_4, 85, 15);
  playNote(C_5, 85, 15);
  playNote(A_4, 85, 15);
  
  playNote(F_3_sharp, 150, 15);
  playNote(A_4, 100, 15);
  playNote(B_4, 85, 15);
  playNote(A_4, 85, 15);
  
  playNote(F_3_sharp, 150, 15);
  playNote(E_3, 150, 15);
  playNote(C_3_sharp, 85, 50);
  
  playNote(E_3, 150, 15);
  playNote(F_3_sharp, 300, 15);
  

  // Fourth part
  
  playNote(D_5, 150, 15);
  playNote(C_5, 150, 15);
  playNote(B_4, 150, 15);
  playNote(G_4, 150, 15);

  playNote(C_5, 150, 15);
  playNote(B_4, 150, 15);
  playNote(G_4, 150, 15);
  playNote(F_4, 150, 15);

  playNote(E_4, 150, 15);
  playNote(F_4, 150, 15);
  playNote(G_4, 150, 15);
  
  playNote(A_4, 150, 15);
  playNote(A_4, 150, 15);
  playNote(A_4, 85, 15);
  playNote(A_4, 85, 15);
  playNote(A_4, 85, 15);
  
  playNote(D_5, 85, 15);
  playNote(C_5, 85, 15);
  playNote(B_4, 85, 15);
  playNote(B_4, 85, 15);
  playNote(D_5, 85, 15);
  playNote(C_5, 85, 15);
  playNote(B_4, 85, 15);
  playNote(B_4, 85, 15);

  playNote(E_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(C_5, 85, 15);
  playNote(E_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(C_5, 85, 15);

  playNote(F_5_sharp, 85, 15);
  playNote(E_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(E_5, 85, 15);
  playNote(D_5, 85, 15);
  playNote(G_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(E_5, 85, 15);

  playNote(A_5, 85, 15);
  playNote(G_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(B_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(A_5, 85, 15);
  playNote(G_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(B_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  
  playNote(A_5, 85, 15);
  playNote(G_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(B_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(A_5, 85, 15);
  playNote(G_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(B_5, 85, 15);
  playNote(A_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(F_5_sharp, 85, 15);
  

  // Fifth part

  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);
  
  playNote(B_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(E_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(B_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  playNote(E_5, 85, 15);
  playNote(F_5_sharp, 85, 15);
  
  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(E_5 + i*12.474, 15, 1.5); }
  playNote(F_5_sharp, 150, 15);

  for (int i = 0; i < 10; i++){ playNote(F_5 + i*8.553, 15, 1.5); }
  playNote(G_5, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(F_5 + i*8.553, 15, 1.5); }
  playNote(G_5, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(F_5 + i*8.553, 15, 1.5); }
  playNote(G_5, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(F_5 + i*8.553, 15, 1.5); }
  playNote(G_5, 150, 15);

  for (int i = 0; i < 10; i++){ playNote(G_5 + i*9.601, 15, 1.5); }
  playNote(A_5, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(G_5 + i*9.601, 15, 1.5); }
  playNote(A_5, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(G_5_sharp + i*10.172, 15, 1.5); }
  playNote(A_5_sharp, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(G_5_sharp + i*10.172, 15, 1.5); }
  playNote(A_5_sharp, 150, 15);
  
  for (int i = 0; i < 10; i++){ playNote(A_5 + i*10.777, 15, 1.5); }
  playNote(B_5, 150, 15);
  for (int i = 0; i < 10; i++){ playNote(A_5 + i*22.873, 15, 1.5); }
  playNote(B_5, 150, 15);

  for (int i = 0; i < 10; i++){ playNote(D_6 + i*22.225, 15, 1.5); }
  playNote(F_6, 500, 15);
  for (int i = 0; i < 15; i++){ playNote(F_6 - i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(E_6 + i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(F_6 - i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(E_6 + i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(F_6 - i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(E_6 + i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(F_6 - i*5.227, 7.5, 0); }
  for (int i = 0; i < 15; i++){ playNote(E_6 + i*5.227, 7.5, 0); }
  for (int i = 0; i < 10; i++){ playNote(F_6 + i*17.107, 15, 0); }
  playNote(G_6, 750, 15);
  for (int i = 0; i < 200; i++){ playNote(G_6 - i*10, 15, 0); }
}
