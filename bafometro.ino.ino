//Robson Correia
#include "U8glib.h"#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

#include <string.h>
#include <Wire.h>

#define Mussum_4_width 44
#define Mussum_4_height 50
static unsigned char Mussum_4_bits[] = {
  0xff, 0xff, 0xbf, 0xff, 0xff, 0x0f, 0xdb, 0xb6, 0x01, 0xe8, 0xb6, 0x0d,
  0xff, 0x7f, 0x00, 0xc0, 0xff, 0x0f, 0x6d, 0x1b, 0x00, 0x80, 0xb6, 0x0d,
  0xff, 0x0f, 0x00, 0x00, 0xfe, 0x0f, 0xdb, 0x06, 0x20, 0x00, 0xb4, 0x0d,
  0xff, 0x03, 0xda, 0x01, 0xf8, 0x0f, 0xdb, 0xc0, 0xff, 0x00, 0x60, 0x0d,
  0xff, 0x40, 0x5b, 0x00, 0xe0, 0x0f, 0xdb, 0xc0, 0x3f, 0x00, 0xc0, 0x0d,
  0x7f, 0xc0, 0x16, 0x00, 0xc0, 0x0f, 0x36, 0xc0, 0x0f, 0x00, 0xa0, 0x0d,
  0x7f, 0x40, 0x0d, 0x00, 0xc0, 0x0f, 0x2d, 0xe0, 0x7b, 0x00, 0x80, 0x0d,
  0x3f, 0xe0, 0x0f, 0x00, 0xc0, 0x0f, 0x36, 0xa0, 0x36, 0x00, 0x80, 0x0d,
  0x3f, 0xe0, 0x1f, 0x00, 0xc0, 0x07, 0x36, 0xf8, 0x07, 0x00, 0x80, 0x0e,
  0x3f, 0x00, 0x06, 0x00, 0xc0, 0x0f, 0x36, 0x00, 0x02, 0x00, 0x80, 0x0d,
  0x3f, 0x00, 0x80, 0x00, 0xc0, 0x0f, 0x6d, 0x08, 0x02, 0x00, 0x80, 0x0d,
  0x7f, 0x00, 0x02, 0x00, 0xc0, 0x0f, 0xed, 0x40, 0x83, 0x18, 0xc0, 0x0d,
  0xbf, 0xf6, 0x03, 0x1f, 0x40, 0x0f, 0xf6, 0xaf, 0x0b, 0x1b, 0xe0, 0x0d,
  0xdf, 0xce, 0x16, 0x0e, 0xe0, 0x0f, 0xfb, 0xc5, 0x03, 0x0c, 0xe0, 0x0d,
  0xdf, 0x23, 0x03, 0x10, 0x80, 0x0b, 0xbb, 0x01, 0x01, 0x00, 0x00, 0x01,
  0xff, 0x80, 0x03, 0x00, 0x80, 0x01, 0xdb, 0x40, 0x0d, 0x00, 0x80, 0x03,
  0xff, 0x80, 0x3f, 0x10, 0xc0, 0x02, 0xdb, 0x80, 0x5f, 0x00, 0xe0, 0x0f,
  0xff, 0x01, 0x1f, 0x00, 0xc0, 0x06, 0xad, 0xe3, 0x1f, 0x00, 0xf0, 0x0f,
  0xff, 0xce, 0x1b, 0x00, 0x68, 0x0f, 0xdb, 0x8f, 0x0f, 0x00, 0xf8, 0x0d,
  0x7f, 0xdb, 0x00, 0x00, 0x6c, 0x0f, 0xf6, 0xdf, 0x01, 0x00, 0xfc, 0x0d,
  0xdf, 0xfa, 0x1f, 0x00, 0xb6, 0x0f, 0xfb, 0x6f, 0x0a, 0x00, 0xfe, 0x0d,
  0x6f, 0x7f, 0x00, 0x00, 0xdb, 0x0f, 0xfd, 0x6d, 0x00, 0x80, 0xbf, 0x0d,
  0x6f, 0xbf, 0x00, 0xc0, 0xf6, 0x0f, 0xfd, 0xf6, 0x00, 0xe0, 0xbf, 0x0d,
  0xf7, 0xdf, 0x00, 0xa0, 0xed, 0x0f, 0x6f, 0xfb, 0x00, 0xe0, 0x7f, 0x0d,
  0xff, 0xaf, 0x00, 0x60, 0xda, 0x0f, 0xda, 0xfe, 0x00, 0xb4, 0xff, 0x0d
};
float metabolizaPorHora;
float gramasDeAlcoolConsumidas;
int tempo_aquecimento = 2;
unsigned long time;
String texto;
int peso;
int estado;
int posicao;
int passo;
unsigned int valor_sensor;
int x;
int n;
int y;
int velocidade = 1;
int status = 1;
boolean trava = true;
boolean trava2 = true;
boolean trava3 = true;
boolean trava4 = true;
boolean trava5 = true;
boolean trava6 = true;
boolean trava7 = true;
boolean trava8 = true;
boolean trava9 = true;
boolean trava10 = true;
boolean trava11 = true;
unsigned long tempoColeta;
unsigned long contagemRegressiva;
unsigned long Delay;
unsigned int graficoLeft;
unsigned int graficoTop;
int left;
int left1;
int top;
int left2;
int top2;
int centena;
int dezena;
int unidade;
int posicaoMussum = 2;
float tempo;
int horas;
int minutos;
int ajuste = 65;
//========================================================================
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255, 255, 255);
  }
}
//========================================================================
void loop() {
  //Leitura do valor do sensor
  sensor();
  //Movimenta o texto
  posicao -= 2;
  //Conversão de milisegundos em segundos
  time = millis() / 1000;

  u8g.firstPage();
  //tempo de aquecimento do sensor.
  if (time <= tempo_aquecimento) {
    time = map(time, 0, tempo_aquecimento, 0, 30);
  }
  else {
    status = 0;
    //========================================================================
    if (passo == 99) {
      if (Delay > time) {
        if (trava5 == true) {
          trava5 = false;
          Serial.println("Numeros com apenas tres caracteres.");
        }
      }
      else {
        passo = 0;
      }
    }
    //========================================================================
    if (passo == 98) {
      if (Delay > time) {
        if (trava6 == true) {
          trava6 = false;
          Serial.println("Apenas numeros.");
        }
      }
      else {
        passo = 0;
      }
    }
    //========================================================================
    if (passo == 97) {
      if (Delay > time) {
        if (trava11 == true) {
          trava11 = false;
          Serial.println("Digite um valor para peso acima de 30 kg.");
        }
      }
      else {
        passo = 0;
      }
    }
    //========================================================================
    if (passo == 0) {
      Serial.println("Digite seu peso:");
      passo++;
    }
    //========================================================================
    if (passo == 1) {
      guardarPeso();
    }
    //========================================================================
    if (passo == 2) {
      if (Delay >= time) {
        if (trava3 == true) {
          posicao = 0;
          trava3 = false;
          Serial.print(peso);
          Serial.println("kg.");
        }
      } else {
        passo++;
      }
    }
    //========================================================================
    if (passo == 3) {
      Delay = time + 6;
      passo++;
    }
    //========================================================================
    if (passo == 4) {
      aguardeContagem();
    }
    //========================================================================
    if (passo == 5) {
      contagem();
    }
    //========================================================================
    if (passo == 6) {
      tempoColeta = time + 4;
      passo++;
    }
    //========================================================================
    if (passo == 7) {
      coleta();
    }
    //========================================================================
    if (passo == 8) {
      aguardeContagem();
    }
    //========================================================================
    if (passo == 9) {
      contagem();
    }
    //========================================================================
    if (passo == 10) {
      tempoColeta = time + 4;
      passo++;
    }
    //========================================================================
    if (passo == 11) {
      coleta();
    }
    //========================================================================
    if (passo == 12) {
      aguardeContagem();
    }
    //========================================================================
    if (passo == 13) {
      contagem();
    }
    //========================================================================
    if (passo == 14) {
      tempoColeta = time + 4;
      passo++;
    }
    //========================================================================
    if (passo == 15) {
      coleta();
    }
    //========================================================================
    if (passo == 16) {
      y = n / 3;
      gramasDeAlcoolConsumidas = y * 0.45;
      metabolizaPorHora = peso * 0.1;
      tempo = (gramasDeAlcoolConsumidas / metabolizaPorHora) * 60;
      Tempo();
      passo++;
    }
    //========================================================================
    if (passo == 17) {
      if (Delay >= time) {
        if (trava4 == true) {
          trava4 = false;
          Serial.println("Gramas de alcool consumidas: ");
          Serial.print(gramasDeAlcoolConsumidas);
          Serial.println("g." );
        }
      }
      else {
        posicao = -2;
        passo++;
      }
    }

    //========================================================================
    //Reset
    if (Serial.read() == 'r') {
      reset();
    }
  }
  //========================================================================
  do
  {
    draw();
  }
  while ( u8g.nextPage() );
  delay(10);
}
void draw() {
  //========================================================================
  u8g.drawRFrame(0, 16, 128, 48, 2);
  if (status == 1) {
    u8g.setFont(u8g_font_8x13B);
    u8g.drawStr( 30, 15, "BAFOMETRO");
    u8g.drawStr( 10, 37, "Aguarde");
    caneca();
    if (time == 0)
    {
      time = 1;
    }
    u8g.drawBox(79, 25, 22, time);
    u8g.setColorIndex(1);
  }
  //========================================================================
  if ((passo >= 1) && (passo <= 15)) {
    grafico();
  }
  //========================================================================
  if ((passo >= 3) && (passo <= 15)) {
    u8g.setFont(u8g_font_8x13B);
    u8g.setPrintPos(0, 10);
    u8g.print(valor_sensor);
  }
  //========================================================================
  if (passo == 1) {
    canecaSensor();
    u8g.setColorIndex(1);
    u8g.drawRFrame(0, 16, 128, 48, 4);

    u8g.setFont(u8g_font_8x13B);
    u8g.setPrintPos(posicao, 10);
    u8g.print("Seu peso sera usado no calculo.");
    u8g.setPrintPos(5, 38);
    u8g.print("Digite");
    u8g.setPrintPos(5, 52);
    u8g.print("seu peso.");
  }
  //========================================================================
  if (passo == 2) {
    u8g.setFont(u8g_font_8x13B);
    u8g.setPrintPos(posicao, 10);
    u8g.print("Seu peso foi armazenado.");

    u8g.setFont(u8g_font_fub20);
    u8g.setPrintPos(60, 50);
    u8g.print("kg");
    if (peso < 10) {
      left2 = 44;
    }
    else if (peso < 100) {
      left2 = 30;
    }
    else {
      left2 = 14;
    }
    u8g.setFont(u8g_font_fub20);
    u8g.setPrintPos(left2, 50);
    u8g.print(peso);
  }
  //========================================================================
  if (passo == 4) {
    textoAguardeContagem();
  }
  //========================================================================
  if (passo == 5) {
    textoContagem();
  }
  //========================================================================
  if (passo == 7) {
    textoColeta();
  }
  //========================================================================
  if (passo == 8) {
    textoAguardeContagem();
  }
  //========================================================================
  if (passo == 9) {
    textoContagem();
  }
  //========================================================================
  if (passo == 11) {
    textoColeta();
  }
  //========================================================================
  if (passo == 12) {
    textoAguardeContagem();
  }
  //========================================================================
  if (passo == 13) {
    textoContagem();
  }
  //========================================================================
  if (passo == 15) {
    textoColeta();
  }
  //========================================================================
  if (passo == 17) {
    textoGramasDeAlcoolConsumidos();
  }
  //========================================================================
  if (passo == 18) {
    if (Serial.available() == 1) {
      if (Serial.read() == 'r') {
        reset();
        return;
      }
      else {
        Serial.println("Digite 'r' para resetar.");
      }
    }
    //.......................................................................
    if ((minutos == 0) && (horas == 0)) {
      if (trava7 == true) {
        posicao = 0;
        trava7 = false;
        Serial.println("Voce pode dirigir normalmente.");
      }
      //.....................................................................
      u8g.setPrintPos(posicao, 10);
      u8g.print("Digite 'r' para resetar.");
      u8g.setFont(u8g_font_8x13B);
      u8g.setPrintPos(6, 30);
      u8g.print("Voce pode ");
      u8g.setPrintPos(6, 45);
      u8g.print("dirigir");
      u8g.setPrintPos(6, 60);
      u8g.print("normalmente.");
    }
    //.......................................................................
    else if (horas == 0) {
      if (trava8 == true) {
        trava8 = false;
        posicao = 0;
        Serial.print("Deve aguardar aproximadamente ");
        Serial.print(minutos);
        if (minutos > 1) {
          Serial.println(" minutos.");
        }
        else {
          Serial.println(" minuto.");
        }
      }
      //.......................................................................
      u8g.setPrintPos(posicao, 10);
      u8g.print("Aguarde o tempo,repita o teste.");
      u8g.setFont(u8g_font_8x13B);
      u8g.setPrintPos(6, 30);
      u8g.print("Deve aguardar");
      u8g.setPrintPos(6, 45);
      u8g.print("aproximadamente");
      u8g.setPrintPos(6, 60);
      u8g.print(minutos);
      if (minutos < 10) {
        u8g.setPrintPos(14, 60);
      }
      else {
        u8g.setPrintPos(24, 60);
      }
      if (minutos > 1) {
        u8g.println(" minutos.");
      }
      else {
        u8g.println(" minuto.");
      }
    }
    //.......................................................................
    else if ((horas > 0) && (minutos == 0)) {
      if (trava9 == true) {
        posicao = 0;
        trava9 = false;
        Serial.print("Deve aguardar aproximadamente ");
        Serial.print(horas);
        if (horas > 1) {
          Serial.println(" horas.");
        }
        else {
          Serial.println(" hora.");
        }
      }
      //.......................................................................
      u8g.setPrintPos(posicao, 10);
      u8g.print("Aguarde o tempo,repita o teste.");
      u8g.setFont(u8g_font_8x13B);
      u8g.setPrintPos(6, 30);
      u8g.print("Deve aguardar");
      u8g.setPrintPos(6, 45);
      u8g.print("aproximadamente");
      u8g.setPrintPos(6, 60);
      u8g.print(horas);
      u8g.setPrintPos(30, 60);
      if (horas > 1) {
        u8g.println("horas.");
      }
      else {
        u8g.print("hora.");
      }
    }
    //.......................................................................
    else if (horas > 0) {
      if (trava10 == true) {
        posicao = 0;
        trava10 = false;
        Serial.print("Deve aguardar aproximadamente ");
        Serial.print(horas);
        if (horas > 1) {
          Serial.print(" horas e ");
        }
        else {
          Serial.print(" hora e ");
        }
        Serial.print(minutos);
        if (minutos > 1) {
          Serial.println(" minutos.");

        }
        else {
          Serial.println(" minuto.");
        }
      }
      //.......................................................................
      u8g.setPrintPos(posicao, 10);
      u8g.print("Aguarde o tempo,repita o teste.");
      u8g.setFont(u8g_font_8x13B);
      u8g.setPrintPos(6, 30);
      u8g.print("Deve aguardar");
      u8g.setPrintPos(6, 45);
      u8g.print(horas);
      if (horas < 10) {
        u8g.setPrintPos(20, 45);
      }
      else {
        u8g.setPrintPos(24, 45);
      }
      u8g.print("horas e ");
      u8g.setPrintPos(6, 60);
      u8g.print(minutos);
      if (minutos < 10) {
        u8g.setPrintPos(14, 60);
      }
      else {
        u8g.setPrintPos(18, 60);
      }
      u8g.print(" minutos.");
    }
  }
  //========================================================================
  if (passo == 97) {
    u8g.setFont(u8g_font_8x13B);
    u8g.setPrintPos(6, 29);
    u8g.print("Digite um valor");
    u8g.setPrintPos(6, 44);
    u8g.print("para peso");
    u8g.setPrintPos(6, 59);
    u8g.print("acima de 30kg.");
  }
  //========================================================================
  if (passo == 99) {
    u8g.setFont(u8g_font_8x13B);
    u8g.setPrintPos(24, 29);
    u8g.print("Numero com ");
    u8g.setPrintPos(18, 44);
    u8g.print("apenas tres ");
    u8g.setPrintPos(20, 59);
    u8g.print("caracteres");
  }
  //========================================================================
  if (passo == 98) {
    u8g.setFont(u8g_font_8x13B);
    u8g.setPrintPos(8, 44);
    u8g.print("Apenas numeros.");
    u8g.setPrintPos(posicao, 10);
    u8g.print("Nao digite letras.");
  }
}
//========================================================================
void reset() {
  trava = true;
  trava2 = true;
  trava3 = true;
  trava4 = true;
  trava5 = true;
  trava6 = true;
  trava7 = true;
  trava8 = true;
  trava9 = true;
  trava10 = true;
  trava11 = true;
  minutos = 0;
  horas = 0;
  tempo = 0;
  passo = 0;
  peso = 0;
  x = 0;
  n = 0;
  y = 0;
}
//========================================================================
void Tempo() {

  if (tempo >= 1380) {
    horas = 23;
    minutos = tempo - 1380;
  }
  else if (tempo >= 1320) {
    horas = 22;
    minutos = tempo - 1320;
  }
  else if (tempo >= 1260) {
    horas = 21;
    minutos = tempo - 1260;
  }
  else if (tempo >= 1200) {
    horas = 20;
    minutos = tempo - 1200;
  }
  else if (tempo >= 1140) {
    horas = 19;
    minutos = tempo - 1140;
  }
  else if (tempo >= 1080) {
    horas = 18;
    minutos = tempo - 1080;
  }
  else if (tempo >= 1020) {
    horas = 17;
    minutos = tempo - 1020;
  }
  else if (tempo >= 960) {
    horas = 16;
    minutos = tempo - 960;
  }
  else if (tempo >= 900) {
    horas = 15;
    minutos = tempo - 900;
  }
  else if (tempo >= 840) {
    horas = 14;
    minutos = tempo - 840;
  }
  else if (tempo >= 780) {
    horas = 13;
    minutos = tempo - 780;
  }
  else if (tempo >= 720) {
    horas = 12;
    minutos = tempo - 720;
  }
  else if (tempo >= 660) {
    horas = 11;
    minutos = tempo - 660;
  }
  else if (tempo >= 600) {
    horas = 10;
    minutos = tempo - 600;
  }
  else if (tempo >= 540) {
    horas = 9;
    minutos = tempo - 540;
  }
  else if (tempo >= 480) {
    horas = 8;
    minutos = tempo - 480;
  }
  else if (tempo >= 420) {
    horas = 7;
    minutos = tempo - 420;
  }
  else if (tempo >= 360) {
    horas = 6;
    minutos = tempo - 360;
  }
  else if (tempo >= 300) {
    horas = 5;
    minutos = tempo - 300;
  }
  else if (tempo >= 240) {
    horas = 4;
    minutos = tempo - 240;
  }
  else if (tempo >= 180) {
    horas = 3;
    minutos = tempo - 180;
  }
  else if (tempo >= 120) {
    horas = 2;
    minutos = tempo - 120;
  }
  else if (tempo >= 60) {
    horas = 1;
    minutos = tempo - 60;
  }
  else {
    minutos = tempo;
  }
}
//========================================================================
void sensor() {

  valor_sensor = analogRead(A0);

  if (valor_sensor <= ajuste) {
    valor_sensor = ajuste;
  }
  valor_sensor = map(valor_sensor, ajuste, 1024, 0, 1000);

  //animação da caneca
  graficoLeft = map(valor_sensor, 0, 200, 2, 126);
  if (graficoLeft >= 126) {
    graficoLeft = 126;
  }
  if (graficoLeft <= 2) {
    graficoLeft = 2;
  }
  graficoTop = map(valor_sensor, 0, 200, 1, 30);
  if (graficoTop >= 30) {
    graficoTop = 30;
  }
  if (graficoTop <= 1) {
    graficoTop = 1;
  }
}
//========================================================================
void guardarPeso() {
  if (Serial.available() > 3) {
    trava5 = true;
    Delay = time + 4;
    passo = 99;
  }
  else if (Serial.available() == 3) {
    centena = Serial.read() - 48;
    dezena = Serial.read() - 48;
    unidade = Serial.read() - 48;
    peso = (centena * 100) + (dezena * 10) + unidade;
    if (centena >= 10 or centena < 0 or dezena >= 10 or dezena < 0 or unidade >= 10 or unidade < 0) {
      trava6 = true;
      Delay = time + 4;
      passo = 98;
    }
    else {
      Delay = time + 5;
      passo++;
    }
  }
  else if (Serial.available() == 2) {
    dezena = Serial.read() - 48;
    unidade = Serial.read() - 48;
    peso = (dezena * 10) + unidade;
    if (peso <= 30) {
      trava11 = true;
      Delay = time + 5;
      passo = 97;
    }
    else {
      if (dezena >= 10 or dezena < 0 or unidade >= 10 or unidade < 0) {
        trava6 = true;
        Delay = time + 4;
        passo = 98;
      }
      else {
        Delay = time + 5;
        passo++;
      }
    }
  }
  else if (Serial.available() == 1) {
    unidade = Serial.read() - 48;
    peso =  unidade;
    if (peso <= 10) {
      trava11 = true;
      Delay = time + 5;
      passo = 97;
    } else {
      if (unidade >= 10 or unidade < 0) {
        trava6 = true;
        Delay = time + 4;
        passo = 98;
      }
      else {
        Delay = time + 5;
        passo++;
      }
    }
  }
}
//========================================================================
void caneca() {
  u8g.drawBox(80, 25, 20, 30);
  u8g.drawHLine(77, 24, 26);
  u8g.drawRFrame(78, 25 , 24, 32, 0);
  u8g.drawRFrame(77, 25 , 26, 32, 0);
  u8g.drawHLine(76, 57, 28);
  u8g.drawHLine(76, 58, 28);
  u8g.drawRFrame(102, 30 , 7, 20, 2);
  u8g.drawRFrame(102, 28 , 9, 24, 2);
  u8g.setColorIndex(0);
}
//========================================================================
void canecaSensor() {
  u8g.drawBox(94, 25, 20, 30);
  u8g.drawHLine(91, 24, 26);
  u8g.drawRFrame(92, 25 , 24, 32, 0);
  u8g.drawRFrame(91, 25 , 26, 32, 0);
  u8g.drawHLine(90, 57, 28);
  u8g.drawHLine(90, 58, 28);
  u8g.drawRFrame(116, 30 , 7, 20, 2);
  u8g.drawRFrame(116, 28 , 9, 24, 2);
  u8g.setColorIndex(0);
  u8g.drawBox(93, 26, 22, graficoTop);
  u8g.setColorIndex(1);
}
//========================================================================
void contagem() {
  if ((contagemRegressiva - time == 3) && (trava == true)) {
    trava = false;
    texto = "3";
    Serial.println(texto);
  }
  if ((contagemRegressiva - time == 2) && (trava == false)) {
    trava = true;
    texto = "2";
    Serial.println(texto);
  }
  if ((contagemRegressiva - time == 1) && (trava == true)) {
    trava = false;
    texto = "1";
    Serial.println(texto);
  }
  if ((contagemRegressiva == time) && (trava == false)) {
    trava = true;
    texto = "Assopre!";
    Serial.println(texto);
    passo++;
  }
}
//========================================================================
void textoContagem() {
  u8g.setFont(u8g_font_8x13B);

  u8g.setFont(u8g_font_fub20);
  u8g.setPrintPos(74, 50);
  u8g.print(texto);
  u8g.drawXBM(posicaoMussum, 16, Mussum_4_width, Mussum_4_height, Mussum_4_bits);
}
//========================================================================
void coleta() {

  if (tempoColeta >= time) {
    sensor();
    if (valor_sensor > x) {
      x = valor_sensor;
    }
  }
  else {
    n += x;
    x = 0;
    Delay = time + 3;
    passo++;
  }
}
//========================================================================
void textoColeta() {
  u8g.setFont(u8g_font_fub20);
  u8g.setPrintPos(8, 50);
  u8g.print("Assopre!");
}
//========================================================================
void aguardeContagem() {
  if (Delay >= time) {
    if (trava2 == true) {
      posicao = 0;
      trava2 = false;
      texto = "Aguarde o fim da contagem regressiva para assoprar!";
      Serial.println(texto);
    }
  }
  else {
    trava2 = true;
    contagemRegressiva = time + 5;
    passo++;
    texto = "";
  }
}
//========================================================================
void textoAguardeContagem() {
  u8g.setFont(u8g_font_8x13B);
  u8g.setPrintPos(12, 29);
  u8g.print("Aguarde o fim");
  u8g.setPrintPos(18, 44);
  u8g.print("da contagem");
  u8g.setPrintPos(10, 59);
  u8g.print("para assoprar.");
}
//========================================================================
void textoGramasDeAlcoolConsumidos() {
  u8g.setFont(u8g_font_8x13B);
  u8g.setPrintPos(posicao, 10);
  u8g.print("Gramas de alcool consumidas: " );

  u8g.setFont(u8g_font_fub20);
  u8g.setPrintPos(8, 50);
  u8g.print(gramasDeAlcoolConsumidas);
}
//========================================================================
void grafico() {
  u8g.drawBox(0, 13, graficoLeft, 2);
}
//========================================================================
