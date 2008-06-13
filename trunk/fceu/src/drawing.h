#include <assert.h>

void DrawTextLineBG(uint8 *dest)
{
 int x,y;
 static int otable[7]={81,49,30,17,8,3,0};
        //100,40,15,10,7,5,2};
 for(y=0;y<14;y++)
 {
  int offs;

  if(y>=7) offs=otable[13-y];
  else offs=otable[y];   
          
  for(x=offs;x<(256-offs);x++)
  {
   // Choose the dimmest set of colours and then dim that
   dest[y*256+x]=(dest[y*256+x]&0x0F)|0xC0;
  }
 }
}

static void DrawMessage(void)
{
 if(howlong)
  {
   uint8 *t;
   howlong--;
   t=XBuf+(FSettings.LastSLine-16)*256;
   
   /*
          FCEU palette:
            $00: [8] unvpalette found in palettes/palettes.h
              black, white, black, greyish, redish, bright green, bluish
            $80:
              nes palette
            $C0:
              dim version of nes palette
           
   */
   
   if(t>=XBuf)
   {
     int color = 0x20;
     if(howlong == 39) color = 0x38;
     if(howlong <= 30) color = 0x2C;
     if(howlong <= 20) color = 0x1C;
     if(howlong <= 10) color = 0x11;
     if(howlong <= 5) color = 0x1;
     //DrawTextTrans(t, 256, (uint8 *)errmsg, color+0x80);
     DrawTextTrans(t, 256, (uint8 *)errmsg, 0x20+0x80);
   }
  }
}

uint8 fontdata2[2048] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x81,0xa5,0x81,0xbd,0x99,0x81,0x7e,0x7e,0xff,0xdb,0xff,0xc3,0xe7,0xff,0x7e,0x36,0x7f,0x7f,0x7f,0x3e,0x1c,0x08,0x00,0x08,0x1c,0x3e,0x7f,0x3e,0x1c,0x08,0x00,0x1c,0x3e,0x1c,0x7f,0x7f,0x3e,0x1c,0x3e,0x08,0x08,0x1c,0x3e,0x7f,0x3e,0x1c,0x3e,0x00,0x00,0x18,0x3c,0x3c,0x18,0x00,0x00,0xff,0xff,0xe7,0xc3,0xc3,0xe7,0xff,0xff,0x00,0x3c,0x66,0x42,0x42,0x66,0x3c,0x00,0xff,0xc3,0x99,0xbd,0xbd,0x99,0xc3,0xff,0xf0,0xe0,0xf0,0xbe,0x33,0x33,0x33,0x1e,0x3c,0x66,0x66,0x66,0x3c,0x18,0x7e,0x18,0xfc,0xcc,0xfc,0x0c,0x0c,0x0e,0x0f,0x07,0xfe,0xc6,0xfe,0xc6,0xc6,0xe6,0x67,0x03,0x99,0x5a,0x3c,0xe7,0xe7,0x3c,0x5a,0x99,0x01,0x07,0x1f,0x7f,0x1f,0x07,0x01,0x00,0x40,0x70,0x7c,0x7f,0x7c,0x70,0x40,0x00,0x18,0x3c,0x7e,0x18,0x18,0x7e,0x3c,0x18,0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x00,0xfe,0xdb,0xdb,0xde,0xd8,0xd8,0xd8,0x00,0x7c,0xc6,0x1c,0x36,0x36,0x1c,0x33,0x1e,0x00,0x00,0x00,0x00,0x7e,0x7e,0x7e,0x00,0x18,0x3c,0x7e,0x18,0x7e,0x3c,0x18,0xff,0x18,0x3c,0x7e,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x7e,0x3c,0x18,0x00,0x00,0x18,0x30,0x7f,0x30,0x18,0x00,0x00,0x00,0x0c,0x06,0x7f,0x06,0x0c,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x7f,0x00,0x00,0x00,0x24,0x66,0xff,0x66,0x24,0x00,0x00,0x00,0x18,0x3c,0x7e,0xff,0xff,0x00,0x00,0x00,0xff,0xff,0x7e,0x3c,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x1e,0x1e,0x0c,0x0c,0x00,0x0c,0x00,0x36,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x36,0x36,0x7f,0x36,0x7f,0x36,0x36,0x00,0x0c,0x3e,0x03,0x1e,0x30,0x1f,0x0c,0x00,0x00,0x63,0x33,0x18,0x0c,0x66,0x63,0x00,0x1c,0x36,0x1c,0x6e,0x3b,0x33,0x6e,0x00,0x06,0x06,0x03,0x00,0x00,0x00,0x00,0x00,0x18,0x0c,0x06,0x06,0x06,0x0c,0x18,0x00,0x06,0x0c,0x18,0x18,0x18,0x0c,0x06,0x00,0x00,0x66,0x3c,0xff,0x3c,0x66,0x00,0x00,0x00,0x0c,0x0c,0x3f,0x0c,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0x06,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x0c,0x00,0x60,0x30,0x18,0x0c,0x06,0x03,0x01,0x00,0x3e,0x63,0x73,0x7b,0x6f,0x67,0x3e,0x00,0x0c,0x0e,0x0c,0x0c,0x0c,0x0c,0x3f,0x00,0x1e,0x33,0x30,0x1c,0x06,0x33,0x3f,0x00,0x1e,0x33,0x30,0x1c,0x30,0x33,0x1e,0x00,0x38,0x3c,0x36,0x33,0x7f,0x30,0x78,0x00,0x3f,0x03,0x1f,0x30,0x30,0x33,0x1e,0x00,0x1c,0x06,0x03,0x1f,0x33,0x33,0x1e,0x00,0x3f,0x33,0x30,0x18,0x0c,0x0c,0x0c,0x00,0x1e,0x33,0x33,0x1e,0x33,0x33,0x1e,0x00,0x1e,0x33,0x33,0x3e,0x30,0x18,0x0e,0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,0x06,0x18,0x0c,0x06,0x03,0x06,0x0c,0x18,0x00,0x00,0x00,0x3f,0x00,0x00,0x3f,0x00,0x00,0x06,0x0c,0x18,0x30,0x18,0x0c,0x06,0x00,0x1e,0x33,0x30,0x18,0x0c,0x00,0x0c,0x00,
0x3e,0x63,0x7b,0x7b,0x7b,0x03,0x1e,0x00,0x0c,0x1e,0x33,0x33,0x3f,0x33,0x33,0x00,0x3f,0x66,0x66,0x3e,0x66,0x66,0x3f,0x00,0x3c,0x66,0x03,0x03,0x03,0x66,0x3c,0x00,0x1f,0x36,0x66,0x66,0x66,0x36,0x1f,0x00,0x7f,0x46,0x16,0x1e,0x16,0x46,0x7f,0x00,0x7f,0x46,0x16,0x1e,0x16,0x06,0x0f,0x00,0x3c,0x66,0x03,0x03,0x73,0x66,0x7c,0x00,0x33,0x33,0x33,0x3f,0x33,0x33,0x33,0x00,0x1e,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e,0x00,0x78,0x30,0x30,0x30,0x33,0x33,0x1e,0x00,0x67,0x66,0x36,0x1e,0x36,0x66,0x67,0x00,0x0f,0x06,0x06,0x06,0x46,0x66,0x7f,0x00,0x63,0x77,0x7f,0x7f,0x6b,0x63,0x63,0x00,0x63,0x67,0x6f,0x7b,0x73,0x63,0x63,0x00,0x1c,0x36,0x63,0x63,0x63,0x36,0x1c,0x00,0x3f,0x66,0x66,0x3e,0x06,0x06,0x0f,0x00,0x1e,0x33,0x33,0x33,0x3b,0x1e,0x38,0x00,0x3f,0x66,0x66,0x3e,0x36,0x66,0x67,0x00,0x1e,0x33,0x07,0x0e,0x38,0x33,0x1e,0x00,0x3f,0x2d,0x0c,0x0c,0x0c,0x0c,0x1e,0x00,0x33,0x33,0x33,0x33,0x33,0x33,0x3f,0x00,0x33,0x33,0x33,0x33,0x33,0x1e,0x0c,0x00,0x63,0x63,0x63,0x6b,0x7f,0x77,0x63,0x00,0x63,0x63,0x36,0x1c,0x1c,0x36,0x63,0x00,0x33,0x33,0x33,0x1e,0x0c,0x0c,0x1e,0x00,0x7f,0x63,0x31,0x18,0x4c,0x66,0x7f,0x00,0x1e,0x06,0x06,0x06,0x06,0x06,0x1e,0x00,0x03,0x06,0x0c,0x18,0x30,0x60,0x40,0x00,0x1e,0x18,0x18,0x18,0x18,0x18,0x1e,0x00,0x08,0x1c,0x36,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
0x0c,0x0c,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1e,0x30,0x3e,0x33,0x6e,0x00,0x07,0x06,0x06,0x3e,0x66,0x66,0x3b,0x00,0x00,0x00,0x1e,0x33,0x03,0x33,0x1e,0x00,0x38,0x30,0x30,0x3e,0x33,0x33,0x6e,0x00,0x00,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x1c,0x36,0x06,0x0f,0x06,0x06,0x0f,0x00,0x00,0x00,0x6e,0x33,0x33,0x3e,0x30,0x1f,0x07,0x06,0x36,0x6e,0x66,0x66,0x67,0x00,0x0c,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x30,0x00,0x30,0x30,0x30,0x33,0x33,0x1e,0x07,0x06,0x66,0x36,0x1e,0x36,0x67,0x00,0x0e,0x0c,0x0c,0x0c,0x0c,0x0c,0x1e,0x00,0x00,0x00,0x33,0x7f,0x7f,0x6b,0x63,0x00,0x00,0x00,0x1f,0x33,0x33,0x33,0x33,0x00,0x00,0x00,0x1e,0x33,0x33,0x33,0x1e,0x00,0x00,0x00,0x3b,0x66,0x66,0x3e,0x06,0x0f,0x00,0x00,0x6e,0x33,0x33,0x3e,0x30,0x78,0x00,0x00,0x3b,0x6e,0x66,0x06,0x0f,0x00,0x00,0x00,0x3e,0x03,0x1e,0x30,0x1f,0x00,0x08,0x0c,0x3e,0x0c,0x0c,0x2c,0x18,0x00,0x00,0x00,0x33,0x33,0x33,0x33,0x6e,0x00,0x00,0x00,0x33,0x33,0x33,0x1e,0x0c,0x00,0x00,0x00,0x63,0x6b,0x7f,0x7f,0x36,0x00,0x00,0x00,0x63,0x36,0x1c,0x36,0x63,0x00,0x00,0x00,0x33,0x33,0x33,0x3e,0x30,0x1f,0x00,0x00,0x3f,0x19,0x0c,0x26,0x3f,0x00,0x38,0x0c,0x0c,0x07,0x0c,0x0c,0x38,0x00,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x00,0x07,0x0c,0x0c,0x38,0x0c,0x0c,0x07,0x00,0x6e,0x3b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x1c,0x36,0x63,0x63,0x7f,0x00,
0x1e,0x33,0x03,0x33,0x1e,0x18,0x30,0x1e,0x00,0x33,0x00,0x33,0x33,0x33,0x7e,0x00,0x38,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x7e,0xc3,0x3c,0x60,0x7c,0x66,0xfc,0x00,0x33,0x00,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x07,0x00,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x0c,0x0c,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x00,0x00,0x1e,0x03,0x03,0x1e,0x30,0x1c,0x7e,0xc3,0x3c,0x66,0x7e,0x06,0x3c,0x00,0x33,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x07,0x00,0x1e,0x33,0x3f,0x03,0x1e,0x00,0x33,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x3e,0x63,0x1c,0x18,0x18,0x18,0x3c,0x00,0x07,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x63,0x1c,0x36,0x63,0x7f,0x63,0x63,0x00,0x0c,0x0c,0x00,0x1e,0x33,0x3f,0x33,0x00,0x38,0x00,0x3f,0x06,0x1e,0x06,0x3f,0x00,0x00,0x00,0xfe,0x30,0xfe,0x33,0xfe,0x00,0x7c,0x36,0x33,0x7f,0x33,0x33,0x73,0x00,0x1e,0x33,0x00,0x1e,0x33,0x33,0x1e,0x00,0x00,0x33,0x00,0x1e,0x33,0x33,0x1e,0x00,0x00,0x07,0x00,0x1e,0x33,0x33,0x1e,0x00,0x1e,0x33,0x00,0x33,0x33,0x33,0x7e,0x00,0x00,0x07,0x00,0x33,0x33,0x33,0x7e,0x00,0x00,0x33,0x00,0x33,0x33,0x3e,0x30,0x1f,0xc3,0x18,0x3c,0x66,0x66,0x3c,0x18,0x00,0x33,0x00,0x33,0x33,0x33,0x33,0x1e,0x00,0x18,0x18,0x7e,0x03,0x03,0x7e,0x18,0x18,0x1c,0x36,0x26,0x0f,0x06,0x67,0x3f,0x00,0x33,0x33,0x1e,0x3f,0x0c,0x3f,0x0c,0x0c,0x1f,0x33,0x33,0x5f,0x63,0xf3,0x63,0xe3,0x70,0xd8,0x18,0x3c,0x18,0x18,0x1b,0x0e,
0x38,0x00,0x1e,0x30,0x3e,0x33,0x7e,0x00,0x1c,0x00,0x0e,0x0c,0x0c,0x0c,0x1e,0x00,0x00,0x38,0x00,0x1e,0x33,0x33,0x1e,0x00,0x00,0x38,0x00,0x33,0x33,0x33,0x7e,0x00,0x00,0x1f,0x00,0x1f,0x33,0x33,0x33,0x00,0x3f,0x00,0x33,0x37,0x3f,0x3b,0x33,0x00,0x3c,0x36,0x36,0x7c,0x00,0x7e,0x00,0x00,0x1c,0x36,0x36,0x1c,0x00,0x3e,0x00,0x00,0x0c,0x00,0x0c,0x06,0x03,0x33,0x1e,0x00,0x00,0x00,0x00,0x3f,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x3f,0x30,0x30,0x00,0x00,0xc3,0x63,0x33,0x7b,0xcc,0x66,0x33,0xf0,0xc3,0x63,0x33,0xdb,0xec,0xf6,0xf3,0xc0,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x00,0x00,0xcc,0x66,0x33,0x66,0xcc,0x00,0x00,0x00,0x33,0x66,0xcc,0x66,0x33,0x00,0x00,0x44,0x11,0x44,0x11,0x44,0x11,0x44,0x11,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xdb,0xee,0xdb,0x77,0xdb,0xee,0xdb,0x77,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1f,0x18,0x18,0x18,0x18,0x18,0x1f,0x18,0x1f,0x18,0x18,0x18,0x6c,0x6c,0x6c,0x6c,0x6f,0x6c,0x6c,0x6c,0x00,0x00,0x00,0x00,0x7f,0x6c,0x6c,0x6c,0x00,0x00,0x1f,0x18,0x1f,0x18,0x18,0x18,0x6c,0x6c,0x6f,0x60,0x6f,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x00,0x00,0x7f,0x60,0x6f,0x6c,0x6c,0x6c,0x6c,0x6c,0x6f,0x60,0x7f,0x00,0x00,0x00,0x6c,0x6c,0x6c,0x6c,0x7f,0x00,0x00,0x00,0x18,0x18,0x1f,0x18,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x18,0x18,0x18,
0x18,0x18,0x18,0x18,0xf8,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xf8,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0xff,0x18,0x18,0x18,0x18,0x18,0xf8,0x18,0xf8,0x18,0x18,0x18,0x6c,0x6c,0x6c,0x6c,0xec,0x6c,0x6c,0x6c,0x6c,0x6c,0xec,0x0c,0xfc,0x00,0x00,0x00,0x00,0x00,0xfc,0x0c,0xec,0x6c,0x6c,0x6c,0x6c,0x6c,0xef,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0xef,0x6c,0x6c,0x6c,0x6c,0x6c,0xec,0x0c,0xec,0x6c,0x6c,0x6c,0x00,0x00,0xff,0x00,0xff,0x00,0x00,0x00,0x6c,0x6c,0xef,0x00,0xef,0x6c,0x6c,0x6c,0x18,0x18,0xff,0x00,0xff,0x00,0x00,0x00,0x6c,0x6c,0x6c,0x6c,0xff,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0xff,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0xff,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0xfc,0x00,0x00,0x00,0x18,0x18,0xf8,0x18,0xf8,0x00,0x00,0x00,0x00,0x00,0xf8,0x18,0xf8,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0xfc,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0x6c,0xff,0x6c,0x6c,0x6c,0x18,0x18,0xff,0x18,0xff,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x18,0x18,0x18,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,
0x00,0x00,0x6e,0x3b,0x13,0x3b,0x6e,0x00,0x00,0x1e,0x33,0x1f,0x33,0x1f,0x03,0x03,0x00,0x3f,0x33,0x03,0x03,0x03,0x03,0x00,0x00,0x7f,0x36,0x36,0x36,0x36,0x36,0x00,0x3f,0x33,0x06,0x0c,0x06,0x33,0x3f,0x00,0x00,0x00,0x7e,0x1b,0x1b,0x1b,0x0e,0x00,0x00,0x66,0x66,0x66,0x66,0x3e,0x06,0x03,0x00,0x6e,0x3b,0x18,0x18,0x18,0x18,0x00,0x3f,0x0c,0x1e,0x33,0x33,0x1e,0x0c,0x3f,0x1c,0x36,0x63,0x7f,0x63,0x36,0x1c,0x00,0x1c,0x36,0x63,0x63,0x36,0x36,0x77,0x00,0x38,0x0c,0x18,0x3e,0x33,0x33,0x1e,0x00,0x00,0x00,0x7e,0xdb,0xdb,0x7e,0x00,0x00,0x60,0x30,0x7e,0xdb,0xdb,0x7e,0x06,0x03,0x1c,0x06,0x03,0x1f,0x03,0x06,0x1c,0x00,0x1e,0x33,0x33,0x33,0x33,0x33,0x33,0x00,0x00,0x3f,0x00,0x3f,0x00,0x3f,0x00,0x00,0x0c,0x0c,0x3f,0x0c,0x0c,0x00,0x3f,0x00,0x06,0x0c,0x18,0x0c,0x06,0x00,0x3f,0x00,0x18,0x0c,0x06,0x0c,0x18,0x00,0x3f,0x00,0x70,0xd8,0xd8,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1b,0x1b,0x0e,0x0c,0x0c,0x00,0x3f,0x00,0x0c,0x0c,0x00,0x00,0x6e,0x3b,0x00,0x6e,0x3b,0x00,0x00,0x1c,0x36,0x36,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0xf0,0x30,0x30,0x30,0x37,0x36,0x3c,0x38,0x1e,0x36,0x36,0x36,0x36,0x00,0x00,0x00,0x0e,0x18,0x0c,0x06,0x1e,0x00,0x00,0x00,0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static uint8 Font6x5[594] =
{
	4,  0,  0,  0,  0,  0,
	3, 64, 64, 64,  0, 64,
	5, 80, 80,  0,  0,  0,
	6, 80,248, 80,248, 80,
	6,112,160,112, 40,240,
	6,136, 16, 32, 64,136,
	6, 96, 96,104,144,104,
	3, 64, 64,  0,  0,  0,
	4, 32, 64, 64, 64, 32,
	4, 64, 32, 32, 32, 64,
	7, 72, 48,252, 48, 72,
	6, 32, 32,248, 32, 32,
	3,  0,  0,  0, 64,128,
	5,  0,  0,240,  0,  0,
	3,  0,  0,  0,  0, 64,
	6,  8, 16, 32, 64,128,
	5,240,144,144,144,240, //0
	5, 64,192, 64, 64,224, //1
	5, 96,144, 32, 64,240, //2
	5,240, 16, 96, 16,224, //3
	5, 80,144,240, 16, 16, //4
	5,240,128,224, 16,224, //5
	5, 96,128,224,144, 96, //6
	5,240, 16, 32, 32, 64, //7
	5, 96,144, 96,144, 96, //8
	5, 96,144,112, 16, 96, //9
	3,  0, 64,  0, 64,  0,
	3,  0, 64,  0, 64,128,
	4, 32, 64,128, 64, 32,
	4,  0,224,  0,224,  0,
	4,128, 64, 32, 64,128,
	5, 96,144, 32,  0, 32,
	5, 96,144,176,128, 96,
	5, 96,144,240,144,144,
	5,224,144,224,144,224,
	5,112,128,128,128,112,
	5,224,144,144,144,224,
	5,240,128,224,128,240,
	5,240,128,224,128,128,
	5,112,128,176,144,112,
	5,144,144,240,144,144,
	4,224, 64, 64, 64,224,
	5, 16, 16, 16,144, 96,
	5,144,160,192,160,144,
	5,128,128,128,128,240,
	6,136,216,168,136,136,
	6,136,200,168,152,136,
	5, 96,144,144,144, 96,
	5,224,144,224,128,128,
	5, 96,144,144,176,112,
	5,224,144,224,160,144,
	5, 96,128, 96, 16,224,
	6,248, 32, 32, 32, 32,
	5,144,144,144,144, 96,
	6,136,136, 80, 80, 32,
	6,136,136,136,168, 80,
	6,136, 80, 32, 80,136,
	6,136, 80, 32, 32, 32,
	6,248, 16, 32, 64,248,
	3,192,128,128,128,192,
	6,128, 64, 32, 16,  8,
	3,192, 64, 64, 64,192,
	4, 64,160,  0,  0,  0,
	5,  0,  0,  0,  0,240,
	3,128, 64,  0,  0,  0,
	5, 96, 16,112,144,112,
	5,128,128,224,144,224,
	4,  0, 96,128,128, 96,
	5, 16, 16,112,144,112,
	5,  0, 96,240,128, 96,
	4, 96,128,192,128,128,
	4,  0,224,224, 32,192,
	5,128,128,224,144,144,
	4, 64,  0,192, 64,224,
	3, 64,  0, 64, 64,192,
	5,128,160,192,160,144,
	4,192, 64, 64, 64,224,
	6,  0,208,168,168,136,
	5,  0,224,144,144,144,
	5,  0, 96,144,144, 96,
	5,  0,224,144,224,128,
	5,  0,112,144,112, 16,
	4,  0, 96,128,128,128,
	5,  0, 96,224, 16,224,
	4, 64,224, 64, 64, 32,
	5,  0,144,144,144,112,
	6,  0,136,136, 80, 32,
	6,  0,136,136,168, 80,
	5,  0,144, 96, 96,144,
	5,  0,144,112, 16, 96,
	5,  0,240, 32, 64,240,
	4, 96, 64,128, 64, 96,
	3, 64, 64, 64, 64, 64,
	4,192, 64, 32, 64,192,
	5, 80,160,  0,  0,  0
};

static int FixJoedChar(uint8 ch)
{
    int c = ch; c -= 32;
    return (c < 0 || c > 98) ? 0 : c;
}
static int JoedCharWidth(uint8 ch)
{
    return Font6x5[FixJoedChar(ch)*6];
}


void DrawTextTransWH(uint8 *dest, uint32 width, uint8 *textmsg, uint8 fgcolor, int max_w, int max_h)
{
	unsigned beginx=5, x=beginx;
	unsigned y=2;

	char target[64][256] = {{0}};
	
	assert(width==256);
        if (max_w > 256) max_w = 256;
        if (max_h >  64) max_h =  64;
	
	for(; *textmsg; ++textmsg)
	{
	    int ch, wid;
	    unsigned ny, nx;
	    
	    if(*textmsg == '\n') { x=beginx; y+=6; continue; }
	    ch  = FixJoedChar(*textmsg);
	    wid = JoedCharWidth(*textmsg);
	    
	    for(ny=0; ny<5; ++ny)
	    {
	        uint8 d = Font6x5[ch*6 + 1+ny];
	        for(nx=0; nx<wid; ++nx)
	        {
	            int c = (d >> (7-nx)) & 1;
	            if(c)
	            {
	                if(y+ny >= max_h) goto textoverflow;
	                target[y+ny][x+nx] = 2;
	            }
	            else
	                target[y+ny][x+nx] = 1;
	        }
	    }
		x += wid;
		if(x >= max_w) { x=beginx; y+=6; }
	}
textoverflow:
	for(y=0; y<max_h; ++y)
	    for(x=0; x<max_w; ++x)
	    {
	        int offs = y*width+x;
	        int c = 0;
	        
	        c += target[y][x] * 600;
	        
	        x>=(     1) && (c += target[y][x-1] * 8);
	        x<(width-1) && (c += target[y][x+1] * 8);
	        y>=(     1) && (c += target[y-1][x] * 8);
	        y<(16   -1) && (c += target[y+1][x] * 8);
	        
	        x>=(     1) && y>=(  1) && (c += target[y-1][x-1]*3);
	        x<(width-1) && y>=(  1) && (c += target[y-1][x+1]*3);
	        x>=(     1) && y<(16-1) && (c += target[y+1][x-1]*3);
	        x<(width-1) && y<(16-1) && (c += target[y+1][x+1]*3);
	        
	        x>=(     2) && (c += target[y][x-2]);
	        x<(width-2) && (c += target[y][x+2]);
	        y>=(     2) && (c += target[y-2][x]);
	        y<(16   -2) && (c += target[y+2][x]);
	        
	        x>=(     3) && (c += target[y][x-3]);
	        x<(width-3) && (c += target[y][x+3]);
	        y>=(     3) && (c += target[y-3][x]);
	        y<(16   -3) && (c += target[y+3][x]);
	        
	        if(c >= 1200)
	            dest[offs] = fgcolor;
	        else if(c >= 30)
	        {
	            dest[offs] = (dest[offs] & 0x0F) | 0xC0;
	        }
	        else if(c > 0)
	        {
	            dest[offs] = (dest[offs] & 0x3F) | 0xC0;
	        }
	    }
}

void DrawTextTrans(uint8 *dest, uint32 width, uint8 *textmsg, uint8 fgcolor)
{
	DrawTextTransWH(dest, width, textmsg, fgcolor, 256, 16);
}

static uint8 sstat[2541] =
{
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x80,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,
0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x81,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,
0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x83,0x80,0x80,0x81,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x80,0x83,0x83,0x81,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x81,0x81,0x81,0x83,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x83,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80
};

void FCEU_DrawNumberRow(uint8 *XBuf, int *nstatus, int cur)
{
 uint8 *XBaf;
 int z,x,y;

 XBaf=XBuf - 4 + (FSettings.LastSLine-34)*256;
 if(XBaf>=XBuf)
 for(z=1;z<11;z++)
 {
  if(nstatus[z%10])
   {
    for(y=0;y<13;y++)
     for(x=0;x<21;x++)
      XBaf[y*256+x+z*21+z]=sstat[y*21+x+(z-1)*21*12]^0x80;
   } else {
    for(y=0;y<13;y++)
     for(x=0;x<21;x++)
      if(sstat[y*21+x+(z-1)*21*12]!=0x83)
       XBaf[y*256+x+z*21+z]=sstat[y*21+x+(z-1)*21*12]^0x80;

      else
       XBaf[y*256+x+z*21+z]=(XBaf[y*256+x+z*21+z]&0xF)|0xC0;
   }
  if(cur==z%10)
   {
    for(x=0;x<21;x++)
     XBaf[x+z*21+z*1]=4;
    for(x=1;x<12;x++)
     {
     XBaf[256*x+z*21+z*1]=
     XBaf[256*x+z*21+z*1+20]=4;
     }
    for(x=0;x<21;x++)
     XBaf[12*256+x+z*21+z*1]=4;
   }
  }
}   

static uint8 play_slines[]=
{
	0, 0, 1,
	1, 0, 2,
	2, 0, 3,
	3, 0, 4,
	4, 0, 5,
	5, 0, 6,
	6, 0, 7,
	7, 0, 8,
	8, 0, 7,
	9, 0, 6,
	10, 0, 5,
	11, 0, 4,
	12, 0, 3,
	13, 0, 2,
	14, 0, 1,
	99,
};

static uint8 record_slines[]=
{
	0, 5, 9,
	1, 3, 11,
	2, 2, 12,
	3, 1, 13,
	4, 1, 13,
	5, 0, 14,
	6, 0, 14,
	7, 0, 14,
	8, 0, 14,
	9, 0, 14,
	10, 1, 13,
	11, 1, 13,
	12, 2, 12,
	13, 3, 11,
	14, 5, 9,
	99,
};

static uint8 pause_slines[]=
{
	0, 2, 6,
	1, 2, 6,
	2, 2, 6,
	3, 2, 6,
	4, 2, 6,
	5, 2, 6,
	6, 2, 6,
	7, 2, 6,
	8, 2, 6,
	9, 2, 6,
	10, 2, 6,
	11, 2, 6,
	12, 2, 6,
	13, 2, 6,
	14, 2, 6,

	0, 9, 13,
	1, 9, 13,
	2, 9, 13,
	3, 9, 13,
	4, 9, 13,
	5, 9, 13,
	6, 9, 13,
	7, 9, 13,
	8, 9, 13,
	9, 9, 13,
	10, 9, 13,
	11, 9, 13,
	12, 9, 13,
	13, 9, 13,
	14, 9, 13,
	99,
};

static uint8 no_slines[]=
{
	99
};

static uint8* sline_icons[4]=
{
	no_slines,
	play_slines,
	record_slines,
	pause_slines
};

void FCEU_DrawRecordingStatusN(uint8* XBuf, int n)
{
	uint8* slines=sline_icons[n];
	int i;

	XBuf += (FSettings.LastSLine-28)*256 + 240 + 255;
	for(i=0; slines[i]!=99; i+=3)
	{
		int y=slines[i];
		uint8* dest=XBuf+(y*256);
		int x;
		for(x=slines[i+1]; x!=slines[i+2]; ++x)
			dest[x]=0;
	}

	XBuf -= 255;
	for(i=0; slines[i]!=99; i+=3)
	{
		int y=slines[i];
		uint8* dest=XBuf+(y*256);
		int x;
		for(x=slines[i+1]; x!=slines[i+2]; ++x)
			dest[x]=4;
	}
}