
/* 
 *  Coffin Dance / Astronomia
 *  by Tony Igy and Vicetone
 */
void playCoffinDance() {
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(orange, LOW);
  lcd.clear();
  lcd.print("Astronomia");
  lcd.setCursor(0, 1);
  lcd.print("aka Coffin Dance");

  playNote(C_5, 150, 75);
  playNote(A_4_sharp, 150, 75);
  playNote(A_4, 150, 75);
  playNote(F_4, 150, 75);
  
  playNote(G_4, 200, 200);
  playNote(G_4, 150, 75);
  playNote(D_5, 150, 75);
  playNote(C_5, 200, 225);
  playNote(A_4_sharp, 200, 225);

  playNote(A_4, 200, 200);
  playNote(A_4, 150, 75);
  playNote(A_4, 150, 75);
  playNote(C_5, 200, 225);
  playNote(A_4_sharp, 150, 75);
  playNote(A_4, 125, 75);
  
  playNote(G_4, 200, 200);
  playNote(G_4, 150, 75);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);
  
  playNote(G_4, 200, 200);
  playNote(G_4, 150, 75);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);

  // Repeat
  playNote(G_4, 200, 200);
  playNote(G_4, 150, 75);
  playNote(D_5, 150, 75);
  playNote(C_5, 200, 225);
  playNote(A_4_sharp, 200, 225);

  playNote(A_4, 200, 200);
  playNote(A_4, 150, 75);
  playNote(A_4, 150, 75);
  playNote(C_5, 200, 225);
  playNote(A_4_sharp, 150, 75);
  playNote(A_4, 125, 75);
  
  playNote(G_4, 200, 200);
  playNote(G_4, 150, 75);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);
  
  playNote(G_4, 200, 200);
  playNote(G_4, 150, 75);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);
  playNote(A_5, 150, 50);
  playNote(A_5_sharp, 150, 75);

  // Outro
  for (int i = 0; i < 4; i++) {playNote(A_4_sharp, 150, 75);}
  for (int i = 0; i < 4; i++) {playNote(D_5, 150, 75);}
  for (int i = 0; i < 4; i++) {playNote(C_5, 150, 75);}
  for (int i = 0; i < 4; i++) {playNote(F_5, 150, 75);}
  for (int i = 0; i < 12; i++) {playNote(G_5, 150, 75);}
  playNote(C_5, 150, 75);
  playNote(A_4_sharp, 150, 75);
  playNote(A_4, 150, 75);
  playNote(F_4, 150, 75);
  playNote(G_4, 400, 200);
}
