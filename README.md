# hsqc3rf_C13dec
 hsqc3rf_C13dec - hsqc using third channel for X pulses and decoupling uses
 second
 channel for optional 13C decoupling in di-labelled molecules. uses
 status-controlled C=O decoupling in t1 with C(alpha) decoupling using
 an SLP 180 degree pulse in t1.

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
Date submitted: 1992-10-27
		1994-01-31 (removed redifinition of POWER_DELAY; changed
			    dec2pulse to dec2rgpulse; macro bug fixed - Krish)

File name:      hsqc3rf_C13dec
Directory:      psglib
Description:    hsqc using third channel for X pulses and decoupling
                uses second channel for optional 13C decoupling in di-labelled
                molecules. uses status-controlled C=O decoupling in t1 with
                C(alpha) decoupling using an SLP 180 degree pulse in t1.

Related files:  maclib/hsqc3rf_C13dec, manual/hsqc3rf_C13dec,
                parlib/hsqc3rf_C13dec

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     third rf channel/wfg
Known software version compatibility:   VNMR 4.1, 4.3
Known OS version compatibility:         n.a.
Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout hsqc3rf_C13dec-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/hsqc3rf_C13dec-v1.0.zip

Read hsqc3rf_C13dec.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/hsqc3rf_C13dec