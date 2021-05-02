

/* 
 * Megalovania 
 * by Toby Fox 
 */
void playMegalovania() {
  digitalWrite(green, HIGH);
  digitalWrite(orange, LOW);
  lcd.clear();
  lcd.print("Megalovania");
  for (int i = 0; i < 4; i++){
    if (i == 0) {
      playNote(D_3, 100, 25);
      playNote(D_3, 100, 25); 
    } else if (i == 1) {
      playNote(C_3, 100, 25);
      playNote(C_3, 100, 25); 
    } else if (i == 2) {
      playNote(B_2, 100, 25);
      playNote(B_2, 100, 25); 
    } else if (i == 3) {
      playNote(A_2_sharp, 100, 25);
      playNote(A_2_sharp, 100, 25); 
    }
    playNote(D_4, 100, 200);
    playNote(A_3, 100, 200);
    
    playNote(G_3_sharp, 100, 150);
    playNote(G_3, 100, 150);
    playNote(F_3, 200, 50);
    
    playNote(D_3, 100, 25);
    playNote(F_3, 100, 25);
    playNote(G_3, 100, 25);
  }
}
