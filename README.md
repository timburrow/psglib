# wnoesy
 wnoesy - a pulse sequence to do noesy using obs.xmtr. for all rf. The basic
 sequence is ..presat..p1.d2.p2.mix.p3..at where all rf is waveform
 generator-based and all rf may be shaped Selective noesy is done by
 making p1 a selective pulse and reducing F1 (the p1 pulse may be a
 "shifted laminar pulse" to effect a 90 degree pulse at a specific
 position away from the transmitter- the shapelib entry listed below
 is one for a 90 degree tophat pulse done 1080 Hz away from tof).

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
Date submitted: 1991-10-07

File name:      wnoesy.c
Directory:      psglib
Description:    a pulse sequence to do noesy using obs.xmtr. for all rf. The
		basic sequence is ..presat..p1.d2.p2.mix.p3..at where all rf
		is waveform generator-based and all rf may be shaped Selective
		noesy is done by making p1 a selective pulse and reducing F1
		(the p1 pulse may be a "shifted laminar pulse" to effect a 90
		degree pulse at a specific position away from the transmitter-
		the shapelib entry listed below is one for a 90 degree tophat
		pulse done 1080 Hz away from tof).

Related files:  maclib/wnoesy, manual/wnoesy, parlib/wnoesy.par,
                shapelib/90top1080.RF

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     Requires linear amplifiers
                                        and waveform generator(1)
Known software version compatibility:   VnmrS 4.1
Known OS version compatibility:         n.a.
Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout wnoesy-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/wnoesy-v1.0.zip

Read wnoesy.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/wnoesy