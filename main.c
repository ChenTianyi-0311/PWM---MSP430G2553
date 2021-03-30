
/*把帽子套在P1.6和P2.5上*/

#include <msp430.h>
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    BCSCTL1= CALBC1_1MHZ;         //frequence d’horloge 1MHz
    DCOCTL= CALDCO_1MHZ;
    P2DIR |= BIT2;                // P2.2 en sortie
    P2SEL |= BIT2;                // selection fonction TA1.1
    P2SEL2 &= ~BIT2;              // selection fonction TA1.1
    TA1CTL = TASSEL_2 | MC_1;     // source SMCLK pour TimerA (no 2), mode comptage Up
    TA1CCTL1 |= OUTMOD_7;         // activation mode de sortie n°7
    TA1CCR0 = 20000 - 1;          // determine la periode du signal
    TA1CCR1 = 1500;               // determine le rapport cyclique du signal
    while(1);                     // plus rien a faire (le timer est autonome !)
}
