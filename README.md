# cconh
 cconh - This contribution includes the following pulse sequences (based on
 code written by Lewis Kay, U.Toronto), including auxiliary macros for
 the creation of the necessary SLP pulse shapes: - c_co_nh , known as
 C(CO)NH in the literature; - two gradient versions of C(CO)NH, with
 and without seduce decoupling in place of a 180 C13 pulse, which
 appear to give equivalent results; - the equivalent two gradient
 versions of CBCA(CO)NH.

 Copyright 2016 University of Oregon

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

                                SUBMISSION FORM

Submitter:      George A. Gray, Varian
Date submitted: 1995-10-31

File name:      cconh   (all files written by Robin Bendall, James Cook
                        University, Townsville, Australia)
Directory:      psglib
Description:    This contribution includes the following pulse sequences
                (based on code written by Lewis Kay, U.Toronto), including
                auxiliary macros for the creation of the necessary SLP pulse
                shapes:
                 - c_co_nh , known as C(CO)NH in the literature;
                 - two gradient versions of C(CO)NH, with and without seduce
                   decoupling in place of a 180 C13 pulse, which appear to
                   give equivalent results;
                 - the equivalent two gradient versions of CBCA(CO)NH.

Related files:  maclib/c_co_nhcal   maclib/convolute     maclib/make180CO
                maclib/make180Ca    maclib/make90CO      maclib/makedipsi2
                maclib/makehard     maclib/makeseduce1   maclib/makesinc
                maclib/makesquare
                manual/c_co_nh      manual/gc_co_nh      manual/gc_co_nh2
                manual/gcbca_co_nh  manual/gcbca_co_nh2
                parlib/c_co_nh.par  parlib/gc_co_nh.par  parlib/gc_co_nh2.par
                parlib/gcbca_co_nh.par        parlib/gcbca_co_nh2.par
                psglib/c_co_nh.c    psglib/gc_co_nh.c    psglib/gc_co_nh2.c
                psglib/gcbca_co_nh.c          psglib/gcbca_co_nh2.c


Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     third rf channel/WFG/PFG
Known software version compatibility:   VNMR 5.1
Known OS version compatibility:         n.a.
Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout cconh-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/cconh-v1.0.zip

Read cconh.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/cconh