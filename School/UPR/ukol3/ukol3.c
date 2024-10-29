#include "drawing.h"

int cara();
int schod();
int kvetina();
int louka();
int animace();

int main() {
  // Keep this line here
  clear_screen();

  // Load the input - what should be drawn.
  int drawing = 0;
  scanf("%d", &drawing);
    if (drawing == 0) {
        int a = 10;
        int b = 6;
        int c = 4;
        int d = 12;
        set_yellow_color();
        move_to(5, 20);
        cara(a);
        move_to(0, 10);
        set_black_color();
        cara(b);
        move_to(4, 6);
        set_green_color();
        cara(c);
        move_to(2, 14);
        set_white_color();
        cara(d);
    }
    else if (drawing == 1) {
        int a = 5;
        int b = 3;
        int c = 7;
        set_blue_color();
        schod(a);
        move_to(0, 10);
        set_green_color();
        schod(b);
        set_yellow_color();
        move_to(0, 35);
        schod(c);
    }
    else if (drawing == 2) {
        int a = 5;
        int b = 5;
        int c = 7;
        int d = 7;
        int e = 3;
        int f = 3;
        kvetina(a, b);
        move_to(0 , 10);
        kvetina(c, d);
        move_to(0 , 20);
        kvetina(e, f);
    }
    else if (drawing == 3) {
        louka();
    }
    else if (drawing == 4) {
        animace();
    }

//   // Keep this line here
  end_drawing();

  return 0;
}

int cara(int delkacary){
    for(int i = 0; i < delkacary; i++) {
        draw_pixel();
        move_right();
        move_right();
    }
    return 0;
}

int schod(int pocetschodu){
    for(int k = 0; k < pocetschodu; k++) {
        draw_pixel();
        move_down();
        draw_pixel();
        move_right();
        draw_pixel();
    }
    return 0;
}

int kvetina(int sirkakytky, int vyskakytky) {
    move_right();
    move_right();
    move_right();
    move_right();
    move_right();
    set_green_color();
    for(int i = 0; i < ((vyskakytky / 2) + 1); i++) {
        move_down();
    }
    for(int i = 0; i < (vyskakytky / 2); i++) {
        draw_pixel();
        move_down();
    }
    for(int i = 0; i < ((vyskakytky / 2) + 1); i++) {
        move_up();
    }
    set_red_color();
    for(int i = 0; i < (sirkakytky / 2); i++) {
        move_left();
    }
    for(int i = 0; i < sirkakytky; i++) {
        draw_pixel();
        move_right();
    }
    for(int i = 0; i < ((sirkakytky / 2) + 1); i++) {
        move_left();
    }

    for (int i = 0; i < (sirkakytky / 2); i++) {
        move_left();
    }
    for (int i = 0; i < (vyskakytky / 2); i++) {
        move_up();
    }
    set_yellow_color();
    draw_pixel();    
    for (int i = 0; i < sirkakytky; i++) {
        draw_pixel();
        move_down();
        move_right();
    }
    for ( int i = 0; i < (sirkakytky); i++) {
        move_left();
    }
    move_up();
    for (int i = 0; i < sirkakytky; i++) {
        draw_pixel();
        move_up();
        move_right();
    }
    move_down();
    return 0;

}
int louka(){
    int radky = 2;
    int sloupce = 5;
    int sirka = 5;
    int vyska = 5;
    for (int i = 0; i < radky; i++) {
        for (int j = 0; j < sloupce; j++) {
            kvetina(sirka, vyska);
            for(int k = 0; k < (sirka); k++) {
                move_right();
            }
        }
        for (int i = 0; i < 6; i++) {
            move_down();
        }
        for (int i = 0; i < 100; i++) {
            move_left();
        }
    }
    return 0;
}
int cesko(){
    set_blue_color();
    for (int i = 0; i < 2; i++) {
        draw_pixel();
        move_right();
    }
    set_white_color();
    for (int i = 0; i < 16; i++) {
        draw_pixel();
        move_right();
    }
    move_left();
    move_down();
    for (int i = 0; i < 14; i++) {
        draw_pixel();
        move_left();
    }
    set_blue_color();
    for (int i = 0; i < 4; i++) {
        draw_pixel();
        move_left();
    }
    move_down();
    set_blue_color();
    for (int i = 0; i < 6; i++) {
        draw_pixel();
        move_right();
    }
    set_white_color();
    for (int i = 0; i < 12; i++) {
        draw_pixel();
        move_right();
    }
    move_left();
    move_down();
    set_red_color();
    for (int i = 0; i < 12; i++) {
        draw_pixel();
        move_left();
    }
    set_blue_color();
    for (int i = 0; i < 6; i++) {
        draw_pixel();
        move_left();
    }
    move_down();
    set_blue_color();
    for (int i = 0; i < 4; i++) {
        draw_pixel();
        move_right();
    }
    set_red_color();
    for (int i = 0; i < 14; i++) {
        draw_pixel();
        move_right();
    }
    move_down();
    move_left();
    set_red_color();
    for (int i = 0; i < 16; i++) {
        draw_pixel();
        move_left();
    }
    set_blue_color();
    for (int i = 0; i < 2; i++) {
        draw_pixel();
        move_left();
    }
    return 0;
}

int animace(){
    for (int i = 0; i < 10; i++) {
        move_to(i,i);
        cesko();
        animate();
        clear_screen();    
        }
    for (int i = 10; i > 0; i--) {
        move_to(i,i);
        cesko();
        animate();
        clear_screen();    
        }
    return 0;
}
