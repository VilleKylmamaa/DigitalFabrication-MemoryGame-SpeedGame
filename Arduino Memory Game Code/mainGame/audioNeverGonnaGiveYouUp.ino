
/* 
 * Never Gonna Give You Up 
 * by Rick Astley
 */
void playNeverGonnaGiveYouUp() {
  digitalWrite(orange, HIGH);
  digitalWrite(green, LOW);
  lcd.clear();
  lcd.print("Never Gonna");
  lcd.setCursor(0, 1);
  lcd.print("Give You Up");

  // Intro
  playNote(C_6_sharp, 600, 50);
  playNote(D_6_sharp, 600, 50);
  playNote(G_5_sharp, 400, 50);
  playNote(D_6_sharp, 600, 50);
  playNote(F_6, 600, 50);
  
  playNote(G_6_sharp, 100, 25);
  playNote(F_6_sharp, 100, 25);
  playNote(F_6, 100, 25);
  playNote(C_6_sharp, 100, 25);
  
  playNote(C_6_sharp, 600, 50);
  playNote(D_6_sharp, 600, 50);
  playNote(G_5_sharp, 1000, 50);

  playNote(G_4_sharp, 100, 25);
  playNote(G_4_sharp, 100, 25);
  playNote(G_5_sharp, 100, 25);
  playNote(F_5_sharp, 100, 25);
  playNote(F_5, 100, 25);
  playNote(C_5_sharp, 100, 25);
  
  playNote(C_5_sharp, 600, 50);
  playNote(D_5_sharp, 600, 50);
  playNote(G_4_sharp, 400, 50);
  playNote(D_5_sharp, 600, 50);
  playNote(F_5, 600, 50);
  
  playNote(G_5_sharp, 100, 25);
  playNote(F_5_sharp, 100, 25);
  playNote(F_5, 100, 25);
  playNote(C_5_sharp, 100, 25);
  
  playNote(C_5_sharp, 600, 50);
  playNote(D_5_sharp, 600, 50);
  playNote(G_4_sharp, 1000, 50);

  playNote(D_4_sharp, 100, 25);
  playNote(D_4_sharp, 100, 300);
  playNote(D_4_sharp, 100, 25);
  playNote(D_4_sharp, 100, 300);

  // Verse
  playNote(A_4_sharp, 225, 25);
  playNote(C_5, 225, 25);
  playNote(C_5_sharp, 225, 25);
  playNote(C_5_sharp, 225, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(C_5, 325, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(G_4_sharp, 1000, 50);
  
  playNote(A_4_sharp, 225, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(C_5, 225, 25);
  playNote(C_5_sharp, 225, 25);
  playNote(A_4_sharp, 325, 125);
  playNote(G_4_sharp, 225, 25);
  playNote(G_5_sharp, 325, 175);
  playNote(G_5_sharp, 225, 25);
  playNote(D_5_sharp, 1000, 25);
  
  playNote(A_4_sharp, 225, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(C_5, 225, 25);
  playNote(C_5_sharp, 225, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(C_5_sharp, 225, 25);
  playNote(D_5_sharp, 325, 225);
  playNote(C_5, 225, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(G_4_sharp, 1000, 25);
  
  playNote(A_4_sharp, 225, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(C_5, 225, 25);
  playNote(C_5_sharp, 225, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(G_4_sharp, 325, 175);

  playNote(D_5_sharp, 225, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(F_5, 225, 25);
  playNote(D_5_sharp, 775, 25);

  playNote(C_5_sharp, 1225, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(F_5, 225, 25);
  playNote(C_5_sharp, 255, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(F_5, 225, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(G_4_sharp, 225, 25);
  playNote(G_4_sharp, 725, 175);

  playNote(A_4_sharp, 225, 25);
  playNote(C_5, 225, 25);
  playNote(C_5_sharp, 225, 25);
  playNote(A_4_sharp, 425, 225);

  playNote(D_5_sharp, 225, 25);
  playNote(F_5, 225, 25);
  playNote(D_5_sharp, 1000, 25);
  
  // Chorus
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  
  playNote(F_5, 400, 25);
  playNote(F_5, 400, 25);
  playNote(D_5_sharp, 600, 25);
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  
  playNote(D_5_sharp, 400, 25);
  playNote(D_5_sharp, 400, 25);
  playNote(C_5_sharp, 400, 25);
  playNote(C_5, 100, 25);
  playNote(A_4_sharp, 225, 25);
  
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  
  playNote(C_5_sharp, 325, 75);
  playNote(D_5_sharp, 225, 25);
  playNote(C_5, 100, 25);
  playNote(A_4_sharp, 225, 25);
  playNote(G_4_sharp, 600, 25);
  playNote(G_4_sharp, 225, 25);
  playNote(D_5_sharp, 500, 25);
  playNote(C_5_sharp, 1000, 25);
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(G_4_sharp, 100, 25);
  
  playNote(F_5, 400, 25);
  playNote(F_5, 400, 25);
  playNote(D_5_sharp, 600, 25);
  
  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);

  playNote(G_5_sharp, 400, 25);
  playNote(C_5, 225, 25);
  playNote(C_5_sharp, 325, 25);
  playNote(C_5, 100, 25);
  playNote(A_4_sharp, 400, 25);

  playNote(G_4_sharp, 100, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(C_5_sharp, 100, 25);
  playNote(G_4_sharp, 100, 25);

  playNote(C_5_sharp, 400, 25);
  playNote(D_5_sharp, 225, 25);
  playNote(C_5, 400, 25);
  playNote(A_4_sharp, 100, 25);
  playNote(G_4_sharp, 600, 25);
  
  playNote(G_4_sharp, 225, 25);
  playNote(D_5_sharp, 500, 25);
  playNote(C_5_sharp, 1000, 25);
}
