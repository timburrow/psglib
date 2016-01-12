# SSnoesy
 SSnoesy - noesy pulse sequence with SS read pulse

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

Your name:      Steve Smallcombe, Varian
Date submitted: 1993-03-30
                1994-02-28
                1994-12-01 (fixed file dates)

File name:      SSnoesy
Directory:      psglib
Description:    noesy pulse sequence with SS read pulse

Related files:  bin/makeSS.c    maclib/makeSS   maclib/makeSSpw
                maclib/makeS    maclib/makeSpw  manual/SSnoesy
                parlib/SSnoesy.par      shapelib/SS4758g.RF
                shapelib/S3358g.RF      tablib/SSnoesy

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     requires waveform genertors
Known software version compatibility:   VNMR 4.3
Known OS version compatibility:         
Special instructions for installation:
    If you are downloading from the Internet, store
    the file SSnoesy.tar.Z in /vnmr/userlib/psglib, then use
        cd /vnmr/userlib
        ./extract psglib/SSnoesy /vnmr
        seqgen SSnoesy
    for a "global" installation, for a local installation use

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout SSnoesy-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/SSnoesy-v1.0.zip

Read SSnoesy.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/SSnoesy