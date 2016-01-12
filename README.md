# xdec2pul
 xdec2pul - A pulse sequence to perform F19 decouple - 1H and F19-1H NOE
 difference
 experiments on single broadband UNITY spectrometers (fixed frequency
 decoupler).

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

Your name:      Steve Cheatham, Varian
Date submitted: 1992-10-29

File name:      xdec2pul.c
Directory:      psglib
Description:    A pulse sequence to perform F19 decouple - 1H and
                F19-1H NOE difference experiments on single broadband
                UNITY spectrometers (fixed frequency decoupler).

Related files:  manual/xdec2pul, maclib/xdec2pul

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     linear amplifiers
Known software version compatibility:   VnmrS 4.1

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout xdec2pul-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/xdec2pul-v1.0.zip

Read xdec2pul.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/xdec2pul