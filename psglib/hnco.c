/* hnco.c  -   modified HNCO experiment by Kay et al.; uses shifted
		   laminar pulses for selective inversion of the Ca
		   spins during t1; uses a broadband inversion pulse to
		   refocus the Ca-N15 and CO-N15 scalar interactions
		   during t2; uses broadband H1 decoupling during t1,
		   t2, and both tau(cn) periods; the C13 and N15 RF
		   channels are user-selectable.


   Parameters:

      sspul = 'y':  selects for Trim(x)-Trim(y) sequence at the start
		    of the pulse sequence
      f1180 = 'n':  standard t1 timing
              'y':  modified t1 timing for t1(1) = half the dwell time
      f2180 = 'n':  standard t2 timing
              'y':  modified t2 timing for t2(1) = half the dwell time
              'n':  normal experiment
       fad1 = 'y':  TPPI axial-peak displacement along t1
              'n':  standard phasecycle
       fad2 = 'y':  TPPI axial-peak displacement along t2 (3D experiment)
              'n':  standard phasecycle
     satmode = 'n':  no H1 presaturation
              'y':  H1 presaturation during relaxation delay
     satfrq = frequency of H1 presaturation for all periods
     satdly = saturation time during the relaxation period
     satpwr = power level for presaturation with the transmitter
      hdlvl = power level for H1 broadband decoupling during t(cn), t1, and t2
    hdshape = H1 broadband decoupling sequence
      hdres = tip-angle resolution for H1 broadband decoupling sequence
       hd90 = 90 degree pulse length for H1 broadband decoupling
      hdfrq = NOT DEFINED ==> tof is assumed to define the center of the H1
	      broadband decoupling profile
         hs = 'yn':  homospoil pulse (hst) during the d1 relaxation delay
       tpwr = power level for H1 transmitter pulses
         pw = 90 degree xmtr pulse length for protons (the observed nucleus)
      cafrq = frequency for Ca spins (not explicitly used in pulse sequence)
      cofrq = frequency for CO spins
    pwcalvl = power level for Ca decoupler pulses
       pwca = 90 degree decoupler pulse length for Ca at `pwcalvl`
    cashape = Ca pattern for shifted laminar pulse
    pwcolvl = power level for C0 decoupler pulses
       pwco = 90 degree decoupler pulse length for C0 at `pwcolvl`
   pwcoalvl = power level for broadband C13 pulse
      pwcoa = 90 degree decoupler pulse length for C13 at `pwcoalvl`
     c13dev = RF device for C13
   pwn15lvl = power level for N15 decoupler pulses
      pwn15 = 90 degree decoupler pulse length for N15
     n15dev = RF device for N15
        jnh = one-bond heteronuclear coupling constant to NH (in Hz)
    deltanh = if deltanh < 0.2e-6, deltanh = 1/(2*jnh)
      taunh = should be set to 5.55 ms (or 1/[2*90]); if taunh < 0.2e-6,
	      taunh = 1/(2*jnh)
        jcn = one-bond heteronuclear coupling constant to CN (in Hz)
  dpwr(N15) = power level for N15 broadband decoupling
  dpwr(C13) = power level for C13 broadband decoupling
    dm(N15) = 'nn':  no broadband decoupling of N15 during acquisition
              'ny':  broadband heteronuclear decoupling of N15
		     during acquisition
    dm(C13) = 'nn':  no broadband decoupling of C13 during acquisition

      phase = 1,2:  hypercomplex experiment with F1 quadrature (complex F1-FT)
     phase2 = 1,2:  hypercomplex experiment with F2 quadrature (complex F2-FT)
                    modified from hnco3FSP.c (1/27/92) (S.Farmer author)
*/



#include <standard.h>
#include <math.h>

#define MIN_DELAY		0.2e-6	/* shortest executable delay */
#define MIN_J			0.1	/* Hz  */
#define MIN_NULL		0.0001	/* sec */


static int	   count = 0,
		 phs1[4] = {0,0,2,2},
		 phs2[2] = {1,3},
		 phs3[2] = {0,2},
		 phs4[4] = {0,1,2,3},
		 phs5[4] = {0,1,2,3},
		 phs6[4] = {2,3,0,1},
		 phs7[2] = {0,2},
		 phs8[2] = {0,2},
		 phs9[2] = {0,1},
		rec[128] = {0,2,2,0,2,0,0,2,2,0,0,2,0,2,2,0,
			    2,0,0,2,0,2,2,0,0,2,2,0,2,0,0,2,
			    2,0,0,2,0,2,2,0,0,2,2,0,2,0,0,2,
			    0,2,2,0,2,0,0,2,2,0,0,2,0,2,2,0,
			    2,0,0,2,0,2,2,0,0,2,2,0,2,0,0,2,
                            0,2,2,0,2,0,0,2,2,0,0,2,0,2,2,0,
			    0,2,2,0,2,0,0,2,2,0,0,2,0,2,2,0,
                            2,0,0,2,0,2,2,0,0,2,2,0,2,0,0,2};

static double	d2_init = 0.0,
		d3_init = 0.0,
		t1adj_1 = 0.0,
		t1adj_2 = 0.0,
		t1adj_3 = 0.0,
		t1adj_4 = 0.0,
		tmpd2 = 0.0;

extern double	getvalnwarn();


/*-------------------------------
|				|
|       pulsesequence()/0	|
|				|
+------------------------------*/
pulsesequence()
{
/* Variable declaration */
   char         satmode[MAXSTR],
		sspul[MAXSTR],
		fad1[MAXSTR],
		f1180[MAXSTR],
		f2180[MAXSTR],
		cashape[MAXSTR],
		prtinfo[MAXSTR],
		hdshape[MAXSTR],
		*dmc13,
		*dmn15;
   int          phase,
		satmove,
		t1_counter,
		exp3D,
		c13dev,
		n15dev;
   double       ss,
		sw1,
		sw2,
		deltacn,
		taunh,
		deltanh,
		delayval,
		t1evol_1,
		t1evol_2,
		t1evol_3,
		t1evol_4,
		d2local,
		cofrq,
                pwcoalvl,
                pwcoa,
                pwcalvl,
                pwca,
                pwcolvl,
                pwco,
                pwn15lvl,
                pwn15,
                jnh,
                jcn,
                satfrq,
                satdly,
                satpwr,
		hd90,
		hdres,
		hdlvl;


/* Load variables */
   satfrq = getval("satfrq");
   satdly = getval("satdly");
   satpwr = getval("satpwr");
   hdlvl = getval("hdlvl");
   hd90 = getval("hd90");
   hdres = getval("hdres");
   cofrq = getval("cofrq");
   pwcoalvl = getval("pwcoalvl");
   pwcoa = getval("pwcoa");
   pwcalvl = getval("pwcalvl");
   pwca = getval("pwca");
   pwcolvl = getval("pwcolvl");
   pwco = getval("pwco");
   pwn15lvl = getval("pwn15lvl");
   pwn15 = getval("pwn15");
   taunh = getval("taunh");
   deltanh = getval("deltanh");
   jnh = getval("jnh");
   jcn = getval("jcn");
   ss = getval("ss");
   sw1 = getval("sw1");
   phase = (int) (getval("phase") + 0.5);
   c13dev = (int) (getval("c13dev") + 0.5);
   n15dev = (int) (getval("n15dev") + 0.5);

   getstr("sspul", sspul);
   getstr("fad1", fad1);
   getstr("satmode", satmode);
   getstr("f1180", f1180);
   getstr("prtinfo", prtinfo);
   getstr("cashape", cashape);
   getstr("hdshape", hdshape);


/* Initialize variables */
   deltacn = ( (jcn > MIN_J) ? 1/(2*jcn) : 0.0 );
   if (taunh < MIN_DELAY)
      taunh = ( (jnh > MIN_J) ? 1/(2*jnh) : 0.0 );
   if (deltanh < MIN_DELAY)
      deltanh = ( (jnh > MIN_J) ? 1/(2*jnh) : 0.0 );


/* Setup phasecycle */
   settable(t1, 4, phs1);
   settable(t2, 2, phs2);
   settable(t3, 2, phs3);
   settable(t4, 4, phs4);
   settable(t5, 4, phs5);
   settable(t6, 4, phs6);
   settable(t7, 2, phs7);
   settable(t8, 2, phs8);
   settable(t9, 2, phs9);
   settable(t10, 128, rec);

   setdivnfactor(t2, 32);
   setdivnfactor(t4, 64);
   setdivnfactor(t5, 64);
   setdivnfactor(t6, 64);
   setdivnfactor(t7, 4);
   setdivnfactor(t8, 16);
   setdivnfactor(t9, 8);


/* Check conditions */
   satmove = ( fabs(tof - satfrq) >= 0.1 );
   exp3D = ( (int) (getvalnwarn("ni2") + 0.5) > 0 );

   if ( (n15dev != DODEV) && (n15dev != DO2DEV) )
   {
      text_error("invalid RF device for N15\n");
      abort(1);
   }
   else if ( (c13dev != DODEV) && (c13dev != DO2DEV) ) 
   { 
      text_error("invalid RF device for C13\n");
      abort(1); 
   }
   else if (c13dev == n15dev)
   {
      text_error("N15 and C13 RF devices must be different\n");
      abort(1);
   }

   dmn15 = ( (n15dev == DODEV) ? dm : dm2 );
   dmc13 = ( (c13dev == DODEV) ? dm : dm2 );

   if ( (strcmp(dmn15, "n") != 0) && (strcmp(dmn15, "nn") != 0) &&
	(strcmp(dmn15, "ny") != 0) )
   {
      text_error("`dm(N15)` must be to 'n', 'nn', or 'ny'\n");
      abort(1);
   }

   if ( (strcmp(dmc13, "n") != 0) && (strcmp(dmc13, "nn") != 0) )
   {
      text_error("`dm(C13)` must be to 'n' or 'nn'\n");
      abort(1);
   }



/* Determine steady-state mode */
   if (ss < 0)
   {
      ss *= (-1);
      initval(ss, ssval);
      initval(ss, ssctr);
   }


/* Add in States-Haberkorn element */
   if (phase == 2)
      tsadd(t3, 1, 4);

   if (exp3D)
   {
      int	phase2;

      phase2 = (int) (getval("phase2") + 0.5);
      if (phase2 == 2)
         tssub(t1, 1, 4);
   }


/* Add in FAD */
   if (fad1[A] == 'y')
   {
      if (ix == 1)
        d2_init = d2;

      t1_counter = (int) ( (d2 - d2_init)*sw1 + 0.5 );
      if (t1_counter % 2)
      {
         tsadd(t3, 2, 4);	/* first CO 90 phase cycle	*/
         tsadd(t10, 2, 4);	/* receiver phase cycle		*/
      }
   }

   if (exp3D)
   {
      char	fad2[MAXSTR];
      int	t2_counter;

      sw2 = getval("sw2");
      getstr("fad2", fad2);
      getstr("f2180", f2180);

      if (fad2[A] == 'y')
      {
         if (ix == 1)
           d3_init = d3;
 
         t2_counter = (int) ( (d3 - d3_init)*sw2 + 0.5 );
         if (t2_counter % 2)
         {   
            tsadd(t1, 2, 4);       /* first N15 90 phase cycle     */
            tsadd(t10, 2, 4);      /* receiver phase cycle         */
         }
      }
   }


/* BEGIN ACTUAL PULSE SEQUENCE CODE */
   status(A);
      rlpower(tpwr, TODEV);		/*  H1 hard-pulse power level	*/
      rlpower(pwn15lvl, n15dev);	/* N15 hard-pulse power level	*/
      rlpower(pwcolvl, c13dev); 	/* CO pulse power		*/
      offset(cofrq, c13dev); 		/* CO frequency			*/

      if (sspul[A] == 'y')
      {
         rgpulse(200*pw, zero, rof1, 0.0);
         rgpulse(200*pw, one, 0.0, rof2);
         hsdelay(d1);
      }
      else
      {
         hsdelay(d1);
      }

/* selective saturation period */
      if (satmode[A] == 'y')
      {
         if (satmove)
            offset(satfrq, TODEV);

         rlpower(satpwr, TODEV);
         rgpulse(satdly, zero, 4.0e-5, 0.2e-6);
         if (satmove)
            offset(tof, TODEV);

         rlpower(tpwr, TODEV);
         delay(1.0e-5);
      }


/* Pulse train */
      rcvroff();
      genqdphase(t3, c13dev);           /* CO phase  */


/* INEPT transfer from H1 to N15 */
      rgpulse(pw, zero, rof1, 5.0e-6);
      txphase(t2);			/* H1 phase  */
      genqdphase(t1, n15dev);		/* N15 phase */

      delay(deltanh - 5.0e-6);

      gensim2pulse(2*pw, pwn15, zero, t1, 0.0, 5.0e-6, TODEV, n15dev);
      txphase(t2);			/* H1 phase  */
      genqdphase(t5, n15dev);		/* N15 phase */
      delay(deltanh - 5.0e-6);

      rgpulse(pw, t2, 0.0, 0.0);


/* HMQC established between N15 and C13.  Let NH interaction
   refocus before starting H1 broadband decoupling.  */
      rlpower(hdlvl, TODEV);
      txphase(zero);			/* absolute H1 phase for BBD	*/
      obsprgon(hdshape, hd90, hdres);	/* start up H1 WFG for BBD	*/
      delay(taunh - POWER_DELAY - PRG_START_DELAY);

      xmtron();				/* turn on H1 RF now!		*/
      delay(deltacn - deltanh - taunh - pw);


/* Calculate t1 evolution times */
      if (ix == 1)
      {
         t1adj_1 = (2*pwco/M_PI) + pwca + WFG_START_DELAY;
         t1adj_2 = pwn15 + pwca + WFG_STOP_DELAY;
         t1adj_3 = pwn15 + pwca + WFG_START_DELAY;
         t1adj_4 = (2*pwco/M_PI) + pwca + WFG_STOP_DELAY + 3.0e-6;

         t1adj_1 += POWER_DELAY;
         t1adj_4 += POWER_DELAY;

         t1evol_1 = (8 * sw1) * ( MIN_DELAY + t1adj_1 );
         t1evol_2 = (8 * sw1) * ( MIN_DELAY + t1adj_2 );
         t1evol_3 = (8 * sw1) * ( MIN_DELAY + t1adj_3 );
         t1evol_4 = (8 * sw1) * ( MIN_DELAY + t1adj_4 );

         tmpd2 = ( (t1evol_1 > t1evol_2) ? t1evol_1 : t1evol_2 );
         if (t1evol_3 > tmpd2)
            tmpd2 = t1evol_3;
         if (t1evol_4 > tmpd2)
            tmpd2 = t1evol_4;

         count = (int) (tmpd2) + 1;
         if (prtinfo[0] == 'y')
         {
            char   msge[128];
            double maxsw1;

            maxsw1 = ( (f1180[0] == 'y') ? (sw1/tmpd2) : (2*sw1)/tmpd2 );
            (void) sprintf(msge, "\nMaximum C13 spectral width = %d\n",
				(int) (maxsw1 + 0.5) );
            text_error(msge);
         }

         tmpd2 = count * (0.5/sw1);
      }

      if ( (f1180[0] != 'y') && (count < 3) )
      {
         t1evol_1 = (d2/4) - t1adj_1;
         t1evol_2 = (d2/4) - t1adj_2;
         t1evol_3 = (d2/4) - t1adj_3;
         t1evol_4 = (d2/4) - t1adj_4;
      }
      else
      {
         if ( (count > 2) || ((f1180[0] == 'y') && (count > 1)) )
         {
            if (ix == 1)
               text_error("WARNING:  sw1 is too large for proper t1 timing\n");
         }

         d2local = d2 + tmpd2;
         t1evol_1 = (d2local/4) - t1adj_1;
         t1evol_2 = (d2local/4) - t1adj_2;
         t1evol_3 = (d2local/4) - t1adj_3;
         t1evol_4 = (d2local/4) - t1adj_4;
      }

      if (t1evol_1 < MIN_DELAY)
         t1evol_1 = 0.0;
      if (t1evol_2 < MIN_DELAY)
         t1evol_2 = 0.0;
      if (t1evol_3 < MIN_DELAY)
         t1evol_3 = 0.0;
      if (t1evol_4 < MIN_DELAY)
         t1evol_4 = 0.0;


/* Start C13 pulsing */
      genrgpulse(pwco, t3, 0.0, 0.0, c13dev);

      rlpower(pwcalvl, c13dev);	/* Ca power level		*/
      genqdphase(t4, c13dev);		/* Ca phase			*/
      delay(t1evol_1);

      genshaped_pulse(cashape, 2*pwca, t4, 0.0, 0.0, 0.0, 0.0, c13dev);
      delay(t1evol_2);

      genqdphase(t6, c13dev);
      genrgpulse(2*pwn15, t5, 0.0, 0.0, n15dev);
      delay(t1evol_3);

      genshaped_pulse(cashape, 2*pwca, t6, 0.0, 0.0, 0.0, 0.0, c13dev);

      rlpower(pwcolvl, c13dev);      /* CO power level	  	*/
      genqdphase(t7, c13dev);		/* CO phase			*/
      genqdphase(zero, n15dev);		/* N15 phase			*/
      delay(t1evol_4 + 3.0e-6);

      genrgpulse(pwco, t7, 0.0, 0.0, c13dev);

      rlpower(pwcoalvl, c13dev);	/* C13 broadband pulse power 	*/
      genqdphase(zero, c13dev);		/* C13 phase			*/


/* Remove HMQC between N15 and C13 */
      delayval = deltacn - deltanh - taunh - 2*POWER_DELAY -
			PRG_STOP_DELAY - 2*pw;
      if (exp3D)
         delayval -= 8*pwcoa;

      delay(delayval);


/* 3D section for N15 t2 evolution */
      if (exp3D)
      {
         double	t2evol;

         t2evol = d3;
         if (f2180[0] == 'y')
            t2evol += (0.5/sw2);

         delay(t2evol/2);

         genrgpulse(pwcoa, zero, 0.0, 0.0, c13dev);
         genrgpulse(2*pwcoa, one, 0.0, 0.0, c13dev);
         genrgpulse(pwcoa, zero, 0.0, 0.0, c13dev);

         delay(t2evol/2);

         genrgpulse(pwcoa, zero, 0.0, 0.0, c13dev);
         genrgpulse(2*pwcoa, one, 0.0, 0.0, c13dev);
         genrgpulse(pwcoa, zero, 0.0, 0.0, c13dev);
      }

      xmtroff();			/* turn off H1 RF for BBD	*/
      rlpower(tpwr, TODEV);
      txphase(one);
      obsprgoff();			/* turn of H1 WFG for BBD	*/
      rgpulse(pw, one, 0.0, 5.0e-6);	/* H1 purge pulse		*/


/* Re-establish H1-N15 antiphase magnetization */
      txphase(t8);			/* H1 phase	*/
      delay(taunh - 5.0e-6);


/* REVINEPT transfer from N15 back to H1 */
      rgpulse(pw, t8, 0.0, 5.0e-6);
      txphase(t9);			/* H1 phase  */
      delay(deltanh - 5.0e-6);

      gensim2pulse(2*pw, pwn15, t9, zero, 0.0, 0.0, TODEV, n15dev);

      rlpower(dpwr, DODEV);		/* N15 or C13 decoupling power */
      rlpower(dpwr2, DO2DEV);		/* C13 or N15 decoupling power */
      genqdphase(zero, n15dev);		/* N15 decoupling phase */
      genqdphase(zero, c13dev);		/* C13 final phase */
      delay(rof2);
      rcvron();

      delay(deltanh - 2*POWER_DELAY - PRG_START_DELAY - rof2);


/* Start N15 broadband decoupling */
   status(B);
      setreceiver(t10);
}
