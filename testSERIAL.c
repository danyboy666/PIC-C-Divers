#include "chemin du fichier\testSERIAL.h"

void main()
{
   char Dat;
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

  dat =0;
  printf("%c%c",0xfe,0x1);   //efface l'affichace et met le curseur au d�but de la ligne:1
  printf(" TEST RS232 et SLCD\n\r  sur PIC 18F4550\n\rLab 2a cours:243-444");   //important 20 caract�res par ligne
  delay_MS(3000);

   While (true)
   {
      if (dat == 255) dat =0 ;
      dat = dat +1;
      printf("%c%c",0xfe,0xd9);   // met le curseur au 6 caract�res de la ligne:4, r�f�rence: melab Serial LCD
      printf("valeur = %d ",dat);   // envoie dat sur le port RS232 TX
      delay_MS(1000);     
   }
}

