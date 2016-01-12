# fhoesy
 fhoesy - F19-detected 2D proton fluorine NOE experiment

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

Your name:      Christine Hofstetter, Agilent

Date submitted: 2001-11-13
                2002-11-29 - r.k.: fixed various problems as reported
                             by Gareth Morris, Manchester University

File name:      fhoesy.c
Directory:      psglib
Description:    F19-detected 2D proton fluorine NOE experiment

Related files:  maclib/fhoesy   manual/fhoesy   parlib/fhoesy.par

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     UNITY INOVA with 1 high band amplifier;
                                        need special filters for broadband dec.
Known software version compatibility:   VNMR 6.1B, VNMR 6.1C
Known OS version compatibility:         n.a.
Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout fhoesy-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/fhoesy-v1.0.zip

Read fhoesy.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/fhoesy