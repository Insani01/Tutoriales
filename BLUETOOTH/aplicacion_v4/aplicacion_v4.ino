#include <SoftwareSerial.h>
#include "Vennom.h"
SoftwareSerial SerialBT(9, 8); // RX, TX

char ch = ' ';
boolean b_programacion = false, b_control = false, b_distancia = false, b_rgb = false;
int size = 0, song = 0, cont = 0;
String trama_array[16] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0","0", "0", "0"};
String dato = "", dd = "";

Vennom robot;

void setup() {
  //Serial.begin(9600);
  //SerialBT.begin(9600);
  Serial.begin(115200);
  SerialBT.begin(115200);
}

void loop() {
  
  if (SerialBT.available() > 0) {
    ch = SerialBT.read();
    //Serial.println(ch);  // depuración.
    if (b_programacion)
    {
      programacion(ch, 500);
      //ch = ' ';
    }
    else if (b_control) {
      control(ch);
      ch = ' ';
    }

    if (ch == '?') {
      delay(500);
      SerialBT.println("v1~");
      SerialBT.flush();
    } else if (ch == 'c') {
      SerialBT.flush();
      b_programacion = false;
      b_control = true;
    } else if (ch == 'p') {
      delay(500);
      SerialBT.flush();
      b_programacion = true;
      b_control = false;
    }
  }
}


void programacion(char o, int espera) {
  if (o == '~') {
    delay(espera);
    if (b_rgb) {
      recibir_rgb();
    } else {
      for (int j = 0; j <= 16; j++) {
        Serial.println(trama_array[j]);
        actuar (trama_array[j]);
      }
      robot.MoverVennom("detener");
      // limpiamos el array
      for (int k = 0; k <= 16; k++) {
        trama_array[k] = "0";
      }
      dato = "";
      cont = 0;
    }
  } else {
    delay(80);
    if (o == ',') {
      trama_array[cont] = dd;
      dd = "";
      cont++;
    } else {
      dd = dd + o;
    }
  }
}

void control(char p) {
  if (b_rgb) {
    programacion(p, 10);
  } else {
    if (p == '0') press_cero();
    else if (p == '1')  press_3();
    else if (p == '2')  press_4();
    else if (p == '3')  press_1();
    else if (p == '4')  press_2();
    //else if (p == '6')  send_dista = true;
    //else if (p == '7')  send_dista = false;
    else if (p == 'a')  press_cancion(0);
    else if (p == 'b')  press_cancion(1);
    else if (p == 'c')  press_cancion(2);
    else if (p == 'd')  press_cancion(3);
    else if (p == 'e')  press_cancion(4);
    else if (p == 'f')  press_cancion(5);
    else if (p == 'g')  press_cancion(6);
    else if (p == 'h')  press_cancion(7);
    else if (p == 'i')  press_cancion(8);
    else if (p == 'j')  press_cancion(9);
    else if (p == 'z') {
      b_distancia = true;
      //press_evitar_obataculo();
    } else if (p == '$') {
      b_rgb = true;
      delay(80);
    }
  }

}

void recibir_rgb() {
  int r1 = trama_array[0].toInt();
  int g1 = trama_array[1].toInt();
  int b1 = trama_array[2].toInt();
  r1 = 9-r1;
  g1 = 9-g1;
  b1 = 9-b1;
  r1 = map(r1, 0, 9, 0, 255);
  g1 = map(g1, 0, 9, 0, 255);
  b1 = map(b1, 0, 9, 0, 255);
  press_5(r1, g1, b1);
  for (int k = 0; k <= 16; k++) {
    trama_array[k] = "0";
  }
  b_rgb = false;
  dato = "";
  cont = 0;

}

void actuar(String comando) {
  String nada="0" ,adelante = "31", atras = "32", derecha = "33", izquierda = "34", g_de_90 = "35", g_iz_90 = "36",  g_180 = "37", g_360 = "38",
  c_rojo = "39", c_verde = "40", c_azul = "41", c_morado = "42",
  cn_saludo = "a",cn_detec = "b",cn_cont = "c",cn_enoj = "d",cn_mario = "e",cn_despa = "f";
  if (nada.equals(comando));
  else if (adelante.equals(comando)) a_adelante();
  else if (atras.equals(comando)) a_atras();
  else if (derecha.equals(comando)) a_derecha();
  else if (izquierda.equals(comando)) a_izquierda();
  else if (g_iz_90.equals(comando)) a_g90_iz();
  else if (g_de_90.equals(comando)) a_g90_de();
  else if (g_180.equals(comando)) a_g180();
  else if (g_360.equals(comando)) a_g360();
  else if (c_rojo.equals(comando)) press_5(255,0,0);
  else if (c_verde.equals(comando)) press_5(0,255,0);
  else if (c_azul.equals(comando)) press_5(0,0,255);
  else if (c_morado.equals(comando)) press_5(150,150,100);
  else if (cn_saludo.equals(comando))  press_cancion(0);
  else if (cn_detec.equals(comando))  press_cancion(1);
  else if (cn_cont.equals(comando))  press_cancion(2);
  else if (cn_enoj.equals(comando))  press_cancion(3);
  else if (cn_mario.equals(comando))  press_cancion(4);
  else if (cn_despa.equals(comando))  press_cancion(5);
  
}

void press_cero() {
  robot.MoverVennom("detener");
  robot.LED_RGB(0, 0, 0);
}
void press_1() {
  robot.MoverVennom("adelante");
  robot.LED_RGB(0, 255, 0);
}
void press_2() {
  robot.MoverVennom("atras");
  robot.LED_RGB(255, 0, 0);
}

void press_3() {
  robot.MoverVennom("derecha");
  robot.LED_RGB(0, 0, 255);
}

void press_4() {
  robot.MoverVennom("izquierda");
  robot.LED_RGB(0, 0, 255);
}

void press_5(int r, int g, int b) {
  //Serial.print(ch);
  robot.LED_RGB(r, g, b);
}
void press_cancion(int aa) {
  String can="";
  switch (aa) {
    case 0:
    can="saludo";
    break;
    case 1:
    can="deteccion";
    break;
    case 2:
    can="contento";
    break;
    case 3:
    can="enojado";
    break;
    case 4:
    can="mario";
    break;
    case 5:
    can="despacito";
    break;
    }
    robot.Cantante(can);
}

/*
void press_evitar_obataculo() {
  if (b_distancia) {
    int a = 2;
    while (a > 1) {
      if (SerialBT.available() > 0) {
        char h = SerialBT.read();
        if (h == 'x') {
          b_distancia = false;
          a = 0;
          press_cero();
        }
      }
      int cm = robot.Distancia();
      if (cm < 7) {
        a_atras();
        a_derecha();
      } else  press_1();
    }
    press_cero();
  }
}*/

void a_adelante() {
  robot.MoverVennom("adelante");
  robot.LED_RGB(0, 255, 0);
  delay(1000);
  ch = ' ';
}

void a_atras() {
  robot.MoverVennom("atras");
  robot.LED_RGB(255, 0, 0);
  delay(1000);
  ch = ' ';
}

void a_derecha() {
  robot.MoverVennom("derecha");
  robot.LED_RGB(0, 0, 255);
  delay(1000);
  ch = ' ';
}

void a_izquierda() {
  robot.MoverVennom("izquierda");
  robot.LED_RGB(0, 0, 255);
  delay(1000);
  ch = ' ';
}

void a_g90_de() {
  robot.GiroVennom(90, "derecho");
  robot.LED_RGB(0, 0, 255);
  delay(500);
  ch = ' ';
}

void a_g90_iz() {
  robot.GiroVennom(90, "izquierdo");
  robot.LED_RGB(0, 0, 255);
  delay(500);
  ch = ' ';
}

void a_g180() {
  robot.GiroVennom(180, "izquierdo");
  robot.LED_RGB(0, 0, 255);
  delay(2000);
  ch = ' ';
}

void a_g360() {
  robot.GiroVennom(360, "derecho");
  robot.LED_RGB(0, 0, 255);
  delay(4000);
  ch = ' ';
}


