/*  sklbax-
      water suppression using soft-hard-lock pulse sequence
      see Sklenar and Bax, JMR 75,378(1987)
     requires: linear amp.      version 4.1 vnmr

     A low-power(ca. 5ms pw90) pulse on H2O (on-resonance) puts H2O in
     xy plane. Immediately after, a high power 90 rotates the water to 
     the z-axis and the other spectral lines into the xy plane. A spinlock
     pulse (1-2ms) at the same high power then spinlocks the spectrum along
     the axis of the rf while the water dephases via rf inhomogeneity. The 
     fid is then detected, giving a water-suppressed spectrum with small
     first-order(lp) phase correction and uniform excitation across the 
     spectrum (as opposed to the sine-modulated excitation in binomial
     family of 1-1,1-3-3-1, etc). The short time of the sequence allows
     observation of protons undergoing fast exchange with the water, protons
     that would normally be unobserved in a presat experiment

     The soft pulse must be carefully calibrated, an can be optimized to a
     precision of better than 1%. A suggested procedure is to set satpwr for
     approx. a 5ms pw90. Then array satdly from 1 to 10 (satdly is created as
     a delay, not a pulse, in the parameter set. It is divided by 1000 in the 
     pulse statement). Select the best suppression value of satdly and make a new
     array bracketing this value, for example between 4 and 6 if the best value 
     was 5. Repeat this selection and bracketing to higher precision values of
     satdly until no further improvement is noted. Do this with the acquisition
     conditions of d1 and at desired for the final spectrum.

     G. Gray   Palo Alto  Sept 1991    
*/

#include <standard.h>

pulsesequence()
{
   double satdly,satpwr,trim,phaseinc;
   stepsize(0.5,TODEV);
   phaseinc = getval("phaseinc");
   phaseinc =2.0*phaseinc;
    if (phaseinc < 0.0) phaseinc=720+phaseinc;
   initval(phaseinc,v1);
   loadtable("sklbax");
     trim   = getval("trim");
     satdly = getval("satdly");    
     satpwr = getval("satpwr");
     tpwr = getval("tpwr");
     initval(satpwr,v2); initval(tpwr,v3);
   status(A);
     power(v2,TODEV);        /* reduced xmtr power for soft pulse */
     xmtrphase(v1);     /* correction for phase error from power switch */
     hsdelay(d1);
     rgpulse(satdly*1e-3,t1,4.0e-6,0.0);          /*satdly entered in ms*/
     power(v3,TODEV);
     xmtrphase(zero);                 /* return to normal phase control */
     rgpulse(pw,t2,10.0e-6,0.0);
     rgpulse(trim,t3,0.0,rof2);
     setreceiver(t4);
   status(B);
}
/* sklbax
t1 = 3 3 3 3 1 1 1 1 
t2 = 0 2 0 2 0 2 0 2
t3 = 1 1 3 3 1 1 3 3
t4 = 0 1 0 1 0 1 0 1
*/
