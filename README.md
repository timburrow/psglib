# adequate_AD
 adequate_AD - Pulse sequence for 1-1 Adequate, uses adiabatic and "av180"
 13C 180
 degree pulses. References: - B.Rief, M.Koeck, R.Kerssebaum, H.Kang,
 W.Fenical, and C.Griesinger, J. Magn. Reson. A 118, 282 (1996). -
 M.Koeck, B.Rief, W.Fenical, and C.Griesinger, Tetrahedron Lett. 37(3),
 363 (1996).

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

Your name:      Ronald C. Crouch, Agilent        ron.crouch@agilent.com
                Peter Sandor, Agilent            peter.sandor@agilent.com

Date submitted: 2003-05-22 - Original submission

File name:      adequate_AD.c
Directory:      psglib
Description:    Pulse sequence for 1-1 Adequate, uses adiabatic and "av180"
                13C 180 degree pulses. References:
                 - B.Rief, M.Koeck, R.Kerssebaum, H.Kang, W.Fenical, and
                   C.Griesinger, J. Magn. Reson. A 118, 282 (1996).
                 - M.Koeck, B.Rief, W.Fenical, and C.Griesinger, Tetrahedron
                   Lett. 37(3), 363 (1996).

Related files:  docs/adequate_AD.pdf    manual/adequate_AD
                maclib/adequate_AD      parlib/adequate_AD.par

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     UNITY INOVA, WFG on 13C channel
Known software version compatibility:   VNMR 6.1C
Special instructions for installation:
    If you are downloading from the Internet, store the file

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout adequate_AD-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/adequate_AD-v1.0.zip

Read adequate_AD.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/adequate_AD